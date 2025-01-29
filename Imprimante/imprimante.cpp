#include "imprimante.h"
#include "ui_imprimante.h"
#include <QFileDialog>
#include <QDebug>
#include <QChar>
#include <QByteArray>

Imprimante::Imprimante(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Imprimante)
{
    ui->setupUi(this);
    tout = QString();

    for (const QSerialPortInfo &portinfor : QSerialPortInfo::availablePorts())
    {
        qDebug() << "Port Name : " << portinfor.portName();
        qDebug() << "Port Location : " << portinfor.systemLocation();
        qDebug() << "Port Description : " << portinfor.description();

        desc = portinfor.description();

        if (desc == "Arduino Uno")
        {
            port = portinfor.portName();
        }

    }





    COMPORT = new QSerialPort();
    COMPORT->setPortName(port);
    COMPORT->setBaudRate(QSerialPort::BaudRate::Baud9600);
    COMPORT->setParity(QSerialPort::Parity::NoParity);
    COMPORT->setDataBits(QSerialPort::DataBits::Data8);
    COMPORT->setStopBits(QSerialPort::StopBits::OneStop);
    COMPORT->setFlowControl(QSerialPort::FlowControl::NoFlowControl);
    COMPORT->open(QIODevice::ReadWrite);


    if (COMPORT->isOpen())
    {
        qDebug() << "Serial Port Is Connected to port : " << port;
    }
    else
    {
        qDebug() << "Serial Port Is Not Connected";
        qDebug() << COMPORT->error();
    }


}

Imprimante::~Imprimante()
{
    delete ui;
}

QString fileName;

void Imprimante::on_file_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
    tr("Open Txt"), "U:/Documents/", tr("Text files (*.txt)"));

    ui->acces->setText(fileName);


    QFile fichier(fileName);
    fichier.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&fichier);

    tout = flux.readAll();
    ui->txttout->setText(tout);
}


void Imprimante::on_convert_clicked()
{
    caractere.clear();
    caractere2.clear();
    push.clear();

    infocase = ui->txttout->toPlainText();
    for(int i = 0; i < infocase.length(); i++)
    {
        //https://fr.wikipedia.org/wiki/Table_des_caract%C3%A8res_Unicode_(0000-0FFF)
        switch(infocase[i].unicode())
        {

            //alphabet minuscule
            case 'a':
                caractere.append("00100000");
                push.append(0b00100000);
                break;
            case 'b':
                caractere.append("00101000");
                push.append(0b00101000);
                break;
            case 'c':
                caractere.append("00110000");
                push.append(0b00110000);
                break;
            case 'd':
                caractere.append("00110100");
                push.append(0b00110100);
                break;
            case 'e':
                caractere.append("00100100");
                push.append(0b00100100);
                break;
            case 'f':
                caractere.append("00111000");
                push.append(0b00111000);
                break;
            case 'g':
                caractere.append("00111100");
                push.append(0b00111100);
                break;
            case 'h':
                caractere.append("00101100");
                push.append(0b00101100);
                break;
            case 'i':
                caractere.append("00011000");
                push.append(0b00011000);
                break;
            case 'j':
                caractere.append("00011100");
                push.append(0b00011100);
                break;
            case 'k':
                caractere.append("00100010");
                push.append(0b00100010);
                break;
            case 'l':
                caractere.append("00101010");
                push.append(0b00101010);
                break;
            case 'm':
                caractere.append("00110010");
                push.append(0b00110010);
                break;
            case 'n':
                caractere.append("00110110");
                push.append(0b00110110);
                break;
            case 'o':
                caractere.append("00100110");
                push.append(0b00100110);
                break;
            case 'p':
                caractere.append("00111010");
                push.append(0b00111010);
                break;
            case 'q':
                caractere.append("00111110");
                push.append(0b00111110);
                break;
            case 'r':
                caractere.append("00101110");
                push.append(0b00101110);
                break;
            case 's':
                caractere.append("00011010");
                push.append(0b00011010);
                break;
            case 't':
                caractere.append("00011110");
                push.append(0b00011110);
                break;
            case 'u':
                caractere.append("00100011");
                push.append(0b00100011);
                break;
            case 'v':
                caractere.append("00101011");
                push.append(0b00101011);
                break;
            case 'w':
                caractere.append("00011101");
                push.append(0b00011101);
                break;
            case 'x':
                caractere.append("00110011");
                push.append(0b00110011);
                break;
            case 'y':
                caractere.append("00110111");
                push.append(0b00110111);
                break;
            case 'z':
                caractere.append("00100111");
                push.append(0b00100111);
                break;




                //alphabet Majuscule
            case 'A':
                caractere.append("0000000100100000");
                push.append(0b00000001);
                push.append(0b00100000);
                break;
            case 'B':
                caractere.append("0000000100101000");
                push.append(0b00000001);
                push.append(0b00101000);
                break;
            case 'C':
                caractere.append("0000000100110000");
                push.append(0b00000001);
                push.append(0b00110000);
                break;
            case 'D':
                caractere.append("0000000100110100");
                push.append(0b00000001);
                push.append(0b00110100);
                break;
            case 'E':
                caractere.append("0000000100100100");
                push.append(0b00000001);
                push.append(0b00100100);
                break;
            case 'F':
                caractere.append("0000000100111000");
                push.append(0b00000001);
                push.append(0b00111000);
                break;
            case 'G':
                caractere.append("0000000100111100");
                push.append(0b00000001);
                push.append(0b00111100);
                break;
            case 'H':
                caractere.append("0000000100101100");
                push.append(0b00000001);
                push.append(0b00101100);
                break;
            case 'I':
                caractere.append("0000000100011000");
                push.append(0b00000001);
                push.append(0b00011000);
                break;
            case 'J':
                caractere.append("0000000100011100");
                push.append(0b00000001);
                push.append(0b00011100);
                break;
            case 'K':
                caractere.append("0000000100100010");
                push.append(0b00000001);
                push.append(0b00100010);
                break;
            case 'L':
                caractere.append("0000000100101010");
                push.append(0b00000001);
                push.append(0b00101010);
                break;
            case 'M':
                caractere.append("0000000100110010");
                push.append(0b00000001);
                push.append(0b00110010);
                break;
            case 'N':
                caractere.append("0000000100110110");
                push.append(0b00000001);
                push.append(0b00110110);
                break;
            case 'O':
                caractere.append("0000000100100110");
                push.append(0b00000001);
                push.append(0b00100110);
                break;
            case 'P':
                caractere.append("0000000100111010");
                push.append(0b00000001);
                push.append(0b00111010);
                break;
            case 'Q':
                caractere.append("0000000100111110");
                push.append(0b00000001);
                push.append(0b00111110);
                break;
            case 'R':
                caractere.append("0000000100101110");
                push.append(0b00000001);
                push.append(0b00101110);
                break;
            case 'S':
                caractere.append("0000000100011010");
                push.append(0b00000001);
                push.append(0b00011010);
                break;
            case 'T':
                caractere.append("0000000100011110");
                push.append(0b00000001);
                push.append(0b00011110);
                break;
            case 'U':
                caractere.append("0000000100100011");
                push.append(0b00000001);
                push.append(0b00100011);
                break;
            case 'V':
                caractere.append("0000000100101011");
                push.append(0b00000001);
                push.append(0b00101011);
                break;
            case 'W':
                caractere.append("0000000100011101");
                push.append(0b00000001);
                push.append(0b00011101);
                break;
            case 'X':
                caractere.append("0000000100110011");
                push.append(0b00000001);
                push.append(0b00110011);
                break;
            case 'Y':
                caractere.append("0000000100110111");
                push.append(0b00000001);
                push.append(0b00110111);
                break;
            case 'Z':
                caractere.append("0000000100100111");
                push.append(0b00000001);
                push.append(0b00100111);
                break;






            case 0x00e9: // é
                caractere.append("00111111");
                push.append(0b00111111);
                break;
            case 0x00e8: // è
                caractere.append("00111111");
                push.append(0b10100010);
                break;

            case '\n':
                caractere.append("10100100");
                push.append(0b10100100);
                break;


            default:
                caractere.append(" ");
                push.append('\0');


        }


    }
    ui->txtbraille->setText(caractere);




    for(int i = 0; i < infocase.length(); i++)
    {
        //https://fr.wikipedia.org/wiki/Table_des_caract%C3%A8res_Unicode_(0000-0FFF)
        switch(infocase[i].unicode())
        {

        //alphabet minuscule
        case 'a':
            caractere2.append("⠁");
            break;
        case 'b':
            caractere2.append("⠃");
            break;
        case 'c':
            caractere2.append("⠉");
            break;
        case 'd':
            caractere2.append("⠙");
            break;
        case 'e':
            caractere2.append("⠑");
            break;
        case 'f':
            caractere2.append("⠋");
            break;
        case 'g':
            caractere2.append("⠛");
            break;
        case 'h':
            caractere2.append("⠓");
            break;
        case 'i':
            caractere2.append("⠊");
            break;
        case 'j':
            caractere2.append("⠚");
            break;
        case 'k':
            caractere2.append("⠅");
            break;
        case 'l':
            caractere2.append("⠇");
            break;
        case 'm':
            caractere2.append("⠍");
            break;
        case 'n':
            caractere2.append("⠝");
            break;
        case 'o':
            caractere2.append("⠕");
            break;
        case 'p':
            caractere2.append("⠏");
            break;
        case 'q':
            caractere2.append("⠟");
            break;
        case 'r':
            caractere2.append("⠗");
            break;
        case 's':
            caractere2.append("⠎");
            break;
        case 't':
            caractere2.append("⠞");
            break;
        case 'u':
            caractere2.append("⠥");
            break;
        case 'v':
            caractere2.append("⠧");
            break;
        case 'w':
            caractere2.append("⠺");
            break;
        case 'x':
            caractere2.append("⠭");
            break;
        case 'y':
            caractere2.append("⠽");
            break;
        case 'z':
            caractere2.append("⠵");
            break;




            //alphabet Majuscule
        case 'A':
            caractere2.append("⠨⠁");
            break;
        case 'B':
            caractere2.append("⠨⠃");
            break;
        case 'C':
            caractere2.append("⠨⠉");
            break;
        case 'D':
            caractere2.append("⠨⠙");
            break;
        case 'E':
            caractere2.append("⠨⠑");
            break;
        case 'F':
            caractere2.append("⠨⠋");
            break;
        case 'G':
            caractere2.append("⠨⠛");
            break;
        case 'H':
            caractere2.append("⠨⠓");
            break;
        case 'I':
            caractere2.append("⠨⠊");
            break;
        case 'J':
            caractere2.append("⠨⠚");
            break;
        case 'K':
            caractere2.append("⠨⠚");
            break;
        case 'L':
            caractere2.append("⠨⠇");
            break;
        case 'M':
            caractere2.append("⠨⠍");
            break;
        case 'N':
            caractere2.append("⠨⠝");
            break;
        case 'O':
            caractere2.append("⠨⠕");
            break;
        case 'P':
            caractere2.append("⠨⠏");
            break;
        case 'Q':
            caractere2.append("⠨⠟");
            break;
        case 'R':
            caractere2.append("⠨⠗");
            break;
        case 'S':
            caractere2.append("⠨⠎");
            break;
        case 'T':
            caractere2.append("⠨⠞");
            break;
        case 'U':
            caractere2.append("⠨⠥");
            break;
        case 'V':
            caractere2.append("⠨⠧");
            break;
        case 'W':
            caractere2.append("⠨⠺");
            break;
        case 'X':
            caractere2.append("⠨⠭");
            break;
        case 'Y':
            caractere2.append("⠨⠽");
            break;
        case 'Z':
            caractere2.append("⠨⠵");
            break;






        case 0x00e9: // é
            caractere2.append("⠿");
            break;
        case 0x00e8: // è
            caractere2.append("⠮");
            break;

        default:
            caractere2.append(" ");

        }


    }
    ui->txtcaracbraille->setText(caractere2);
}


void Imprimante::on_envoie_clicked()
{
    //https://www.youtube.com/watch?v=bkyhHt_gHmI&list=PLh0cogPqXcJNfpVO7pDQkMppS7Nj6XpTx


    if (COMPORT->isOpen())
    {
        push.append(0b10100010);
        COMPORT->write(push);
    }


}
