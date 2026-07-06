#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <Qstring>
#include <QVector>
#include "classfood.h"
#include "user.h"
#include "code.h"
#include "orderco.h"
class customer;
extern QVector<customer> ac;
class customer:public user{
public:
    QVector<orderco> ordercou;
    QString phone;
    QVector<code> khod;
    QString addrese="";
    QVector<classfood>menu;
    QVector<classfood>favar;
    QVector<classfood>order;
    QVector<QString>logview;
    customer(QString num,QString name,QString adderse,QString password,QString id);
};
void savecustomertofile();
void loadcustomertofile();
#endif // CUSTOMER_H
