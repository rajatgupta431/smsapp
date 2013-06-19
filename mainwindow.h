#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QObject>
#include<QtNetwork/QHttp>
#include<QtNetwork/QNetworkCookieJar>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QtNetwork>
#include<QDebug>
#include<QtNetwork/QUrlInfo>
#include<QtNetwork/QNetworkRequest>
#include<QtGui>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QTextItem>
#include<QTextEdit>
#include<QComboBox>


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QNetworkAccessManager *nam;
    QUrl first,second;
    QString url;
    QNetworkRequest req;
    QNetworkReply *reply;
    void replyfinished1(QNetworkReply *rep1);
    void replyfinished2(QNetworkReply *rep2);
    
private slots:


    void on_but_clicked();
    void developer();



private:
    Ui::MainWindow *ui;
};
class mandrill:public QObject
{
    Q_OBJECT
public:
    mandrill(QWidget *parent = 0);
    QNetworkAccessManager *mannam;
    QUrl manfirst,second;
    QString manurl;
    QNetworkRequest manreq;
    QNetworkReply *manreply;
    void replyfinished1(QNetworkReply *rep1);
    void replyfinished2(QNetworkReply *rep2);
};
#endif // MAINWINDOW_H
