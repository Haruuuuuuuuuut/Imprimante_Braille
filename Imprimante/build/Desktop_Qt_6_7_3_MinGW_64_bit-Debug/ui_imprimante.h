/********************************************************************************
** Form generated from reading UI file 'imprimante.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPRIMANTE_H
#define UI_IMPRIMANTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Imprimante
{
public:
    QWidget *centralwidget;
    QLineEdit *acces;
    QTextEdit *txttout;
    QTextEdit *txtbraille;
    QPushButton *file;
    QPushButton *convert;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Imprimante)
    {
        if (Imprimante->objectName().isEmpty())
            Imprimante->setObjectName("Imprimante");
        Imprimante->resize(864, 639);
        centralwidget = new QWidget(Imprimante);
        centralwidget->setObjectName("centralwidget");
        acces = new QLineEdit(centralwidget);
        acces->setObjectName("acces");
        acces->setGeometry(QRect(160, 20, 541, 41));
        acces->setReadOnly(true);
        txttout = new QTextEdit(centralwidget);
        txttout->setObjectName("txttout");
        txttout->setGeometry(QRect(380, 110, 441, 231));
        txttout->setReadOnly(true);
        txtbraille = new QTextEdit(centralwidget);
        txtbraille->setObjectName("txtbraille");
        txtbraille->setGeometry(QRect(380, 360, 441, 231));
        txtbraille->setReadOnly(true);
        file = new QPushButton(centralwidget);
        file->setObjectName("file");
        file->setGeometry(QRect(70, 220, 81, 71));
        convert = new QPushButton(centralwidget);
        convert->setObjectName("convert");
        convert->setGeometry(QRect(220, 220, 81, 71));
        Imprimante->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Imprimante);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 864, 22));
        Imprimante->setMenuBar(menubar);
        statusbar = new QStatusBar(Imprimante);
        statusbar->setObjectName("statusbar");
        Imprimante->setStatusBar(statusbar);

        retranslateUi(Imprimante);

        QMetaObject::connectSlotsByName(Imprimante);
    } // setupUi

    void retranslateUi(QMainWindow *Imprimante)
    {
        Imprimante->setWindowTitle(QCoreApplication::translate("Imprimante", "Imprimante", nullptr));
        file->setText(QCoreApplication::translate("Imprimante", "Fichier", nullptr));
        convert->setText(QCoreApplication::translate("Imprimante", "Convert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Imprimante: public Ui_Imprimante {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPRIMANTE_H
