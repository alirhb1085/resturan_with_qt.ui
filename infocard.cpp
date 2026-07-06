#include "infocard.h"
#include "ui_infocard.h"
#include "customer.h"
#include "orderco.h"
#include "namcou.h"

infocard::infocard(QListWidget *listWidget_8,int i,int co,int vs,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::infocard),tar(listWidget_8),val(vs)
{
    ui->setupUi(this);
    this->co=co;
    this->i=i;
    connect(ui->progressBar,&QProgressBar::valueChanged,this,&infocard::pl);
    ui->progressBar->setValue(val);
    pl(val);
}

infocard::~infocard()
{
    delete ui;
}
void infocard::pl(int v){
    if(v==25){
        ui->label_4->clear();
        ui->label_4->setText("  Awaiting Restaurant Approval");
    }
    else if(v==50){
        ui->label_4->clear();
        ui->label_4->setText("  Preparing");
    }
    else if(v==75){
        ui->label_4->clear();
        ui->label_4->setText("  On the Way");
    }
    else if(v==100){
        ui->label_4->clear();
        ui->label_4->setText("  Compelet");
    }
}

void infocard::on_pushButton_clicked()
{
    struct FoodSummary {
        int count=0;
        QString im;
    };
    tar->clear();
    QHash<QString, FoodSummary> summaryMap;
    int totalItems = ac[co].ordercou[i].nami.size();

    for (int j = 0; j < totalItems; ++j) {
        const classfood& food = ac[co].ordercou[i].nami[j];
        summaryMap[food.name].count += 1;
        summaryMap[food.name].im = food.image;
    }
    for (auto it = summaryMap.constBegin(); it != summaryMap.constEnd(); ++it) {
        QString foodName = it.key();
        int total = it.value().count;
        QString a=QString::number(total);
        QListWidgetItem *item = new QListWidgetItem(tar);
        QString image = it.value().im;
        namcou *card = new namcou(foodName,a, image, tar);
        item->setSizeHint(QSize(321, 101));
        tar->setItemWidget(item, card);
    }
}

