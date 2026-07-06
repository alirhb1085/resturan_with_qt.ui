#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manlog.h"
#include "customlog.h"
#include "customer.h"
#include "newcustom.h"
#include <QRegularExpression>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_2,&QPushButton::clicked,this,&MainWindow::pl);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::co);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::pl(){
    manlog *pagelog=new manlog();
    pagelog->show();
    this->close();
}
bool bar(QString num){
    QRegularExpression regex("^09\\d{9}$");
    bool a=regex.match(num).hasMatch();
    return !a;
}
void MainWindow::co(){
    QString num=ui->lineEdit->text();
    if(num=="" || num.size()!=11 || bar(num)){
        ui->label_6->setText("No phone provided");
    }
    else{
        bool flag=true;
        for(auto i=0u;i<ac.size();i+=1){
            if(ac[i].phone==num){
                flag=false;
                customlog *pagelog=new customlog(i,this);
                pagelog->show();
                this->hide();
                break;
            }
        }
        if(flag){
            newcustom *pagelog=new newcustom(num,this);
            pagelog->show();
            this->hide();
        }
    }
}
