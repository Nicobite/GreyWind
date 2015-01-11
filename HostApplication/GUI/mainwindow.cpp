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

    // Connect help detect button
    QObject::connect(ui->helpButton_2,    SIGNAL(clicked()),
                     this,              SLOT(displayHelpDetect()));

    // Connect 3D button
    QObject::connect(ui->threeDButton,  SIGNAL(clicked()),
                     this,              SLOT(display3D()));

    //Conect object selection button
    QObject::connect(ui->objOkButton,  SIGNAL(clicked()),
                     this,             SLOT(emitObjectChoice()));


    // Connect the qcombobox with the main window
    QObject::connect(ui->srcSelect, SIGNAL(currentIndexChanged(QString)),
                     this,          SLOT(emitVidSource(QString)));


    QObject::connect(ui->algSelect, SIGNAL(currentIndexChanged(QString)),
                     this,          SLOT(emitAlgoChoice(QString)));

    // Connect qdoublespinbox
    QObject::connect(ui->framesB4Detect,  SIGNAL(valueChanged(double)),
                       this,              SLOT(emitFramesB4Detect(double)));

    QObject::connect(ui->laserOn,         SIGNAL(stateChanged(int)),
                     this,                SLOT(emitLaserState(int)));
    QObject::connect(ui->getDistance,         SIGNAL(clicked()),
                     this,                SLOT(emitSonarRequest()));

    // Connect detection button
    QObject::connect(ui->detectButton,    SIGNAL(clicked()),
                     this,              SLOT(displayDetection()));
    // Connect clear button
    QObject::connect(ui->clearButton,    SIGNAL(clicked()),
                     this,              SLOT(clearBlackList()));

    // Connect valid button and it action
    QObject::connect(&m_detectionWindow,    SIGNAL(sendValidDetection()),
                     this,              SLOT(validDetection()));
    // Connect blackList button and it action
    QObject::connect(&m_detectionWindow,    SIGNAL(sendAddToBlackListDetection()),
                     this,              SLOT(addToBlackListDetection()));
    QObject::connect(&m_detectionWindow,    SIGNAL(sendSkip1Detection()),
                     this,                  SLOT(skip1Detection()));
    QObject::connect(&m_detectionWindow,    SIGNAL(sendSkip5Detection()),
                     this,                  SLOT(skip5Detections()));
    QObject::connect(&m_detectionWindow,    SIGNAL(sendSkip10Detection()),
                     this,                  SLOT(skip10Detections()));
    //Tracker
    QObject::connect(ui->trackAlgSelect, SIGNAL(currentIndexChanged(QString)),
                     this,               SLOT(emitTrackerChoice(QString)));
    QObject::connect(ui->trackButton, SIGNAL(clicked()),
                     this,            SLOT(emitTrackerInit()));


    m_haltDetection = false;
    m_skipValue = 0;



    QObject::connect(ui->savePicButton, SIGNAL(clicked()),
                     this,              SLOT(emitTakePicture()));


    m_3DWindow.drawPyramid();

    /*################*/
    /* Mission Window */
    /*################*/
    QObject::connect(ui->addAlgoObject, SIGNAL(clicked()),
                     this,              SLOT(addAlgoObject()));
    QObject::connect(ui->subAlgoObject, SIGNAL(clicked()),
                     this,              SLOT(subAlgoObject()));
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

    // Draw the ellipse
    if(!m_haltDetection || m_skipValue>0){
        // Save the values of the center et the size of the ellipse
        m_center=center;
        m_size=size;

        ui->theFrame->pushShape(center, size, CyanEllipse, m_objectName);

        if(m_skipValue > 0){
            m_skipValue --;
            if(m_skipValue == 0){
                // Save the values of the center and the size that we detect
                m_center_detected=m_center;
                m_size_detected=m_size;

                // Draw the ellipse of detection validation with the last values of center and size
                ui->theFrame->pushShape(m_center_detected, m_size_detected, RedEllipse, m_objectName);

                //enable buttons
                m_detectionWindow.enable(true);
                this->ui->theFrame->setHaltDraw(true);
            }
        }
    }
}

void MainWindow::drawTrackedRect(Point center, Size size){
    // Draw the ellipse
    ui->theFrame->pushShape(center, size, CyanSquare, m_objectName);
}

void MainWindow::drawLaserDot(Point center, Size size){
    // Draw the ellipse
    ui->theFrame->pushShape(center, size, RedSquare, "laser");
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

void MainWindow::updateTrackState(std::string state){
    ui->trackState->setText(QString::fromStdString(state));
}

/*
 * Private slots
 */
void MainWindow::emitVidSource(const QString& text){
    dispToCuteConsole(
        "[MainWindow] Video feed source is changed to "+text+"!"
    );
    if(text == "None"){
        ui->theFrame->resetDrawLabel();
    }
    emit vidSourceChanged(text.toStdString());

}

void MainWindow::emitAlgoChoice(const QString& text){
    dispToCuteConsole(
        "[MainWindow] Detection algorithm is changed to "+text+"!"
    );
    ui->theFrame->resetDrawLabel();
    if(text == "<none>"){
        dispToCuteConsole(
            "[MainWindow] No detection algorithm is selected!"
        );
    }
    emit detectAlgoChanged(text.toStdString());
}


void MainWindow::emitObjectChoice(){
    this->ui->theFrame->setObjname(this->ui->objSource->text().toStdString());
    m_objectName = this->ui->objSource->text().toStdString();
    dispToCuteConsole(
        "[MainWindow] Attempting to change the object to detect to "+this->ui->objSource->text()+"!"
    );
    ui->theFrame->resetDrawLabel();
    if(this->ui->objSource->text() == ""){
        dispToCuteConsole(
            "[MainWindow] No object is to be detected!"
        );
    }
    emit detectObjectChanged(this->ui->objSource->text().toStdString());
}


void MainWindow::emitTrackerChoice(const QString& text){
    dispToCuteConsole(
        "[MainWindow] Tracking algorithm is changed to "+text+"!"
    );
    ui->theFrame->resetDrawLabel();
    if(text == "<none>"){
        dispToCuteConsole(
            "[MainWindow] No tracking algorithm is selected!"
        );
    }
    emit detectTrackerChanged(text.toStdString());
}

void MainWindow::emitTrackerInit(){
    emit initialiseTracker();
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


void MainWindow::displayHelpDetect(){
    m_helpDetectWindow.show();
}


void MainWindow::display3D(){
    m_3DWindow.show();
}

void MainWindow::displayDetection(){

    //Detection window with Valid and BlackList appears
    m_detectionWindow.show();
    m_detectionWindow.move(530,430);

    // Stop the different detections
    //emit sendStopDrawingEllipse();

    // Save the values of the center and the size that we detect
    m_center_detected=m_center;
    m_size_detected=m_size;

    // Draw the ellipse of detection validation with the last values of center and size
    ui->theFrame->pushShape(m_center_detected, m_size_detected, RedEllipse, m_objectName);
    DEBUG("--> pushing red circle");

    m_haltDetection = true;
    this->ui->theFrame->setHaltDraw(true);

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

void MainWindow::validDetection(){

    // Change the color of the pen
    ui->theFrame->pushShape(m_center_detected, m_size_detected, GreenEllipse, m_objectName);
    DEBUG("--> pushing green circle");

    // detection window disappears
    m_detectionWindow.close();

    // Change the icon in the mainWindow
    QPixmap pm (":/HostApplication/ressources/tick_octagon.png");
    ui->objectDetectedIconlabel->setPixmap(pm);

    // Add information about the location of the detected object
    // Now static but later with the tracking will be dynamic
    ui->objectDetectedLocationgroupBox->setEnabled(true);
    ui->xCenterlabel->setNum(m_center_detected.x);
    ui->yCenterlabel->setNum(m_center_detected.y);
    ui->radiuslabel->setNum(m_size_detected.width);
    emit sigValidatedObject(m_center_detected, m_size_detected);

    ui->detectButton->setEnabled(false);
    ui->trackButton->setEnabled(true);
}

void MainWindow::skip1Detection(){
    m_detectionWindow.enable(false);
    this->ui->theFrame->setHaltDraw(false);
    m_skipValue = 1;
}

void MainWindow::skip5Detections(){
    m_detectionWindow.enable(false);
    this->ui->theFrame->setHaltDraw(false);
    m_skipValue = 5;
}

void MainWindow::skip10Detections(){
    m_detectionWindow.enable(false);
    this->ui->theFrame->setHaltDraw(false);
    m_skipValue = 10;
}

void MainWindow::addToBlackListDetection(){

    // Change the color of the pen
    ui->theFrame->pushShape(m_center_detected, m_size_detected, BlackEllipse, m_objectName);

    // detection window do not disappear
    m_detectionWindow.close();

    // next ellipse will appear in cyan as normal
    m_haltDetection = false;
    this->ui->theFrame->setHaltDraw(false);

    // Change the icon in the mainWindow
    QPixmap pm (":/HostApplication/ressources/Icon-16x16-not_ok.png");
    ui->objectDetectedIconlabel->setPixmap(pm);

    //Disable the groupbox
    ui->objectDetectedLocationgroupBox->setEnabled(false);

    //Add the bad detected point to the blackList in the control class
    emit sendObjectToBlackList(m_center_detected,m_size_detected);



}

void MainWindow::clearBlackList()
{
    emit sendClearBlackList();
    m_haltDetection = false;
    this->ui->theFrame->setHaltDraw(false);
    ui->objectDetectedLocationgroupBox->setEnabled(false);
    ui->detectButton->setEnabled(true);
    ui->trackButton->setEnabled(false);
}

void MainWindow::updateSizeBlackList(int size)
{
    // Update the size of the BlackList
    ui->sizeBlackListlabel->setNum(size);
}


/*################*/
/* Mission Window */
/*################*/

void MainWindow::addAlgoObject(){
    if (ui->listWidget->count() == 0){
        ui->listWidget->addItem(QString("**Algo****||****Objet****"));
    }
    QString algo_chosen = ui->algSelect_2->currentText();
    if(algo_chosen == "<none>"){
        this->dispToCuteConsole("[Mission] No algorithm is actived. Nothing to do");
    }else if (ui->objSource_2->text().isEmpty()){
            this->dispToCuteConsole("[Mission] No object is selected. Nothing to do");
    }
    else{
        ui->listWidget->addItem(QString("**")+algo_chosen+QString("****||****")+ui->objSource_2->text());
    }
}

void MainWindow::subAlgoObject(){
    if (ui->listWidget->count() == 0){
        this->dispToCuteConsole("[Mission] No mission selected.");
    }else{
        ui->listWidget->currentItem()->setBackgroundColor(Qt::blue);
        ui->listWidget->takeItem(ui->listWidget->currentRow());
    }
}

void MainWindow::emitTakePicture(){
    emit sigTakePicture();
}
