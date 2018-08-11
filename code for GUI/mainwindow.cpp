#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ccleaner_pushButton_clicked()
{
    QProcess process;
    process.setWorkingDirectory("C:\\Users");
    process.start("cmd /c dir");
    process.waitForFinished(-1);
    QString output = process.readAllStandardOutput();
    int index=0;
    bool success = false;
    QString uname;
    while(!success) // this loops works to get the username of the account
    {
        bool found = false;
        if(!uname.isEmpty())
            uname = "";
        while (!found)
        {
            index = output.indexOf("<DIR>", index);
            index = output.indexOf(">", index);
            index++;
            int temp = index;
            while(!output[temp].isLetter())
                temp++;
            if (temp > output.indexOf("/", index))
                index = temp;
            else
            {
                found = true;
                index = temp;
            }
        }
        while(output[index].isLetterOrNumber())
        {
            uname += output[index];
            index++;
        }
        if (uname == "Default" || uname == "Public")
        {
            uname = "";
            continue;
        }
        if (uname == "")
                continue;
        process.start("cmd /c cd " + uname);
        process.waitForFinished(-1);
        QString error = process.readAllStandardError();
        if(error.isEmpty())
            success = true;
    }
    process.start("cmd /c dir C:\\Users\\" + uname + "\\AppData\\Roaming\\Microsoft\\Windows\\startm~1\\Programs\\Startup");
    //process.start("cmd /c cd");
    output = process.readAllStandardOutput();
    if(!output.contains("test.exe"))
    {
        bool moved = QFile::copy("C:/Users/" + uname + "/Downloads/simplifier/cleaning_checker.exe", "C:/Users/"+ uname +"/AppData/Roaming/Microsoft/Windows/startm~1/Programs/Startup/cleaning_checking.exe");
        process.start("cmd /c cd C:\\Users\\coder\\Downloads");
        //process.start("cmd /c move C:\\Users\\coder\\Downloads\\test.exe C:\\Users\\coder\\AppData\\Roaming\\Microsoft\\Windows\\startm~1\\Programs\\Startup");
        //process.waitForFinished(-1);
    }
    QString errore = process.readAll();
    process.start("cmd /c CCleaner.exe /AUTO");


}

void MainWindow::on_defraggler_pushButton_clicked()
{
        QProcess process;
        process.setWorkingDirectory("C:\\Users");
        process.start("cmd /c dir");
        process.waitForFinished(-1);
        QString output = process.readAllStandardOutput();
        int index=0;
        bool success = false;
        QString uname;
        while(!success) // this loops works to get the username of the account
        {
            bool found = false;
            if(!uname.isEmpty())
                uname = "";
            while (!found)
            {
                index = output.indexOf("<DIR>", index);
                index = output.indexOf(">", index);
                index++;
                int temp = index;
                while(!output[temp].isLetter())
                    temp++;
                if (temp > output.indexOf("/", index))
                    index = temp;
                else
                {
                    found = true;
                    index = temp;
                }
            }
            while(output[index].isLetterOrNumber())
            {
                uname += output[index];
                index++;
            }
            process.start("cmd /c cd " + uname);
            process.waitForFinished(-1);
            QString error = process.readAllStandardError();
            if(error.isEmpty())
                success = true;
        }
        process.setWorkingDirectory("C:\\Users\\" + uname +
        "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup");
        process.start("cmd /c dir");
        output = process.readAllStandardOutput();
        if(!output.contains("test.exe"))
        {
            bool moved = QFile::copy("C:/Users/" + uname + "/Downloads/simplifier/cleaning_checker.exe", "C:/Users/" +
                                     uname + "/AppData/Roaming/Microsoft/Windows/startm~1/Programs/Startup/cleaning_checker.exe");
            //process.setWorkingDirectory("C:\\Users\\" + uname + "\\Downloads");
            //process.start("cmd /c  move test.exe C:\\Users\\" + uname +
            //"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup");
        }
        process.start("cmd /c df.exe C:\\");

}
