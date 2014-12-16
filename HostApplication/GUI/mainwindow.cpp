#include "includes.h"
#include "GUI/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Setting up UI
    ui->setupUi(this);
    m_connected = false;
    /* Connecting GUI widgets with QMainWindow instance */
    QObject::connect(ui->connectButton, SIGNAL(clicked()),
                     this,              SLOT(emitConnectButton()));
    QObject::connect(ui->resetPosition, SIGNAL(clicked()),
                     this,              SLOT(emitRstPosButton()));

    // Connect help button
    QObject::connect(ui->helpButton,    SIGNAL(clicked()),
                     this,              SLOT(displayHelp()));


    // Connect the qcombobox with the main window
    QObject::connect(ui->srcSelect, SIGNAL(currentIndexChanged(QString)),
                     this,          SLOT(emitVidSource(QString)));

    // Connect qdoublespinbox
    QObject::connect(ui->framesB4Detect,  SIGNAL(valueChanged(double)),
                       this,              SLOT(emitFramesB4Detect(double)));

    QObject::connect(ui->laserOn,         SIGNAL(stateChanged(int)),
                     this,                SLOT(emitLaserState(int)));
    QObject::connect(ui->getDistance,         SIGNAL(clicked()),
                     this,                SLOT(emitSonarRequest()));
}

MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::dispToCuteConsole(QString message){
    ui->cuteConsole->appendPlainText(message);
}


void MainWindow::keyPressEvent(QKeyEvent* e){
    if(!e->isAutoRepeat()){
        //qDebug() << "Keybutton press:" << e->key() << endl;

        if(m_connected){
            emit pressCmd(e->key());


            switch(e->key())
            {
            case 32:           //SPACE: take off/land
                this->ui->controlTextLabel->setText("Taking off/landing...");
                break;
            case 16777235:     //up arrow: go forward
                this->ui->controlTextLabel->setText("Going forward...");
                break;
            case 16777237:     //down arrow: for backwards
                this->ui->controlTextLabel->setText("Going backwards...");
                break;
            case 16777234:     //left arrow: go left
                this->ui->controlTextLabel->setText("Going left...");
                break;
            case 16777236:     //right arrow: go right
                this->ui->controlTextLabel->setText("Going right...");
                break;
            case 90:     //z button: go up
                this->ui->controlTextLabel->setText("Going up...");
                break;
            case 83:     //s button: go down
                this->ui->controlTextLabel->setText("Going down...");
                break;
            case 81:     //q button: turn left
                this->ui->controlTextLabel->setText("Turning left...");
                break;
            case 68:     //d button: turn right
                this->ui->controlTextLabel->setText("Turning right...");
                break;
            case 70:     //f button: trim magnetometer
                this->ui->controlTextLabel->setText("Resetting magneto...");
                break;
            default:     //unknown button: clear cmd
                this->ui->controlTextLabel->setText("No command.");
                break;
            }
        }
    }

}

void MainWindow::keyReleaseEvent(QKeyEvent* e){
    if(!e->isAutoRepeat()) {
        //qDebug() << "Keybutton release" << endl;

        if(m_connected){
            emit releaseCmd();

            this->ui->controlTextLabel->setText("No command.");

        }
    }
}


void MainWindow::focusInEvent(QFocusEvent* event){
    if(m_connected){
        this->ui->controlGraphicLabel->setPixmap(QPixmap(":/HostApplication/ressources/joystick.png"));
    }
}

void MainWindow::focusOutEvent(QFocusEvent* event){
    this->ui->controlGraphicLabel->setPixmap(QPixmap(":/HostApplication/ressources/joystick_inactive.png"));
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
    //ui->vzLabel->setText(QString::number(nd.vz));
}

void MainWindow::updateLocationView(float x, float y, float z, float psi){
    ui->pxLabel->setText(QString::number(x));
    ui->pyLabel->setText(QString::number(y));
    ui->pzLabel->setText(QString::number(z));
    ui->ppsiLabel->setText(QString::number(psi));
}


void MainWindow::drawDetectedEllipse(Point center, Size size){
    ui->theFrame->pushEllipse(center, size);
}



void MainWindow::updateConnectionStatus(bool status){
    this->ui->connectLabel->setAutoFillBackground(true);
    QPalette pal = ui->connectLabel->palette();
    pal.setColor(QPalette::Window, QColor(Qt::green));
    ui->connectLabel->setPalette(pal);
    ui->connectLabel->setText("OK");

    this->ui->connectButton->setEnabled(false);

    m_connected = true;
    this->ui->controlGraphicLabel->setPixmap(QPixmap(":/HostApplication/ressources/joystick.png"));
    this->ui->controlTextLabel->setText("No command.");
}

void MainWindow::updateSonarView(int distance){
    ui->distanceDisplay->display(distance);
}



/*
 * Private slots
 */
void MainWindow::emitVidSource(const QString& text){
    dispToCuteConsole(
        "[MainWindow] Video feed source changed to "+text+"!"
    );
    if(text == "None"){
        ui->theFrame->resetDrawLabel();
    }
    emit vidSourceChanged(text.toStdString());

}

void MainWindow::emitFramesB4Detect(double fbd){
    dispToCuteConsole(
        "[Detect] Frames before detection changed to "+QString::number(fbd)
    );
    //emit sigDispToCuteConsole(QString::fromStdString("[Detect] Frames before detection changed to ")+QString::number(fbd));
    ui->theFrame->setFrameB4Detect(int(fbd));
    emit detectFrameRateChanged(int(fbd));
}

void MainWindow::emitConnectButton(){
    emit connectButtonClicked();
}

void MainWindow::emitRstPosButton(){
    emit rstPosButtonClicked();
}


void MainWindow::displayHelp(){
    m_helpWindow.show();
}

void MainWindow::emitLaserState(int state){
    if(state==Qt::Unchecked){
        emit laserState(false);
    } else if(state == Qt::Checked){
        emit laserState(true);
    }
}

void MainWindow::emitSonarRequest(){
    emit sonarRequest();
}
