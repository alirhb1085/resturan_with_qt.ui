#include "sides.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
sides::sides(QString rate,QString price,QString name,QString image):rate(rate),price(price),name(name),image(image) {
    sili.push_back(*this);
}
void savesides(){
    QJsonArray sidesArray;
    for (const auto &c : sili) {
        QJsonObject sidesobj;
        sidesobj["image"] = c.image;
        sidesobj["name"] = c.name;
        sidesobj["rate"] = c.rate;
        sidesobj["price"] = c.price;
        sidesArray.append(sidesobj);
    }
    QJsonObject mainObj;
    mainObj["sides"]=sidesArray;
    QJsonDocument doc(mainObj);
    QFile file("sides.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}
void loadsides(){
    QFile file("sides.json");
    if (!file.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();
    QJsonArray sidesArray = mainObj["sides"].toArray();
    sili.clear();
    for (int i = 0; i < sidesArray.size(); i+=1) {
        QJsonObject sidesobj = sidesArray[i].toObject();
        QString name = sidesobj["name"].toString();
        QString image = sidesobj["image"].toString();
        QString rate = sidesobj["rate"].toString();
        QString price = sidesobj["price"].toString();
        sides f(rate, price, name, image);
    }
}
