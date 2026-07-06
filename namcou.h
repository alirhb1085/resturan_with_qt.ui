#ifndef NAMCOU_H
#define NAMCOU_H

#include <QWidget>

namespace Ui {
class namcou;
}

class namcou : public QWidget
{
    Q_OBJECT

public:
    explicit namcou(QString name,QString tedad,QString ima,QWidget *parent = nullptr);
    ~namcou();

private:
    Ui::namcou *ui;
};

#endif // NAMCOU_H
