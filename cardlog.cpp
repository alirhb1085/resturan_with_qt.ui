#include "cardlog.h"
#include "ui_cardlog.h"

cardlog::cardlog(int i,QString l,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cardlog)
{
    ui->setupUi(this);
    QString ad=QString::number(i+1);
    ui->label->clear();
    ui->label_2->clear();
    ui->label->setText(ad+")");
    ui->label_2->setText(l);
}

cardlog::~cardlog()
{
    delete ui;
}
