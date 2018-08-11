#ifndef DEFRAGGLER_H
#define DEFRAGGLER_H

#include <QDialog>
#include <QAbstractButton>
#include <QFile>
#include <QTextStream>

namespace Ui {
class defraggler;
}

class defraggler : public QDialog
{
    Q_OBJECT

public:
    explicit defraggler(QWidget *parent = 0);
    ~defraggler();

private slots:
    void on_yes_pushButton_clicked();

    void on_no_pushButton_clicked();

private:
    Ui::defraggler *ui;
};

#endif // DEFRAGGLER_H
