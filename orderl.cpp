#include "orderl.h"

orderl::orderl(QString name,QString price,QString im,int tedad):name(name),price(price),im(im),tedad(tedad) {
    orc.push_back(*this);
}
