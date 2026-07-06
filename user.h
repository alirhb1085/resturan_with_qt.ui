#ifndef USER_H
#define USER_H
#include <QString>
class user{
public:
    QString name;
    QString id;
    QString pass;
    user(QString n,QString i,QString p){
        name=n;
        id=i;
        pass=p;
    }
};

#endif // USER_H
