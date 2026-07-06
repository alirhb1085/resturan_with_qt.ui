#include "code.h"

code::code(QString name):name(name) {
    QString ad=name.slice(4);
    int miz=ad.toInt();
    this->mizan=miz;
}
