#include "includes.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "videoview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting up UI
    ui->setupUi(this);
    m_connected = false;

    /* Connecting GUI widgets with QMainWindow instance */

    // Connect the qcombobox with the main window
    QObject::connect(ui->srcSelect, SIGNAL(currentIndexChanged(QString)),
                     this,          SLOT(emitVidSource(QString)));
    // Connect qdoublespinbox
    QObject::connect(ui->framesB4Detect,  SIGNAL(valueChanged(double)),
                       this,                SLOT(emitFramesB4Detect(double)));


    // Connect control button
    /*QObject::connect(ui->controlButton, SIGNAL(clicked()),
                     this             , SLOT(displayControl()));
    // Set connect button
    QObject::connect(ui->connectButton, SIGNAL(clicked()),
                     this             , SLOT(connectDrone()));
    */
}

MainWindow::~MainWindow()
{
    m_interface->get_daemon()->kill_daemon(); // TODO Delete this shit ?
    delete m_interface;
    delete ui;
}


void MainWindow::dispToCuteConsole(QString message){
    ui->cuteConsole->appendPlainText(message);
}

/*
 * Public slots
 */

void MainWindow::setFrame(QImage image){
    ui->theFrame->updateView(image);
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

void MainWindow::drawDetectedEllipse(Point center, Size size){
    ui->theFrame->pushEllipse(center, size);
}


/*
 * Private slots
 */
void MainWindow::emitVidSource(const QString& text){
    dispToCuteConsole(
        "[MainWindow] Video feed source changed to "+text+"!"
    );
    emit vidSourceChanged(text.toStdString());

}

void MainWindow::emitFramesB4Detect(double fbd){
    dispToCuteConsole(
        "[Detect] Frames before detection changed to "+QString::number(fbd)
    );
    //emit sigDispToCuteConsole(QString::fromStdString("[Detect] Frames before detection changed to ")+QString::number(fbd));
    emit detectFrameRateChanged(int(fbd));
}

/*



void MainWindow::displayControl(){
    m_controlWindow.show();
}

void MainWindow::connectDrone(){ // TODO 1. Delete this shit but create new signals/slots OR 2. pass interface as argument... 2. is bad.
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
*/
