#ifndef ORDERL_H
#define ORDERL_H
#include <QString>
#include <QVector>
class orderl;
extern QVector<orderl> orc;
class orderl
{
public:
    orderl(QString name,QString price,QString im,int tedad);
    int tedad;
    QString name;
    QString price;
    QString im;
};

#endif // ORDERL_H
