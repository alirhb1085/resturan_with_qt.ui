#ifndef ORDERCARD_H
#define ORDERCARD_H

#include <QWidget>

namespace Ui {
class ordercard;
}

class ordercard : public QWidget
{
    Q_OBJECT

public:
    explicit ordercard(QString im,QString nam,QString price,int tedad,int cou,QWidget *parent = nullptr);
    ~ordercard();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ordercard *ui;
    int cou;
    int gh;
    QString price;
    QString name;
    QString im;
signals:
    void add();
    void rem();
};

#endif // ORDERCARD_H
