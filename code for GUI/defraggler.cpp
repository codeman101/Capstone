#include "defraggler.h"
#include "ui_defraggler.h"

defraggler::defraggler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::defraggler)
{
    ui->setupUi(this);
}

defraggler::~defraggler()
{
    delete ui;
}

void defraggler::on_yes_pushButton_clicked()
{
    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "yes" << endl;
    }
    this->close();
}

void defraggler::on_no_pushButton_clicked()
{
    // give this a more unique name, since im not sure what the overwrite policy is
    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "no" << endl;
    }
    this->close();
}
