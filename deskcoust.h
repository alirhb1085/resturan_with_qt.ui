#ifndef DESKCOUST_H
#define DESKCOUST_H

#include <QMainWindow>

namespace Ui {
class deskcoust;
}

class deskcoust : public QMainWindow
{
    Q_OBJECT

public:
    explicit deskcoust(int i,QWidget *parent = nullptr);
    // static deskcoust* ip;
    ~deskcoust();
public slots:
    void refreshCardList();

private slots:
    void on_pushButton_3_clicked();
    void buedi1();
    void buedi2();
    void buedi3();
    void buedi4();
    void logout();

    void on_pushButton_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();


    void on_pushButton_10_clicked();

    void up();

    void on_pushButton_9_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

private:
    Ui::deskcoust *ui;
    bool isedit1=false;
    bool isedit2=false;
    bool isedit3=false;
    bool isedit4=false;
};

#endif // DESKCOUST_H
