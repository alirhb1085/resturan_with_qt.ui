#include "namcou.h"
#include "ui_namcou.h"

namcou::namcou(QString name,QString tedad,QString ima,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::namcou)
{
    ui->setupUi(this);


    ui->label->clear();
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label->setText(name);
    ui->label_3->setText(tedad);
    // qDebug()<<"I"<<ima;
    // qDebug()<<"E"<<QFile::exists(ima);
    // QPixmap pix(ima);
    // qDebug()<<"N"<<pix.isNull();
    // ui->label_4->setPixmap(pix);
    // ui->label_4->setScaledContents(true);
    int radius = 20;

    QString style = QString(
                        "border-image: url(%1);"
                        "border-radius: %2px;"
                        "background: transparent;"
                        ).arg(ima).arg(radius);
    ui->label_4->setStyleSheet(style);
}

namcou::~namcou()
{
    delete ui;
}
