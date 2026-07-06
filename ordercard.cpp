#include "ordercard.h"
#include "ui_ordercard.h"
#include "customer.h"
#include "classfood.h"

ordercard::ordercard(QString im,QString nam,QString price,int tedad,int cou,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ordercard)
{
    ui->setupUi(this);
    this->cou=cou;
    this->price=price;
    this->name=nam;
    this->im=im;
    ui->label->clear();
    ui->label_2->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label->setText(nam);
    double p=price.toDouble();
    QString vo=QString::number(p*tedad);
    ui->label_2->setText(vo);
    QString t=QString::number(tedad);
    ui->label_3->setText(t);
    int radius=20;
    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(im).arg(radius);
    ui->label_4->setStyleSheet(style);
    ui->label_4->setScaledContents(true);
}

ordercard::~ordercard()
{
    delete ui;
}

void ordercard::on_pushButton_clicked()
{
    ac[cou].order.push_back(classfood(name,"",im,"",price));
    emit add();
}


void ordercard::on_pushButton_2_clicked()
{
    emit rem();
}

