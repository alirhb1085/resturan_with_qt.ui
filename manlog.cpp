#include "manlog.h"
#include "ui_manlog.h"
#include "mainwindow.h"
#include "manger.h"
#include "mangelog.h"
manger p1("Ali","Ali85","alirhb");
manlog::manlog(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::manlog)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&manlog::pb);
    connect(ui->lineEdit_4,&QLineEdit::textChanged,this,&manlog::cheak);
    connect(ui->pushButton,&QPushButton::clicked,this,&manlog::log);
}

manlog::~manlog()
{
    delete ui;
}
void manlog::pb(){
    MainWindow *pagelog=new MainWindow();
    pagelog->show();
    this->close();
}
void manlog::cheak(){
    if((ui->lineEdit_4->text()).isEmpty()){
        ui->label_4->clear();
        ui->label_4->setText("I can see it :)");
    }
    else{
        ui->label_4->clear();
        ui->label_4->setText("I can't see :(");
    }
}
void manlog::log(){
    QString id=ui->lineEdit->text();
    QString pass=ui->lineEdit_4->text();
    if(p1.pass==pass && p1.id==id){
        mangelog *pagelog=new mangelog(true,p1);
        pagelog->show();
        this->close();
    }
    else{
        for(auto i=0u;i<mangerl.size();i+=1){
            if(mangerl[i].pass==pass && mangerl[i].id==id){
                mangelog *pagelog=new mangelog(false,mangerl[i]);
                pagelog->show();
                this->close();
            }
        }
        ui->label_10->clear();
        ui->label_10->setText("No id or password provided");
    }
}
