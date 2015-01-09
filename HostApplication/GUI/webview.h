#ifndef WEBVIEW_H
#define WEBVIEW_H

#include <QDialog>

namespace Ui {
class WebView;
}

class WebView : public QDialog
{
    Q_OBJECT

public:
    explicit WebView(QWidget *parent = 0);
    ~WebView();

private:
    Ui::WebView *ui;
};

#endif // WEBVIEW_H
