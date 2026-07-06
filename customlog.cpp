#include "customlog.h"
#include "ui_customlog.h"
#include "mainwindow.h"
#include "customer.h"
#include "changepass.h"
#include "deskcoust.h"

int re=0;
customlog::customlog(int i,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::customlog)
{
    re=i;
    ui->setupUi(this);
    ui->name->clear();
    ui->name->setText(ac[i].name);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&customlog::ba);
    connect(ui->pushButton,&QPushButton::clicked,this,&customlog::co);
    connect(ui->pushButton_3,&QPushButton::clicked,this,&customlog::fo);
}

customlog::~customlog()
{
    delete ui;
}
void customlog::ba(){
    (ac[re].logview).push_back("The customer back to login page");
    MainWindow *pagelog=new MainWindow();
    pagelog->show();
    this->close();
}
void customlog::co(){
    QString pai=ui->lineEdit_4->text();
    if(ac[re].pass==pai){
        (ac[re].logview).push_back("The customer  to login in desk customer");
        savecustomertofile();
        deskcoust *pagelog=new deskcoust(re,this);
        pagelog->show();
        this->close();
    }
    else{
        ui->pushButton_3->setText("Forgot your password?");
    }
}
void customlog::fo(){
    (ac[re].logview).push_back("The customer  to login in changepass");
    savecustomertofile();
    changepass *pagelog=new changepass(re,this);
    pagelog->show();
    this->close();
}
