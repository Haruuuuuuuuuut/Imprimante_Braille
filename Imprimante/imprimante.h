#ifndef IMPRIMANTE_H
#define IMPRIMANTE_H

#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QString>
#include <QSerialPort>
#include <QtSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui {
class Imprimante;
}
QT_END_NAMESPACE

class Imprimante : public QMainWindow
{
    Q_OBJECT

public:
    Imprimante(QWidget *parent = nullptr);
    ~Imprimante();

private slots:
    void on_file_clicked();

    void on_convert_clicked();

    void on_envoie_clicked();



private:
    Ui::Imprimante *ui;

    QString tout;
    QString caractere;
    QString caractere2;
    QString infocase;
    QString desc;
    QString port;
    QByteArray push;

    QSerialPort* COMPORT;
};
#endif // IMPRIMANTE_H
