#include <QWebFrame>
#include <QFile>

#include "webview.h"
#include "ui_webview.h"

WebView::WebView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WebView)
{
    ui->setupUi(this);
    ui->widget->show();

    ui->widget->load(QUrl("qrc:/Web/test.html"));
    //ui->widget->load(QUrl("file:///home/nikko/Desktop/three.js2/test.html"));
    //QString testObject = "azeytr";
    //ui->widget->page()->mainFrame()->addToJavaScriptWindowObject("aVerySpecialName", testObject);
}

WebView::~WebView()
{
    delete ui;
}
