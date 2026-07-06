#include "classfood.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
classfood::classfood(QString name,QString mtn,QString image,QString rate,QString price):name(name),mtn(mtn),image(image),rate(rate),price(price){
    if(mtn!=""){
    lifo.push_back(*this);
    }
}
classfood::classfood(QString name,QString mtn,QString image,QString rate,QString price,bool flag):name(name),mtn(mtn),image(image),rate(rate),price(price){}

void savefood(){
    QJsonArray foodArray;
    for (const auto &c : lifo) {
        QJsonObject foodobj;
        foodobj["image"] = c.image;
        foodobj["mtn"] = c.mtn;
        foodobj["name"] = c.name;
        foodobj["rate"] = c.rate;
        foodobj["price"] = c.price;
        foodArray.append(foodobj);
    }
    QJsonObject mainObj;
    mainObj["foods"]=foodArray;
    QJsonDocument doc(mainObj);
    QFile file("foods.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}


void loadfood() {
    QFile file("foods.json");
    if (!file.open(QIODevice::ReadOnly)){
        return;
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();
    QJsonArray foodArray = mainObj["foods"].toArray();
    lifo.clear();
    for (int i = 0; i < foodArray.size(); i+=1) {
        QJsonObject foodobj = foodArray[i].toObject();
        QString name = foodobj["name"].toString();
        QString mtn = foodobj["mtn"].toString();
        QString image = foodobj["image"].toString();
        QString rate = foodobj["rate"].toString();
        QString price = foodobj["price"].toString();
        classfood f(name, mtn, image, rate, price);
    }
}
