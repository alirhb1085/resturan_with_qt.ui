#ifndef CODECARD_H
#define CODECARD_H

#include <QWidget>

namespace Ui {
class codecard;
}

class codecard : public QWidget
{
    Q_OBJECT

public:
    explicit codecard(QString name,QWidget *parent = nullptr);
    ~codecard();

private slots:
    void on_pushButton_clicked();

private:
    Ui::codecard *ui;
};

#endif // CODECARD_H
