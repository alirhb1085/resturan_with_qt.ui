#ifndef NEWCUSTOM_H
#define NEWCUSTOM_H

#include <QMainWindow>

namespace Ui {
class newcustom;
}

class newcustom : public QMainWindow
{
    Q_OBJECT

public:
    explicit newcustom(QString num,QWidget *parent = nullptr);
    ~newcustom();

private:
    Ui::newcustom *ui;
private slots:
    void cheak();
    void log();
    void back();
};

#endif // NEWCUSTOM_H
