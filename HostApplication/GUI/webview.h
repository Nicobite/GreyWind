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

signals:
    /*
     * f    face        rose
     * p    pyramid     cyan
     * b    banana      yellow
     */
    void objToJS(QString type, int x, int y, int z);

public slots:
    void updateView();
    void reloadPage();

};
#endif // WEBVIEW_H
