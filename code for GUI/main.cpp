#include "mainwindow.h"
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ccleaner cbox;
    defraggler dbox;

    QProcess process;
    process.start("cmd /c cd C:\\PROGRA~1\\CCleaner");
    QString output;
    process.waitForFinished(-1);
    output= process.readAllStandardError();
    if (!output.isEmpty())
    {
        cbox.exec();
        QFile file("Data.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);
        QString line = in.readLine();

        file.close();
        if (line == "no")
        {
            QMessageBox msg;
            msg.setText("bye");
            msg.exec();
            return 0;
        }
        /*process.start("cmd /c dir ccsetup525.exe /s C:\\");
        process.waitForFinished(-1);
        QString diroutput = process.readAllStandardOutput();
        int start_location = 0;
        int length = 0;
        start_location = diroutput.indexOf("Directory of"); // make index refpointer
        // go to that to get path
        start_location = start_location + 13; // add 13 to current index
        // get subtring length (directory path length)
        length = diroutput.indexOf("\r", start_location) - start_location;
        // create substring
        QStringRef substring(&diroutput, start_location, length);
        //QChar where = diroutput[location];*/
        process.setWorkingDirectory("C:\\Users\\coder\\Downloads\\simplifier");
        process.start("cmd /c ccsetup525.exe /S");
        process.waitForFinished(-1);
        QString error = process.readAllStandardOutput();
        QString error1 = process.readAllStandardError();
    }
    process.start("cmd /c cd C:\\PROGRA~1\\Defraggler");
    process.waitForFinished(-1);
    output = process.readAllStandardError();
    if (!output.isEmpty())
    {
        dbox.exec();
        QFile file("Data.txt");
        if(!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream in(&file);
        QString line = in.readLine();

        file.close();
        if (line == "no")
        {
            QMessageBox msg;
            msg.setText("bye");
            msg.exec();
            return 0;
        }

        /*process.start("cmd /c dir dfsetup221.exe /s C:\\");
        process.waitForFinished(-1);
        QString diroutput = process.readAllStandardOutput();
        int start_location = 0;
        int length = 0;
        start_location = diroutput.indexOf("Directory of"); // make index refpointer
        // go to that to get path
        start_location = start_location + 13; // add 13 to current index
        // get subtring length (directory path length)
        length = diroutput.indexOf("\r", start_location) - start_location;
        // create substring
        QStringRef substring(&diroutput, start_location, length);
        //QChar where = diroutput[location];*/
        process.setWorkingDirectory("C:\\Users\\coder\\Downloads\\simplifier");
        process.start("cmd /c dfsetup221.exe /S");
        process.waitForFinished(-1);
        QString error = process.readAllStandardOutput();
        QString error1 = process.readAllStandardError();
    }

    w.show();

    return a.exec();
}
