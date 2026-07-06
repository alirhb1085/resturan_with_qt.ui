QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cardfood.cpp \
    cardlog.cpp \
    changepass.cpp \
    classfood.cpp \
    code.cpp \
    codecard.cpp \
    customer.cpp \
    customlog.cpp \
    cutomcard.cpp \
    deskcoust.cpp \
    infocard.cpp \
    main.cpp \
    mainwindow.cpp \
    mangelog.cpp \
    manger.cpp \
    mangercard.cpp \
    manlog.cpp \
    manorder.cpp \
    namcou.cpp \
    newcustom.cpp \
    ordercard.cpp \
    orderco.cpp \
    sides.cpp \
    sidescard.cpp

HEADERS += \
    cardfood.h \
    cardlog.h \
    changepass.h \
    classfood.h \
    code.h \
    codecard.h \
    customer.h \
    customlog.h \
    cutomcard.h \
    deskcoust.h \
    infocard.h \
    mainwindow.h \
    mangelog.h \
    manger.h \
    mangercard.h \
    manlog.h \
    manorder.h \
    namcou.h \
    newcustom.h \
    ordercard.h \
    orderco.h \
    sides.h \
    sidescard.h \
    user.h

FORMS += \
    cardfood.ui \
    cardlog.ui \
    changepass.ui \
    codecard.ui \
    customlog.ui \
    cutomcard.ui \
    deskcoust.ui \
    infocard.ui \
    mainwindow.ui \
    mangelog.ui \
    mangercard.ui \
    manlog.ui \
    manorder.ui \
    namcou.ui \
    newcustom.ui \
    ordercard.ui \
    sidescard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    re.qrc
