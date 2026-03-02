#include "walker.hpp"
#include <QDir>
#include <QFileInfo>
#include <QTextStream>

QTextStream cin (stdin);
QTextStream cout (stdout);

void walker::walk(const QString& path, int level) {
    QDir dir(path);
    if (!dir.exists()){
        cout<<"Floder not found";
        return;
    }
    QFileInfoList list = dir.entryInfoList(
        QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot
        );

    for (auto entry : list)
    {
        QString indent(level * 3, ' ');

        if (entry.isDir())
        {
            cout << indent << "[DIR]" << entry.fileName();
            walk(entry.absoluteFilePath(), level + 1);
        }
        else
        {
            cout << indent << "[FILE]" << entry.fileName();
        }
    }
}
