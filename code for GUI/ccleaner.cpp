#include "ccleaner.h"
#include "ui_ccleaner.h"

ccleaner::ccleaner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ccleaner)
{
    ui->setupUi(this);
}

ccleaner::~ccleaner()
{
    delete ui;
}

void ccleaner::on_yes_pushButton_clicked()
{
    // give this a more unique name, since im not sure what the overwrite policy is
    QString filename = "Data.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "yes" << endl;
    }
    this->close();
}

void ccleaner::on_no_pushButton_clicked()
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
