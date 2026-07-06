#ifndef MANGER_H
#define MANGER_H
#include <QString>
#include <QVector>
class manger;
inline QVector<manger> mangerl;
class manger
{
public:
    QString name;
    QString id;
    QString pass;
    manger(QString name,QString pass,QString id);
};
void savemanger();
void loadmanger();
#endif // MANGER_H
