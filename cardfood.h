#ifndef CARDFOOD_H
#define CARDFOOD_H

#include "ui_cardfood.h"
#include <QWidget>
#include <QPushButton>
#include <QListWidget>

namespace Ui {
class cardfood;
}

class cardfood : public QWidget
{
    Q_OBJECT

public:
    explicit cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int i,QListWidget *listWidget,QWidget *parent = nullptr);
    explicit cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int cou,int i,QWidget *parent = nullptr);
    explicit cardfood(QString im,QString nam,QString price,QString rate,QString mtn,int cou,int i,bool flag,QWidget *parent = nullptr);
    QString getFoodName() const;
    QPushButton *getbutton();
    ~cardfood();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::cardfood *ui;
    bool myFlag=false;
    bool flag=true;
    bool flaged=true;
    QString foodname;
    QListWidget *listWidget;
    int ted;
    int gh=-1;
    int co=-1;
};

#endif // CARDFOOD_H
