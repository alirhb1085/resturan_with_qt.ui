#include "cardfood.h"
#include "ui_cardfood.h"
#include "customer.h"
#include <QTimer>
#include <QWidgetList>
#include "mangelog.h"

cardfood::cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int i,QListWidget *listWidget,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardfood)
{
    ui->setupUi(this);
    this->gh=i;
    this->listWidget=listWidget;
    ui->pushButton_5->setVisible(true);
    ui->lineEdit->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    double ra=rate.toDouble();
    if(ra>=0 && ra<=0.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=0.5 && ra<=1){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1 && ra<=1.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1.5 && ra<=2){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2 && ra<=2.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2.5 && ra<=3){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=3 && ra<=3.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_12->setVisible(false);
    }
    else if(ra>=3.5 && ra<=4){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->setVisible(false);
    }
    else if(ra>=4 && ra<=4.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
    }
    else if(ra>=4.5 && ra<=5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
    }
    ui->pushButton->setVisible(false);
    ui->pushButton_4->setVisible(true);
    ui->pushButton_2->setVisible(false);
    this->foodname=nam;
    ui->label->clear();
    ui->label_2->clear();
    ui->label_4->clear();
    ui->label_6->clear();
    ui->label_8->clear();
    ui->label_2->setText(nam);
    ui->label_6->setText(price);
    ui->label_4->setText(mtn);
    ui->label_8->setText(rate);
    int radius = 20;
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label->setStyleSheet(style);
    ui->label->setScaledContents(true);

}

cardfood::cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int cou,int i,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardfood)
{
    ui->setupUi(this);
    ui->pushButton_5->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    myFlag=false;

    this->gh=i;
    this->co=cou;
    if(myFlag==false){
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart.png);}");
    }
    else{
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart (1).png);}");
    }
    double ra=rate.toDouble();
    if(ra>=0 && ra<=0.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=0.5 && ra<=1){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1 && ra<=1.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1.5 && ra<=2){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2 && ra<=2.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2.5 && ra<=3){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=3 && ra<=3.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_12->setVisible(false);
    }
    else if(ra>=3.5 && ra<=4){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->setVisible(false);
    }
    else if(ra>=4 && ra<=4.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
    }
    else if(ra>=4.5 && ra<=5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
    }
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
    ui->label->clear();
    ui->label_2->clear();
    ui->label_4->clear();
    ui->label_6->clear();
    ui->label_8->clear();
    ui->label_2->setText(nam);
    ui->label_6->setText(price);
    ui->label_4->setText(mtn);
    ui->label_8->setText(rate);
    int radius = 20;
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label->setStyleSheet(style);
    ui->label->setScaledContents(true);
}
cardfood::cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int cou,int i,bool flag,QWidget *parent): QWidget(parent)
    , ui(new Ui::cardfood)
{
    ui->setupUi(this);
    ui->pushButton_5->setVisible(false);
    ui->lineEdit->setVisible(false);
    ui->pushButton_4->setVisible(false);
    ui->lineEdit_2->setVisible(false);
    ui->lineEdit_3->setVisible(false);
    this->gh=i;
    this->co=cou;
    myFlag=flag;
    if(myFlag==false){
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart.png);}");
    }
    else{
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart (1).png);}");
    }
    double ra=rate.toDouble();
    if(ra>=0 && ra<=0.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=0.5 && ra<=1){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1 && ra<=1.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=1.5 && ra<=2){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2 && ra<=2.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=2.5 && ra<=3){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
    }
    else if(ra>=3 && ra<=3.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_12->setVisible(false);
    }
    else if(ra>=3.5 && ra<=4){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->setVisible(false);
    }
    else if(ra>=4 && ra<=4.5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
    }
    else if(ra>=4.5 && ra<=5){
        ui->label_7->clear();
        ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_9->clear();
        ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_10->clear();
        ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_11->clear();
        ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
    }
    ui->pushButton->setVisible(true);
    ui->pushButton_2->setVisible(true);
    ui->label->clear();
    ui->label_2->clear();
    ui->label_4->clear();
    ui->label_6->clear();
    ui->label_8->clear();
    ui->label_2->setText(nam);
    ui->label_6->setText(price);
    ui->label_4->setText(mtn);
    ui->label_8->setText(rate);
    int radius = 20;
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label->setStyleSheet(style);
    ui->label->setScaledContents(true);
}
cardfood::~cardfood()
{
    delete ui;
}

void cardfood::on_pushButton_2_clicked(){
    myFlag=!myFlag;
    if(myFlag==false){
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart.png);}");
        auto &vec=ac[co].favar;
        auto target=lifo[gh];
        for(auto i=0u;i<vec.size();){
            if(vec[i].name==target.name){
                vec.erase(vec.begin()+i);
                break;
            }
            else{
                i++;
            }
        }

    }
    else{
        ui->pushButton_2->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/Images/heart (1).png);}");
        (ac[co].favar).push_back(lifo[gh]);
        savecustomertofile();
    }
}
QString cardfood::getFoodName()const{
    return this->foodname;
}

void cardfood::on_pushButton_clicked(){
    (ac[co].order).push_back(lifo[gh]);
    savecustomertofile();
}
QPushButton* cardfood::getbutton(){
    return ui->pushButton;
}
void cardfood::on_pushButton_3_clicked()
{
    if(flag){
        ui->label_7->setVisible(false);
        ui->label_9->setVisible(false);
        ui->label_10->setVisible(false);
        ui->label_11->setVisible(false);
        ui->label_12->setVisible(false);
        ui->label_8->clear();
        ui->label_8->setVisible(false);
        ui->lineEdit->clear();
        ui->lineEdit->setVisible(true);
        flag=false;
    }
    else{
        ui->label_8->setVisible(true);
        ui->lineEdit->setVisible(false);
        double ga=(ui->lineEdit->text()).toDouble();
        double al=((lifo[gh].rate).toDouble())+(ga);
        lifo[gh].rate=QString::number((al)/2);
        ui->label_8->setText((lifo[gh].rate));
        double ra=(lifo[gh].rate).toDouble();
        ui->label_7->setVisible(true);
        ui->label_9->setVisible(true);
        ui->label_10->setVisible(true);
        ui->label_11->setVisible(true);
        ui->label_12->setVisible(true);
        if(ra>=0 && ra<=0.5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
            ui->label_9->setVisible(false);
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=0.5 && ra<=1){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->setVisible(false);
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=1 && ra<=1.5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=1.5 && ra<=2){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->setVisible(false);
            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=2 && ra<=2.5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=2.5 && ra<=3){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

            ui->label_11->setVisible(false);
            ui->label_12->setVisible(false);
        }
        else if(ra>=3 && ra<=3.5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_11->clear();
            ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

            ui->label_12->setVisible(false);
        }
        else if(ra>=3.5 && ra<=4){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_11->clear();
            ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_12->setVisible(false);
        }
        else if(ra>=4 && ra<=4.5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_11->clear();
            ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_12->clear();
            ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        }
        else if(ra>=4.5 && ra<=5){
            ui->label_7->clear();
            ui->label_7->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_9->clear();
            ui->label_9->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_10->clear();
            ui->label_10->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_11->clear();
            ui->label_11->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
            ui->label_12->clear();
            ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        }
        savefood();
        flag=true;
    }
}


void cardfood::on_pushButton_4_clicked()
{
    if(flaged){
        ui->label_4->setVisible(false);
        ui->label_6->setVisible(false);
        ui->lineEdit_2->setVisible(true);
        ui->lineEdit_3->setVisible(true);
        ui->lineEdit_3->clear();
        ui->lineEdit_2->clear();
        flaged=false;
    }
    else{
        ui->lineEdit_2->setVisible(false);
        ui->lineEdit_3->setVisible(false);
        if((ui->lineEdit_3->text().isEmpty()) && (ui->lineEdit_2->text().isEmpty())){
            ui->label_4->setVisible(true);
            ui->label_6->setVisible(true);
        }
        else if((ui->lineEdit_3->text().isEmpty()) && (ui->lineEdit_2->text().isEmpty()!=true)){
            ui->label_6->setVisible(true);
            QString mt=ui->lineEdit_2->text();
            ui->label_4->setText(mt);
            lifo[gh].mtn=mt;
            ui->label_4->setVisible(true);
        }
        else if((ui->lineEdit_3->text().isEmpty()!=true) && (ui->lineEdit_2->text().isEmpty())){
            ui->label_4->setVisible(true);
            QString pr=ui->lineEdit_3->text();
            ui->label_6->setText(pr);
            lifo[gh].price=pr;
            ui->label_6->setVisible(true);
        }
        else if((ui->lineEdit_3->text().isEmpty()!=true) && (ui->lineEdit_2->text().isEmpty()!=true)){
            QString mt=ui->lineEdit_2->text();
            QString pr=ui->lineEdit_3->text();
            ui->label_6->setText(pr);
            ui->label_4->setText(mt);
            lifo[gh].price=pr;
            lifo[gh].mtn=mt;
            ui->label_6->setVisible(true);
            ui->label_4->setVisible(true);
        }
        savefood();
        flaged=true;
    }
}


void cardfood::on_pushButton_5_clicked()

{
    lifo.remove(gh);
    savefood();
    listWidget->clear();
    for(auto i=0u;i<lifo.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(listWidget);
        cardfood *card=new cardfood(lifo[i].image,lifo[i].name,lifo[i].price,lifo[i].rate,lifo[i].mtn,i,listWidget);
        item->setSizeHint(QSize(700, 274));
        listWidget->setItemWidget(item,card);
    }
}

