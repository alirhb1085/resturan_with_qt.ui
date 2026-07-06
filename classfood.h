#ifndef CLASSFOOD_H
#define CLASSFOOD_H
#include <QString>
#include <QVector>
class classfood;
inline QVector<classfood> lifo;
class classfood
{
public:
    QString rate;
    QString price;
    QString name;
    QString mtn;
    QString image;
    classfood(QString name,QString mtn,QString image,QString rate,QString price);
    classfood(QString name,QString mtn,QString image,QString rate,QString price,bool flag);
};
void savefood();
void loadfood();
#endif // CLASSFOOD_H
