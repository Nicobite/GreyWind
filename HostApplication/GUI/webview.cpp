#include "webview.h"
#include "ui_webview.h"

WebView::WebView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WebView)
{
    ui->setupUi(this);
}

WebView::~WebView()
{
    delete ui;
}
