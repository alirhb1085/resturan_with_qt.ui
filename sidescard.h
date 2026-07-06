#ifndef SIDESCARD_H
#define SIDESCARD_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class sidescard;
}

class sidescard : public QWidget
{
    Q_OBJECT

public:
    explicit sidescard(QString name,QString price,QString rate,QString im,int co,int  i,bool flag,QWidget *parent = nullptr);
    explicit sidescard(QString name,QString price,QString rate,QString im,int  i,bool flag,QListWidget *listWidget,QWidget *parent = nullptr);
    ~sidescard();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_5_clicked();

signals:
    void up();
private:
    Ui::sidescard *ui;
    bool flag;
    int co;
    int si;
    QListWidget *listWidget;
};

#endif // SIDESCARD_H
