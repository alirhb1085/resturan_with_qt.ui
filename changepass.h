#ifndef CHANGEPASS_H
#define CHANGEPASS_H

#include <QMainWindow>

namespace Ui {
class changepass;
}

class changepass : public QMainWindow
{
    Q_OBJECT

public:
    explicit changepass(int i,QWidget *parent = nullptr);
    ~changepass();

private:
    Ui::changepass *ui;
private slots:
    void co();
    void ba();
};

#endif // CHANGEPASS_H
