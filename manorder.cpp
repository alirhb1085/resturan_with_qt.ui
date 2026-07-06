#include "manorder.h"
#include "ui_manorder.h"
#include "customer.h"
manorder::manorder(QString gimat,int value,int co,int ord,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::manorder)
{
    ui->setupUi(this);
    this->ord=ord;
    this->co=co;
    // QString a=QString::number(gimat);
    ui->label_4->clear();
    ui->label_4->setText(gimat);
    if(value==25){
        ui->label_5->setText("  Awaiting Restaurant Approval");
    }
    else if(value==50){
         ui->label_5->setText("  Preparing");
    }
    else if(value==75){
        ui->label_5->setText("  On the Way");
    }
    else if(value==100){
        ui->label_5->setText("  Compelet");
        ui->pushButton->setVisible(false);
        ui->pushButton_2->setVisible(false);
    }
}

manorder::~manorder()
{
    delete ui;
}

void manorder::on_pushButton_clicked()
{
    ui->label_5->clear();
    ui->label_5->setText("  Preparing");
    ac[co].ordercou[ord].value=50;
}


void manorder::on_pushButton_2_clicked()
{
    ui->label_5->clear();
    ui->label_5->setText("  On the Way");
    ac[co].ordercou[ord].value=75;
}


void manorder::on_pushButton_3_clicked()
{
    ui->label_5->clear();
    ui->label_5->setText("  Compelet");
    ac[co].ordercou[ord].value=100;
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
}

