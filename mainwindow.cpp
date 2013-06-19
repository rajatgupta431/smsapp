#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Smsapp");

    ui->checkbox->setChecked(1);
     ui->but->setStyleSheet("*{background-color:rgb(173,    255,	47);color:rgb(0,0,0)}");
     connect(ui->developer,SIGNAL(triggered()),this,SLOT(developer()));
         //ui->but->setEnabled(0);

     QSettings settings("sat");
     QString aValue = settings.value("akey","").toString();
     ui->sender->setText(aValue);


     QString aValu = settings.value("pas","").toString();
     ui->password->setText(aValu);
     QSettings settings1("path");
     // the second argument to value is the default
     // in case there hasn't been set a value in the settings yet
     int index = settings1.value("def/comboBoxIndex", 0).toInt();
     ui->box->setCurrentIndex(index);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_but_clicked()
{


    if(ui->checkbox->isChecked())
    {
        QSettings settings("sat");

    QString someValue=ui->sender->text();

    settings.setValue("akey",someValue);
    }
    else
    {
        QSettings settings("sat");

        QString someValue="";

    settings.setValue("akey",someValue);
    }
    if(ui->checkbox->isChecked())
    {
        QSettings settings1("path");
        settings1.setValue("def/comboBoxIndex", ui->box->currentIndex());
        QSettings settings("sat");

      QString pas=ui->password->text();

      settings.setValue("pas",pas);
    }
    else
    {
        QSettings settings("sat");

          QString pas="";

         settings.setValue("pas",pas);
    }






    if(ui->sender->text()==""||ui->rcvr->text()==""||ui->password->text()=="")
    { ui->check->setText("<font color='red'><b>Fill   All  The Fields!!</b></font>");
        ui->usernamelab->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ui->passlab->setStyleSheet("QLabel { background-color : red; color : blue; }");
        ui->moblab->setStyleSheet("QLabel { background-color : red; color : blue; }");

    }
else{   ui->status->setText("<font color='blue'><b>Please Wait...</b><font>");
        ui->check->setText("");
        ui->usernamelab->setStyleSheet("QLabel { color : blue; }");
        ui->passlab->setStyleSheet("QLabel {  color : blue; }");
        ui->moblab->setStyleSheet("QLabel {  color : blue; }");

    QString message =ui->text->toPlainText();
    QString mnum = ui->sender->text();
     QString snum = ui->rcvr->text();
      QString pass = ui->password->text();
      QString pro;
      //ui->but->setStyleSheet("*{background-color:rgb(118,	238	,0);color:rgb(255,255,255)}");
      if(ui->box->currentText()=="Indyarocks")
          pro="indyarocks";
      else if(ui->box->currentText()=="Fullonsms")
          pro="fullonsms";
      else
          pro="Ultoo";
    QString ur = "http://ubaid.tk/sms/sms.aspx?uid="+mnum+"&pwd="+pass+"&msg="+message+"&phone="+snum+"&provider="+pro;
    first =QUrl(ur);
first.toEncoded();

    QByteArray postData;
    QString query =""; //"username="+mnum+"&password="+pass+"&userLogin=no&button=Login";
   postData.append(query);
   nam = new QNetworkAccessManager(this);
   nam->setCookieJar(new QNetworkCookieJar(this));

   //nam->setCookieJar(new QNetworkCookieJar(this));



   req.setUrl(first);
   //qDebug()<<req.url();

   req.setHeader(QNetworkRequest::ContentTypeHeader,QVariant( "application/x-www-form-urlencoded"));
   reply = nam->post(req, postData);


        QEventLoop loop;
        connect(reply, SIGNAL(finished()),&loop, SLOT(quit()));
        loop.exec();
        replyfinished1(reply);
        qDebug()<<ur;

}


}

void MainWindow::replyfinished1(QNetworkReply *rep1)
{
    ui->but->setText("Send Again");
    QString stat=rep1->readAll();
    if(stat=="1")
        ui->status->setText("<font color='green'><b>Message Sent !!!</b></font>"); //here status is a label
    else if (stat=="-4") {

         ui->status->setText("<font color='red'><b>Login Failed :(</b></font>");
    }
    else if (stat=="-1")
        ui->status->setText("<font color='red'><b>Server Error</b></font>");
    else if (stat=="-2")
        ui->status->setText("<font color='red'><b>Inalid Username</b></font>");
    else if (stat=="-5")
        ui->status->setText("<font color='red'><b>IP Blocked</b></font>");
    else if (stat=="-11")
        ui->status->setText("<font color='red'><b>Unsupported provider</b></font>");





}
void MainWindow::developer()
{


   QWidget *devel = new QWidget;
   QLabel *lab = new QLabel;
  // QLabel *labb = new QLabel;
   //labb->setIndent(50);
   lab->setText("<p><b>Developed By:</b><br><b> RAJAT GUPTA</b><br><b>MIT Manipal</b><br>""<br><b>rajatgupta431@gmail.com</b><br><b><font color=\"white\">www.facebook.com/LUGManipal</font></b></p>");
   //labb->setText("<img src='lug.jpg'>");
   QVBoxLayout lay;
  // lay.addWidget(labb);
   lay.addWidget(lab);
   devel->setLayout(&lay);
   devel->setStyleSheet("*{background-color:rgb(10,125,	200	)}");
   devel->setWindowTitle("LUG Manipal");
   devel->show();

}




