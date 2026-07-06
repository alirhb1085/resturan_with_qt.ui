#include "codecard.h"
#include "ui_codecard.h"
#include <QClipboard>
codecard::codecard(QString name,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::codecard)
{
    ui->setupUi(this);
    ui->label_3->setText(name);
}

codecard::~codecard()
{
    delete ui;
}

void codecard::on_pushButton_clicked()
{
    QClipboard *copy=QApplication::clipboard();
    copy->setText(ui->label_3->text());
}

