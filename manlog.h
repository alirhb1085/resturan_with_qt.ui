#ifndef MANLOG_H
#define MANLOG_H

#include <QMainWindow>

namespace Ui {
class manlog;
}

class manlog : public QMainWindow
{
    Q_OBJECT

public:
    explicit manlog(QWidget *parent = nullptr);
    ~manlog();

private:
    Ui::manlog *ui;
private slots:
    void pb();
    void cheak();
    void log();
};

#endif // MANLOG_H
