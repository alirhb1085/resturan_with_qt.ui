#include "mangelog.h"
#include "ui_mangelog.h"
#include "cutomcard.h"
#include "customer.h"
#include "manger.h"
#include "classfood.h"
#include "cardfood.h"
#include <QFileDialog>
#include <QPixmap>
#include "mainwindow.h"
#include "mangelog.h"
#include "mangercard.h"
#include "sides.h"
#include "sidescard.h"
#include <QButtonGroup>
static bool flagsf=false;
static bool flagsS=false;
QString imafo;
QString side;
mangelog::mangelog(bool flag,manger p2,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mangelog),p1(p2)
{
    ui->setupUi(this);
    QButtonGroup *bu=new QButtonGroup(this);
    bu->addButton(ui->pushButton);
    bu->addButton(ui->pushButton_2);
    bu->addButton(ui->pushButton_3);
    bu->setExclusive(true);
    ui->lineEdit_10->setText(p1.name);
    ui->lineEdit_9->setText(p1.pass);
    ui->lineEdit_11->setText(p1.id);
    ui->frame_11->setVisible(flag);
    if(flag){
        ui->label->setText(p1.name);
        ui->stackedWidget->setCurrentIndex(0);
        ui->frame->setVisible(flagsf);
        ui->frame_6->setVisible(flagsS);
        connect(ui->pushButton_2,&QPushButton::clicked,this,&mangelog::cou);
        connect(ui->pushButton_4,&QPushButton::clicked,this,&mangelog::on_pushButton_4_clicked);
        connect(ui->pushButton_5,&QPushButton::clicked,this,&mangelog::on_pushButton_5_clicked);
        connect(ui->pushButton_8,&QPushButton::clicked,this,&mangelog::logout);
    }
    else{
        ui->label->setText(p1.name);
        ui->stackedWidget->setCurrentIndex(0);
        ui->frame->setVisible(flagsf);
        ui->frame_6->setVisible(flagsS);
        connect(ui->pushButton_2,&QPushButton::clicked,this,&mangelog::cou);
        connect(ui->pushButton_4,&QPushButton::clicked,this,&mangelog::on_pushButton_4_clicked);
        connect(ui->pushButton_5,&QPushButton::clicked,this,&mangelog::on_pushButton_5_clicked);
        connect(ui->pushButton_8,&QPushButton::clicked,this,&mangelog::logout);
    }
}

mangelog::~mangelog()
{
    delete ui;
}

void mangelog::cou(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->listWidget->clear();
    ui->listWidget->setSpacing(8);
    for(auto i=0u;i<ac.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget);
        cutomcard *card=new cutomcard(ac[i].name,ac[i].addrese,ac[i].id,(ac[i]).logview,ui->listWidget_2,i,this);
        item->setSizeHint(QSize(700,217));
        ui->listWidget->setItemWidget(item,card);
    }
}

void mangelog::on_pushButton_4_clicked(){
    flagsf=true;
    ui->frame->setVisible(flagsf);
}

void mangelog::on_pushButton_5_clicked(){


    QMenu menu(this);
    QAction *action1 = menu.addAction(QIcon(":/new/prefix1/Images/claudio-schwarz-4qJlXK4mYzU-unsplash.jpg"), tr("CHIKEN IMAGE"));
    QAction *action2 = menu.addAction(QIcon(":/new/prefix1/Images/ivan-torres-MQUqbmszGGM-unsplash.jpg"), tr("PIZZA IMAGE"));
    QAction *action3 = menu.addAction(QIcon(":/new/prefix1/Images/maryam-jahanmehr-7nC7_1oxbJI-unsplash.jpg"), tr("Kababe"));
    QAction *action4 = menu.addAction(QIcon(":/new/prefix1/Images/dad-hotel-5Bof9geg6YQ-unsplash.jpg"), tr("zaerchek"));


    QAction *selectedAction = menu.exec(ui->pushButton_5->mapToGlobal(QPoint(0, ui->pushButton_5->height())));

    if (selectedAction) {
        QString im;
        if (selectedAction == action1) {
            im = ":/new/prefix1/Images/claudio-schwarz-4qJlXK4mYzU-unsplash.jpg";
        }
        else if (selectedAction == action2) {
            im = ":/new/prefix1/Images/ivan-torres-MQUqbmszGGM-unsplash.jpg";
        }
        else if (selectedAction == action3) {
            im = ":/new/prefix1/Images/maryam-jahanmehr-7nC7_1oxbJI-unsplash.jpg";
        }
        else if (selectedAction == action4) {
            im = ":/new/prefix1/Images/dad-hotel-5Bof9geg6YQ-unsplash.jpg";
        }

        imafo = im;
        int radius = 20;
        QString style = QString(
                            "background: transparent;"
                            "border-image: url(%1);"
                            "border-radius: %2px;"
                            ).arg(im).arg(radius);

        ui->label_6->setStyleSheet(style);
    }
}

void mangelog::on_pushButton_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
    ui->listWidget_3->setSpacing(3);
    ui->listWidget_3->clear();
    for(auto i=0u;i<lifo.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_3);
        cardfood *card=new cardfood(lifo[i].image,lifo[i].name,lifo[i].price,lifo[i].rate,lifo[i].mtn,i,(ui->listWidget_3),this);
        item->setSizeHint(QSize(700, 274));
        ui->listWidget_3->setItemWidget(item,card);
    }

}



void mangelog::on_pushButton_6_clicked(){
    QString name=ui->lineEdit->text();
    QString rate=ui->lineEdit_2->text();
    QString mat=ui->lineEdit_3->text();
    QString price=ui->lineEdit_4->text();
    classfood p1(name,mat,imafo,rate,price);
    savefood();
    flagsf=false;
    ui->frame->setVisible(flagsf);
    ui->label_6->clear();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    imafo.clear();
    ui->listWidget_3->setSpacing(3);
    ui->listWidget_3->clear();
    for(auto i=0u;i<lifo.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_3);
        cardfood *card=new cardfood(lifo[i].image,lifo[i].name,lifo[i].price,lifo[i].rate,lifo[i].mtn,i,(ui->listWidget_3),this);

        item->setSizeHint(QSize(700, 274));
        ui->listWidget_3->setItemWidget(item,card);
    }
}
void mangelog::logout()
{
    MainWindow *pagelog=new MainWindow();
    pagelog->show();
    this->hide();
}

void mangelog::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void mangelog::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->label_15->clear();
}


void mangelog::on_pushButton_9_clicked()
{
    QString name=ui->lineEdit_5->text();
    QString id=ui->lineEdit_6->text();
    QString pass=ui->lineEdit_8->text();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    manger p2(name,pass,id);
    savemanger();
    QString jom=" add successful";
    ui->label_15->setText(name+jom);
}



void mangelog::refreshList()
{
    ui->list5->clear();
    ui->list5->setSpacing(5);

    if(mangerl.size() > 1) {
        for(auto i = 1u; i < mangerl.size(); i += 1) {
            QListWidgetItem *item = new QListWidgetItem(ui->list5);
            mangercard *card = new mangercard(mangerl[i].name, mangerl[i].pass, mangerl[i].id, i, this);
            item->setSizeHint(QSize(700, 217));
            ui->list5->setItemWidget(item, card);
            connect(card, &mangercard::carddel, this, &mangelog::refreshList);
        }
    }
}


void mangelog::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    refreshList();
}


void mangelog::on_pushButton_7_clicked()
{
    if(!isedit1){
        isedit1=true;
        ui->lineEdit_10->setReadOnly(false);
    }
    else{
        isedit1=false;
        ui->lineEdit_10->setReadOnly(true);
        p1.name=ui->lineEdit_10->text();
        ui->label->clear();
        ui->label->setText(ui->lineEdit_10->text());
    }
}


void mangelog::on_pushButton_14_clicked()
{
    if(!isedit2){
        isedit2=true;
        ui->lineEdit_9->setReadOnly(false);
    }
    else{
        isedit2=false;
        ui->lineEdit_9->setReadOnly(true);
        p1.pass=ui->lineEdit_9->text();
    }
}


void mangelog::on_pushButton_15_clicked()
{
    if(!isedit3){
        isedit3=true;
        ui->lineEdit_11->setReadOnly(false);
    }
    else{
        isedit3=false;
        ui->lineEdit_11->setReadOnly(true);
        p1.id=ui->lineEdit_11->text();
    }
}


void mangelog::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}


void mangelog::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listWidget_3->setSpacing(3);
    ui->listWidget_3->clear();
    for(auto i=0u;i<lifo.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_3);
        cardfood *card=new cardfood(lifo[i].image,lifo[i].name,lifo[i].price,lifo[i].rate,lifo[i].mtn,i,(ui->listWidget_3),this);

        item->setSizeHint(QSize(700, 274));
        ui->listWidget_3->setItemWidget(item,card);
    }
}


void mangelog::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->listWidget_4->setSpacing(3);
    ui->listWidget_4->clear();
    for(auto i=0u;i<sili.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_4);
        sidescard *card=new sidescard(sili[i].name,sili[i].price,sili[i].rate,sili[i].image,i,false,ui->listWidget_4,this);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_4->setItemWidget(item,card);
    }
}

void mangelog::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->listWidget_3->setSpacing(3);
    ui->listWidget_3->clear();
    for(auto i=0u;i<lifo.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_3);
        cardfood *card=new cardfood(lifo[i].image,lifo[i].name,lifo[i].price,lifo[i].rate,lifo[i].mtn,i,(ui->listWidget_3),this);

        item->setSizeHint(QSize(700, 274));
        ui->listWidget_3->setItemWidget(item,card);
    }
}


void mangelog::on_pushButton_19_clicked()
{
    flagsS=true;
    ui->frame_6->setVisible(flagsS);
}


void mangelog::on_pushButton_20_clicked()
{
    QMenu menu(this);
    QAction *action1 = menu.addAction(QIcon(":/new/prefix1/Images/brett-jordan-aKYu-H5pHJY-unsplash.jpg"), tr("FANTA IMAGE"));
    QAction *action2 = menu.addAction(QIcon(":/new/prefix1/Images/tania-melnyczuk-xeTv9N2FjXA-unsplash (1).jpg"), tr("SALADE IMAGE"));
    QAction *action3 = menu.addAction(QIcon(":/new/prefix1/Images/pixzolo-photography-8YBHgP0WrEo-unsplash.jpg"), tr("FRIZA IMAGE"));
    QAction *action4 = menu.addAction(QIcon(":/new/prefix1/Images/ivan-yerokhin-aJ8CYMhemc8-unsplash.jpg"), tr("Cokalo IMAGE"));


    QAction *selectedAction = menu.exec(ui->pushButton_20->mapToGlobal(QPoint(0, ui->pushButton_20->height())));

    if (selectedAction) {
        QString im;
        if (selectedAction == action1) {
            im = ":/new/prefix1/Images/brett-jordan-aKYu-H5pHJY-unsplash.jpg";
        }
        else if (selectedAction == action2) {
            im = ":/new/prefix1/Images/tania-melnyczuk-xeTv9N2FjXA-unsplash (1).jpg";
        }
        else if (selectedAction == action3) {
            im = ":/new/prefix1/Images/pixzolo-photography-8YBHgP0WrEo-unsplash.jpg";
        }
        else if (selectedAction == action4) {
            im = ":/new/prefix1/Images/ivan-yerokhin-aJ8CYMhemc8-unsplash.jpg";
        }

        side = im;
        int radius = 20;
        QString style = QString(
                            "background: transparent;"
                            "border-image: url(%1);"
                            "border-radius: %2px;"
                            ).arg(im).arg(radius);

        ui->label_23->setStyleSheet(style);
    }
}


void mangelog::on_pushButton_21_clicked()
{
    QString name=ui->lineEdit_12->text();
    QString rate=ui->lineEdit_13->text();
    QString price=ui->lineEdit_15->text();
    sides ps(rate,price,name,side);
    savesides();
    flagsS=false;
    ui->frame->setVisible(flagsS);
    ui->label_23->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
    ui->lineEdit_15->clear();
    side.clear();
    ui->listWidget_4->setSpacing(3);
    ui->listWidget_4->clear();
    for(auto i=0u;i<sili.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_4);
        sidescard *card=new sidescard(sili[i].name,sili[i].price,sili[i].rate,sili[i].image,i,false,ui->listWidget_4,this);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_4->setItemWidget(item,card);
    }
}


void mangelog::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
    ui->listWidget_4->setSpacing(3);
    ui->listWidget_4->clear();
    for(auto i=0u;i<sili.size();i+=1){
        QListWidgetItem *item=new QListWidgetItem(ui->listWidget_4);
        sidescard *card=new sidescard(sili[i].name,sili[i].price,sili[i].rate,sili[i].image,i,false,ui->listWidget_4,this);
        item->setSizeHint(QSize(358,398));
        ui->listWidget_4->setItemWidget(item,card);
    }
}

