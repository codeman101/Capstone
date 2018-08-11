#ifndef CCLEANER_H
#define CCLEANER_H

#include <QDialog>
#include <QAbstractButton>
#include <QFile>
#include <QTextStream>

namespace Ui {
class ccleaner;
}

class ccleaner : public QDialog
{
    Q_OBJECT

public:
    explicit ccleaner(QWidget *parent = 0);
    ~ccleaner();

private slots:
    void on_yes_pushButton_clicked();

    void on_no_pushButton_clicked();

private:
    Ui::ccleaner *ui;
};

#endif // CCLEANER_H
