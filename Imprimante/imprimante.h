#ifndef IMPRIMANTE_H
#define IMPRIMANTE_H

#include <QMainWindow>

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

private:
    Ui::Imprimante *ui;
    QString tout;
    QString caractere;
};
#endif // IMPRIMANTE_H
