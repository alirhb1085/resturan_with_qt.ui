#ifndef CUSTOMLOG_H
#define CUSTOMLOG_H

#include <QMainWindow>

namespace Ui {
class customlog;
}

class customlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit customlog(int i,QWidget *parent = nullptr);
    ~customlog();

private:
    Ui::customlog *ui;
private slots:
    void ba();
    void co();
    void fo();
};

#endif // CUSTOMLOG_H
