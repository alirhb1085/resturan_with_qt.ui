#ifndef INFOCARD_H
#define INFOCARD_H

#include <QWidget>
#include<QListWidget>

namespace Ui {
class infocard;
}

class infocard : public QWidget
{
    Q_OBJECT

public:
    explicit infocard(QListWidget *listWidget_8,int i,int co,int vs,QWidget *parent = nullptr);
    ~infocard();

private:
    Ui::infocard *ui;
    QListWidget *tar;
    int val;
    int i;
    int co;
private slots:
    void pl(int v);
    void on_pushButton_clicked();
};

#endif // INFOCARD_H
