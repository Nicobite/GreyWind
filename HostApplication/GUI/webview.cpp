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
    //ui->widget->load(QUrl("file:///home/nikko/Desktop/three.js2/test.html")); // OLD
    ui->widget->page()->mainFrame()->addToJavaScriptWindowObject("cppCom", this);

}

WebView::~WebView()
{
    delete ui;
}

void WebView::updateView(){
    emit objToJS("f",100,100,100);
    DEBUG("After WebView emit");
}

void WebView::reloadPage(){
    ui->widget->reload();
}
