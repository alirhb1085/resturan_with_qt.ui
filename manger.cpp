#include "manger.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
manger::manger(QString name,QString pass,QString id):name(name),id(id),pass(pass) {
    mangerl.push_back(*this);
}
void savemanger(){
    QJsonArray mangerArray;
    for (const auto &c : mangerl) {
        QJsonObject mangerobj;
        mangerobj["name"] = c.name;
        mangerobj["pass"] = c.pass;
        mangerobj["id"] = c.id;
        mangerArray.append(mangerobj);
    }
    QJsonObject mainObj;
    mainObj["mangers"]=mangerArray;
    QJsonDocument doc(mainObj);
    QFile file("mangers.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}
void loadmanger(){
    QFile file("mangers.json");
    if (!file.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();
    QJsonArray mangerArray = mainObj["mangers"].toArray();
    mangerl.clear();
    for (int i = 0; i < mangerArray.size(); i+=1) {
        QJsonObject mangerobj = mangerArray[i].toObject();
        QString name = mangerobj["name"].toString();
        QString pass = mangerobj["pass"].toString();
        QString id = mangerobj["id"].toString();
        manger f(name, pass, id);
    }
}
