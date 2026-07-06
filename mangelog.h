#ifndef MANGELOG_H
#define MANGELOG_H

#include <QMainWindow>
#include "manger.h"

namespace Ui {
class mangelog;
}

class mangelog : public QMainWindow
{
    Q_OBJECT

public:
    explicit mangelog(bool flag,manger p1,QWidget *parent = nullptr);
    manger p1;
    ~mangelog();

private:
    Ui::mangelog *ui;
    bool bo;

    bool isedit1=false;
    bool isedit2=false;
    bool isedit3=false;
    bool isedit4=false;
private slots:

    void cou();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void logout();
    void on_pushButton_3_clicked();
    void on_pushButton_12_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_13_clicked();
    void refreshList();
    void on_pushButton_7_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_11_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_19_clicked();
    void on_pushButton_20_clicked();
    void on_pushButton_21_clicked();
    void on_pushButton_18_clicked();

};

#endif // MANGELOG_H
