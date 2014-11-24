#include "includes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoview.h"

MainWindow::MainWindow(int childPID, char *childSemFD, int childPipeWrFD, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting up UI
    ui->setupUi(this);

    m_connected = false;
    m_interface = new DroneInterface(childPID, childSemFD, childPipeWrFD);

    // Connect the qcombobox with the main window
    QObject::connect(ui->srcSelect  , SIGNAL(   currentIndexChanged(int)        ),
                     this           , SLOT  (   getSrc())                       );

    // Connect qdoublespinbox
    QObject::connect(ui->framesB4Detect , SIGNAL(   valueChanged(double)                ),
                     this               , SLOT  (   getFramesB4Detect(double))          );
    QObject::connect(this               , SIGNAL(   sigDispToCuteConsole(QString)       ),
                     ui->cuteConsole    , SLOT  (   appendPlainText(QString))           );


    // Connect control button
    QObject::connect(ui->controlButton, SIGNAL(clicked()),
                     this             , SLOT(displayControl()));

    // Coloring the video frame for style points
    ui->theFrame->setAutoFillBackground(true);
    QPalette pal = ui->theFrame->palette();
    pal.setColor(QPalette::Window, QColor(Qt::black));
    ui->theFrame->setPalette(pal);

    //Set connect button
    QObject::connect(ui->connectButton, SIGNAL(clicked()),
                     this             , SLOT(connectDrone()));


#if !NBM
    // Connecting main window and thread
    // * updating video on main widget
    QObject::connect(&m_thread1   , SIGNAL(   displayedFrame(QImage)          ),
                     this         , SLOT  (   getFrame(QImage))               );
    // * requesting source update
    QObject::connect(&m_thread1   , SIGNAL(   sigReqSrc()                     ),
                     this         , SLOT  (   getSrc())                       );
    // * sending back new source
    QObject::connect(this         , SIGNAL(   sigResponsesSrc(std::string)    ),
                     &m_thread1   , SLOT  (   updateSrc(std::string))         );

    this->show();

    // Starting up the threads
    m_thread1.start();

#endif;
}

MainWindow::~MainWindow()
{
    m_interface->get_daemon()->kill_daemon();
    delete m_interface;
    delete ui;
}

void MainWindow::getFrame(QImage image){
    ui->theFrame->updateView(image);
}

void MainWindow::getSrc(){
    if(this->m_connected){
        emit sigResponsesSrc(ui->srcSelect->currentText().toStdString());
        //DEBUG("MainWindow: sigResponsesSrc");
#if DBG
        printf("\t->(%s)\n",ui->srcSelect->currentText().toStdString().c_str());
#endif
    }else{
        ui->srcSelect->setCurrentIndex(0);
        emit sigDispToCuteConsole("Cannot change to TCP source if drone is not connected!");
    }
}

void MainWindow::getFramesB4Detect(double fbd){
    //DEBUG("MainWindow: sigResponsesSrc");
    framesB4Detect = (int)fbd;
    emit sigDispToCuteConsole(QString::fromStdString("[Detect] Frames before detection changed to ")+QString::number(fbd));
}

void MainWindow::updateNavdataView(navdata_t nd){
    ui->controlStateLabel->setText(std::string(nd.ctrl_state).c_str());
    ui->batteryLabel->setText(QString::number(nd.vbat));
    ui->altitudeLabel->setText(QString::number(nd.altitude));
    ui->pitchLabel->setText(QString::number(nd.pitch));
    ui->rollLabel->setText(QString::number(nd.roll));
    ui->yawLabel->setText(QString::number(nd.yaw));
    ui->vxLabel->setText(QString::number(nd.vx));
    ui->vyLabel->setText(QString::number(nd.vy));
    ui->vzLabel->setText(QString::number(nd.vz));
}


void MainWindow::displayControl(){
    m_controlWindow.show();
}

void MainWindow::connectDrone(){
    //Connect to the daemon
    m_interface->get_daemon()->connect_daemon();
    if(m_interface->get_daemon()->is_drone_available())
    {
        m_interface->get_daemon()->launch_navdata_handler();
        m_interface->get_daemon()->launch_control_handler();
        m_connected = true;

        this->ui->connectLabel->setAutoFillBackground(true);
        QPalette pal = ui->connectLabel->palette();
        pal.setColor(QPalette::Window, QColor(Qt::green));
        ui->connectLabel->setPalette(pal);
        ui->connectLabel->setText("OK");

        this->ui->controlButton->setEnabled(true);
        this->ui->connectButton->setEnabled(false);


        //Set navdata
        QObject::connect(this->m_interface->get_daemon()->get_navdata_thread(), SIGNAL(sendCurrentND(navdata_t)),
                         this                                                , SLOT(updateNavdataView(navdata_t)));

        if(m_interface->get_daemon()->is_control_running())
        {
            QObject::connect(&this->m_controlWindow                               , SIGNAL(pressCmd(int)),
                             this->m_interface->get_daemon()->get_control_thread(), SLOT(key_press_cmd(int)));

            QObject::connect(&this->m_controlWindow                               , SIGNAL(releaseCmd()),
                             this->m_interface->get_daemon()->get_control_thread(), SLOT(key_release_cmd()));
        }
    }
}
