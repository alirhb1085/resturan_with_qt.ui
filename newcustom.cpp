#include "newcustom.h"
#include "ui_newcustom.h"
#include "customer.h"
#include "mainwindow.h"

QString number=0;

newcustom::newcustom(QString num,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::newcustom)
{
    number=num;
    ui->setupUi(this);
    connect(ui->lineEdit_4,&QLineEdit::textChanged,this,&newcustom::cheak);
    connect(ui->pushButton,&QPushButton::clicked,this,&newcustom::log);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&newcustom::back);
}

newcustom::~newcustom()
{
    delete ui;
}
void newcustom::cheak(){
    if((ui->lineEdit_4->text()).isEmpty()){
        ui->label_4->clear();
        ui->label_4->setText("I can see it :)");
    }
    else{
        ui->label_4->clear();
        ui->label_4->setText("I can't see :(");
    }
}
void newcustom::log(){
    if((ui->lineEdit->text()).isEmpty() && (ui->lineEdit_6->text()).isEmpty() && (ui->lineEdit_4->text()).isEmpty() && (ui->lineEdit_8->text()).isEmpty()){
        ui->label_6->setText("No name provided");
        ui->label_7->setText("No address provided");
        ui->label_8->setText("No password provided");
        ui->label_10->setText("No id provided");
    }
    else if((ui->lineEdit->text()).isEmpty()){
        ui->label_6->setText("No name provided");
    }
    else if((ui->lineEdit_6->text()).isEmpty()){
        ui->label_7->setText("No address provided");
    }
    else if((ui->lineEdit_4->text()).isEmpty()){
        ui->label_8->setText("No password provided");
    }
    else if((ui->lineEdit_8->text()).isEmpty()){
        ui->label_10->setText("No id provided");
    }
    else{
        QString na=ui->lineEdit->text();
        QString ad=ui->lineEdit_6->text();
        QString pa=ui->lineEdit_4->text();
        QString id=ui->lineEdit_8->text();
        customer p1(number,na,ad,pa,id);
        savecustomertofile();
        MainWindow *pagelog=new MainWindow();
        pagelog->show();
        this->close();
    }
}
void newcustom::back(){
    MainWindow *pagelog=new MainWindow();
    pagelog->show();
    this->close();
}
