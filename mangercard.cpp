#include "mangercard.h"
#include "ui_mangercard.h"
#include "manger.h"
#include "mangelog.h"

mangercard::mangercard(QString name,QString pass,QString id,int i,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mangercard)
{
    ui->setupUi(this);
    ui->label_2->clear();
    ui->label_4->clear();
    ui->label_5->clear();
    this->j=i;
    ui->label_2->setText(name);
    ui->label_4->setText(pass);
    ui->label_5->setText(id);
}

mangercard::~mangercard()
{
    delete ui;
}

void mangercard::on_pushButton_clicked()
{
    mangerl.remove(j);
    emit carddel(j);
}

