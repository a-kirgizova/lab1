#include <QCoreApplication>
#include <QTextStream>
#include <QTextCodec>
#include "walker.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream cin(stdin);
    QTextStream cout(stdout);
    cout.setCodec(QTextCodec::codecForName("cp866"));

    cout << "Enter folder path: ";
    cout.flush();
    QString path = cin.readLine();

    walker walker;
    walker.walk(path);

    cout << Qt::endl;

    return 0;
}
