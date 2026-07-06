#ifndef CUTOMCARD_H
#define CUTOMCARD_H

#include <QWidget>
#include<QListWidget>

namespace Ui {
class cutomcard;
}

class cutomcard : public QWidget
{
    Q_OBJECT

public:
    explicit cutomcard(QString name,QString addrase,QString id,QVector<QString> lo,QListWidget *listWidget_2,int i,QWidget *parent = nullptr);
    ~cutomcard();

private:
    Ui::cutomcard *ui;
    QListWidget *tar;
    QVector<QString>lop;
    int co;
private slots:
    void logv();
    void on_pushButton_2_clicked();
};

#endif // CUTOMCARD_H
