#include "cutomcard.h"
#include "ui_cutomcard.h"
#include "cardlog.h"
#include <QListWidgetItem>
#include "customer.h"
#include "manorder.h"
cutomcard::cutomcard(QString name,QString addrase,QString id,QVector<QString> lo,QListWidget *listWidget_2,int i,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cutomcard),tar(listWidget_2),lop(lo)
{
    ui->setupUi(this);
    this->co=i;
    QString fa="   ";
    ui->label_2->setText(fa+name);
    ui->label_4->setText(fa+addrase);
    ui->label_5->setText(fa+id);
    connect(ui->pushButton,&QPushButton::clicked,this,&cutomcard::logv);
}

cutomcard::~cutomcard()
{
    delete ui;
}
void cutomcard::logv(){
    if(tar){
        tar->clear();
        for(auto i = 0u; i < lop.size(); ++i) {

            QListWidgetItem *item = new QListWidgetItem();
            item->setSizeHint(QSize(270, 60));

            tar->addItem(item);

            cardlog *card = new cardlog(i, lop[i], this);
            tar->setItemWidget(item, card);
        }
    }

}

void cutomcard::on_pushButton_2_clicked(){
    if(tar){
        tar->clear();
        for(auto i=0u;i<ac[co].ordercou.size();i+=1){
                QListWidgetItem *item = new QListWidgetItem(tar);
                manorder *card = new manorder(ac[co].ordercou[i].gimat,ac[co].ordercou[i].value,co,i,this);
                item->setSizeHint(QSize(380, 380));
                tar->setItemWidget(item,card);
        }
    }
}


