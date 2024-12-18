#include "imprimante.h"
#include <QString>
#include <QApplication>
#include <QFileDialog>
#include <QTextStream>
#include <QChar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Imprimante w;
    w.show();
    return a.exec();
}
