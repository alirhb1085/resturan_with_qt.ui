#ifndef MANORDER_H
#define MANORDER_H

#include <QWidget>

namespace Ui {
class manorder;
}

class manorder : public QWidget
{
    Q_OBJECT

public:
    explicit manorder(QString gimat,int value,int co,int ord,QWidget *parent = nullptr);
    ~manorder();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manorder *ui;
    int ord;
    int co;
};

#endif // MANORDER_H
