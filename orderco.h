#ifndef ORDERCO_H
#define ORDERCO_H
#include "classfood.h"

class orderco
{
public:
    orderco(QString gimat,QVector<classfood> nami,int v=25);
    QString gimat;
    QVector<classfood> nami;
    int value;
};

#endif // ORDERCO_H
