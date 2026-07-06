#ifndef CARDLOG_H
#define CARDLOG_H
#pragma once
#include <QWidget>

namespace Ui {
class cardlog;
}

class cardlog : public QWidget
{
    Q_OBJECT

public:
    explicit cardlog(int i,QString l,QWidget *parent = nullptr);
    ~cardlog();

private:
    Ui::cardlog *ui;
};

#endif // CARDLOG_H
