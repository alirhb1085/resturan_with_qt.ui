#include "sidescard.h"
#include "ui_sidescard.h"
#include "customer.h"
#include "sides.h"
#include "classfood.h"
// #include "deskcoust.h"
sidescard::sidescard(QString name,QString price,QString rate,QString im,int  i,bool flag,QListWidget *listWidget,QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::sidescard)
{
    ui->setupUi(this);
    ui->pushButton_5->setVisible(true);
    double ra=rate.toDouble();
    if(ra>=0 && ra<=0.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        ui->label_14->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=0.5 && ra<=1){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=1 && ra<=1.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=1.5 && ra<=2){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=2 && ra<=2.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=2.5 && ra<=3){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=3 && ra<=3.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_17->setVisible(false);
    }
    else if(ra>=3.5 && ra<=4){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->setVisible(false);
    }
    else if(ra>=4 && ra<=4.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->clear();
        ui->label_17->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
    }
    else if(ra>=4.5 && ra<=5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->clear();
        ui->label_17->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
    }
    this->flag=flag;
    this->si=i;
    this->listWidget=listWidget;
    ui->pushButton->setVisible(flag);
    int radius = 20;
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_2->setText(name);
    ui->label_3->setText(price);
    ui->label_4->setText(rate);
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label->setStyleSheet(style);
    ui->label->setScaledContents(true);
}
sidescard::sidescard(QString name,QString price,QString rate,QString im,int co,int  i,bool flag,QWidget *parent )
    : QWidget(parent)
    , ui(new Ui::sidescard)
{
    ui->setupUi(this);
    ui->pushButton_5->setVisible(false);
    double ra=rate.toDouble();
    if(ra>=0 && ra<=0.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
        ui->label_14->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=0.5 && ra<=1){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->setVisible(false);
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=1 && ra<=1.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=1.5 && ra<=2){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->setVisible(false);
        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=2 && ra<=2.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=2.5 && ra<=3){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");

        ui->label_16->setVisible(false);
        ui->label_17->setVisible(false);
    }
    else if(ra>=3 && ra<=3.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");

        ui->label_17->setVisible(false);
    }
    else if(ra>=3.5 && ra<=4){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->setVisible(false);
    }
    else if(ra>=4 && ra<=4.5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->clear();
        ui->label_17->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (4).png);}");
    }
    else if(ra>=4.5 && ra<=5){
        ui->label_12->clear();
        ui->label_12->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_14->clear();
        ui->label_14->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_15->clear();
        ui->label_15->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_16->clear();
        ui->label_16->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
        ui->label_17->clear();
        ui->label_17->setStyleSheet("QLabel {border-image: url(:/new/prefix1/Images/star (5).png);}");
    }
    this->flag=flag;
    this->co=co;
    this->si=i;
    ui->pushButton->setVisible(flag);
    int radius = 20;
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_2->setText(name);
    ui->label_3->setText(price);
    ui->label_4->setText(rate);
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label->setStyleSheet(style);
    ui->label->setScaledContents(true);
}

sidescard::~sidescard()
{
    delete ui;
}

void sidescard::on_pushButton_clicked()
{
    ac[co].order.push_back(classfood(sili[si].name,"",sili[si].image,sili[si].rate,sili[si].price,false));
    emit up();
}


void sidescard::on_pushButton_5_clicked()
{
    listWidget->clear();
    sili.remove(si);
    savesides();
    for(auto i=0u;i<sili.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(listWidget);
        sidescard *card=new sidescard(sili[i].name,sili[i].price,sili[i].rate,sili[i].image,i,false,listWidget,this);
        item->setSizeHint(QSize(252,442));
        listWidget->setItemWidget(item,card);
    }
}

