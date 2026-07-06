#include "customer.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
QVector<customer> ac;
customer::customer(QString num, QString name, QString adderse, QString password, QString id)
    : user(name, id, password), phone(num), addrese(adderse)
{
    ac.push_back(*this);
}

void savecustomertofile() {
    QJsonArray customersArray;

    for (const auto &c : ac) {
        QJsonObject customerObj;
        customerObj["phone"] = c.phone;
        customerObj["address"] = c.addrese;
        customerObj["name"] = c.name;
        customerObj["password"] = c.pass;
        customerObj["id"] = c.id;
        QJsonArray logArray;
        for (const QString &log : c.logview) {
            logArray.append(log);
        }
        customerObj["logview"] = logArray;


        auto foodsToJson = [](const QVector<classfood> &foodVector) {
            QJsonArray arr;
            for (const auto &f : foodVector) {
                QJsonObject fObj;
                fObj["name"] = f.name;
                fObj["mtn"] = f.mtn;
                fObj["image"] = f.image;
                fObj["rate"] = f.rate;
                fObj["price"] = f.price;
                arr.append(fObj);
            }
            return arr;
        };


        customerObj["menu"] = foodsToJson(c.menu);
        customerObj["favar"] = foodsToJson(c.favar);
        customerObj["order"] = foodsToJson(c.order);

        QJsonArray khodArray;
        for (const auto &k : c.khod) {
            QJsonObject kObj;
            kObj["name"] = k.name;
            kObj["mizan"] = k.mizan;
            khodArray.append(kObj);
        }
        customerObj["khod"] = khodArray;


        QJsonArray ordercouArray;
        for (const auto &o : c.ordercou) {
            QJsonObject oObj;
            oObj["gimat"] = o.gimat;
            oObj["value"] = o.value;
            oObj["nami"] = foodsToJson(o.nami);
            ordercouArray.append(oObj);
        }
        customerObj["ordercou"] = ordercouArray;

        customersArray.append(customerObj);
    }

    QJsonObject mainObj;
    mainObj["customers"] = customersArray;

    QJsonDocument doc(mainObj);
    QFile file("customers.json");
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}


void loadcustomertofile() {
    QFile file("customers.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();
    QJsonArray customersArray = mainObj["customers"].toArray();

    ac.clear();

    for (int i = 0; i < customersArray.size(); ++i) {
        QJsonObject customerObj = customersArray[i].toObject();

        QString phone = customerObj["phone"].toString();
        QString address = customerObj["address"].toString();
        QString name = customerObj["name"].toString();
        QString password = customerObj["password"].toString();
        QString id = customerObj["id"].toString();


        customer c(phone, name, address, password, id);

        QJsonArray logArray = customerObj["logview"].toArray();
        for (int j = 0; j < logArray.size(); ++j) {
            ac.last().logview.append(logArray[j].toString());
        }


            auto jsonToFoods = [](const QJsonArray &arr) {
                  QVector<classfood> vec;
                  for (int j = 0; j < arr.size(); ++j) {
                      QJsonObject fObj = arr[j].toObject();
                      classfood f(fObj["name"].toString(), fObj["mtn"].toString(),
                                  fObj["image"].toString(), fObj["rate"].toString(),
                                  fObj["price"].toString(), true); // <--- استفاده از سازنده دوم (flag)
                      vec.append(f);
                  }
                  return vec;
              };


        ac.last().menu = jsonToFoods(customerObj["menu"].toArray());
        ac.last().favar = jsonToFoods(customerObj["favar"].toArray());
        ac.last().order = jsonToFoods(customerObj["order"].toArray());


        QJsonArray khodArray = customerObj["khod"].toArray();
        for (int j = 0; j < khodArray.size(); ++j) {
            QJsonObject kObj = khodArray[j].toObject();
            code k(kObj["name"].toString());
            k.mizan = kObj["mizan"].toInt();
            ac.last().khod.append(k);
        }
        QJsonArray ordercouArray = customerObj["ordercou"].toArray();
        for (int j = 0; j < ordercouArray.size(); ++j) {
            QJsonObject oObj = ordercouArray[j].toObject();

            QString gimat = oObj["gimat"].toString();
            int value = oObj["value"].toInt();
            QVector<classfood> nami = jsonToFoods(oObj["nami"].toArray());

            orderco o(gimat, nami, value);
            ac.last().ordercou.append(o);
        }
    }
}
