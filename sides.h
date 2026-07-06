#ifndef SIDES_H
#define SIDES_H
#include <QVector>
class sides;
inline QVector<sides> sili;
class sides
{
public:
    QString rate;
    QString price;
    QString name;
    QString image;
    sides(QString rate,QString price,QString name,QString image);
};
void savesides();
void loadsides();
#endif // SIDES_H
