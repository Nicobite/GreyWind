#include <QWebFrame>
#include <QFile>

#include "includes.h"
#include "webview.h"
#include "ui_webview.h"

WebView::WebView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WebView)
{
    ui->setupUi(this);
    ui->widget->show();

    ui->widget->load(QUrl("qrc:/Web/test.html"));
    //ui->widget->settings()->setObjectCacheCapacities(0,0,0);
    //ui->widget->load(QUrl("file:///home/nikko/Desktop/three.js2/test.html")); // OLD
    ui->widget->page()->mainFrame()->addToJavaScriptWindowObject("cppCom", this);


}

WebView::~WebView(){
    delete ui;
}

void WebView::updateView(){
    emit objToJS("b",100,100,0);
}

void WebView::addObjToView(QString type, int x, int y, int z){
    //TODO un switch ou alors modifier l'autre
    emit objToJS(type,x,y,z);
}


/**
 * @brief WebView::reloadPage
 * Actually doesn't reload the page. Destroys the UI then recreates it. For some reason, a standard reload also causes the JS to go in error state.
 */
void WebView::reloadPage(){
    //ui->widget->reload(); //TODO This puts the JS in an error state for some reason
    delete ui;
    ui->setupUi(this);
    ui->widget->show();
    ui->widget->load(QUrl("qrc:/Web/test.html"));
    ui->widget->page()->mainFrame()->addToJavaScriptWindowObject("cppCom", this);//*/
}
