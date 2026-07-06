#include "changepass.h"
#include "ui_changepass.h"
#include "customer.h"
#include "mainwindow.h"

int pa=0;
bool flags=false;
changepass::changepass(int i,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::changepass)
{
    pa=i;
    ui->setupUi(this);
    ui->frame->setVisible(flags);
    connect(ui->pushButton,&QPushButton::clicked,this,&changepass::co);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&changepass::ba);
}

changepass::~changepass()
{
    delete ui;
}
void changepass::co(){
    (ac[pa].logview).push_back("The customer changed password");
    if(flags==false){
        QString idr=ui->lineEdit_8->text();
        if(ac[pa].id==idr){
            ui->label_11->clear();
            flags=true;
            ui->frame->setVisible(flags);
        }
        else{
            ui->label_11->setText("ID does not match");
        }
    }
    else{
        if(ui->lineEdit_4->text().isEmpty()){
            ui->label_10->setText("Password is empty");
        }
        else{
            ac[pa].pass=ui->lineEdit_4->text();
            savecustomertofile();
            ui->label_10->setText("Password changed successfully");
            ac[pa].logview.push_back("Password changed successfully to "+ui->lineEdit_4->text());
        }
    }
}
void changepass::ba(){
    (ac[pa].logview).push_back("The customer back to login page");
    MainWindow *pagelog=new MainWindow();
    flags=false;
    ui->frame->setVisible(flags);
    pagelog->show();
    this->close();
}
