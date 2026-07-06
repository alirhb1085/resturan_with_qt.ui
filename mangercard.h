#ifndef MANGERCARD_H
#define MANGERCARD_H

#include <QWidget>


namespace Ui {
class mangercard;
}

class mangercard : public QWidget
{
    Q_OBJECT

public:
    explicit mangercard(QString name,QString pass,QString id,int i,QWidget *parent = nullptr);
    ~mangercard();
signals:
    void carddel(int index);
private slots:
    void on_pushButton_clicked();

private:
    Ui::mangercard *ui;
    int j;
};

#endif // MANGERCARD_H
