#include "Serial.h"
#include "mainwindow.h"
#include "stdio.h"
#include "stdlib.h"
#include <QCoreApplication>
#include <QDir>


Serial::Serial()
{
    m_serial = new QSerialPort;
    m_serial->setPortName("COM3");

    if(!m_serial->setBaudRate(QSerialPort::Baud115200))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setDataBits(QSerialPort::Data8))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setParity(QSerialPort::NoParity))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setStopBits(QSerialPort::OneStop))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setFlowControl(QSerialPort::NoFlowControl))
        qDebug()<<m_serial->errorString();

    if(m_serial->open(QIODevice::ReadWrite))
        qDebug() << "OPEN";
    else
        qDebug() << "NOT OPEN";


//  QObject::connect(m_serial, SIGNAL(readyRead()),this, SLOT(serialRead()));
}

Serial::Serial(QString nomPort, int typeSerial)
{
    m_serial = new QSerialPort;
    m_serial->setPortName(nomPort);
    qDebug() << "Creation du Port :" << nomPort;

    type = typeSerial;

    connect(m_serial,SIGNAL(readyRead()),this,SLOT(serialRead()));
}

Serial::~Serial()
{
    qDebug() << "Destruction";
    m_serial->close();
}

bool Serial::openSerial(QIODevice::OpenModeFlag pType){

    bool y = false;
    if(m_serial->open(pType)){
            qDebug() << "Port bien ouvert.";
            y = true;
        }
        else{
            qDebug() << "Port non ouvert.";
            qDebug() << m_serial->errorString();
        }
    return y;
}

void Serial::serialRead()
{
    if(type == 1)
    {
        lStr = m_serial->readAll();
        mStr = mStr.append(lStr);
//      qDebug() << lStr;

        if (mStr.contains("/>")) {
            mEtape = 1;
        }

        if(mEtape == 1 )
        {
            if(mStr.contains("\n"))
            {
                QString lStrSection = mStr.section("\n",0,0);
//              qDebug() << lStrSection;

                if(testCommande(lStrSection))
                {
                    qDebug() << lStrSection;
                    mStr.remove(0,lStrSection.size() + 1);
                    mEtape = 2;
                }

                if(mEtape == 2)
                {
                    if(mStr.contains("\n\r"))
                    {
                        QString lStrSection2 = mStr.section("\n\r",0,0);
                        qDebug() << lStrSection2;

                        if(lStrSection2.contains("Done"))
                        {
//                          qDebug() << "La commande est bien passée";
                            mStr.remove(0,lStrSection2.size()+2);
                            mEtape = 3;
                        }
                        if(lStrSection2.contains("Debug: Init Calibration Status = 0x1e"))
                        {
                            lStrSection2.clear();
                            mStr.clear();
                            mEtape = 3;
                        }

                        if (mEtape == 3)
                        {

                            if(mStr.contains(">"))
                            {
                                qDebug() << mStr;
                                mStr.clear();
                                lStr.clear();
                                i++;
                                ecrireCMD(i);
                            }
                        }
                        else
                        {
                            qDebug() << "ERREUR A L'ETAPE : " << mEtape;
                        }
                    }
                }
            }
        }
    }
    else
        if(type == 0)
        {
           trame = m_serial->readAll().toHex();
           emit dataTrame(trame);
        }

}

void Serial::startRadar(QByteArrayList texte)
{
    ligneCMD.append(texte);
//  qDebug() << "TEXTE" << ligneCMD;

    for(int i=0;i<ligneCMD.size();i++)
    {
        tabCMD[i] = ligneCMD[i];
//      qDebug() << tabCMD[i];
    }
    ecrireCMD(i);
}

void Serial::close()
{
   qDebug() << "CLOSE";
   m_serial->close();
}

void Serial::settingsConfig(int vitesse)
{
//    qDebug() << vitesse;
    if(!m_serial->setBaudRate(vitesse))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setDataBits(QSerialPort::Data8))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setParity(QSerialPort::NoParity))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setStopBits(QSerialPort::OneStop))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setFlowControl(QSerialPort::NoFlowControl))
        qDebug()<<m_serial->errorString();

//    qDebug() << "settingsConfig";
}

void Serial::settingsLecture(int vitesse)
{
    if(!m_serial->setBaudRate(vitesse))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setDataBits(QSerialPort::Data8))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setParity(QSerialPort::NoParity))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setStopBits(QSerialPort::OneStop))
        qDebug()<<m_serial->errorString();

    if(!m_serial->setFlowControl(QSerialPort::NoFlowControl))
        qDebug()<<m_serial->errorString();

//    qDebug() << "settingsLecture";
}

void Serial::ecrireCMD(int numLigne)
{
//    qDebug() << "ecrire cmd";
//    qDebug() << "num ligne" << numLigne << " " << ligneCMD.size();

    if(numLigne<ligneCMD.size())
    {
//      qDebug() << "j'ecris !";
        m_serial->write(ligneCMD.at(numLigne)+'\n');
    }
}

bool Serial::testCommande(QString strCommande)
{
    for(int i = 0; i<16; i++)
    {
        if(strCommande.contains(tabCMD[i]))
        {
//          qDebug() << "C'est une commande";
            return true;
        }
    }
      return false;
}

void Serial::writeStart()
{
    m_serial->write("sensorStart 0\n");
    mStr.clear();
    lStr.clear();
}

void Serial::writeStop()
{
    m_serial->write("sensorStop\n");
    mStr.clear();
    lStr.clear();
}

void Serial::write(QByteArray tabCertif)
{
    m_serial->write(tabCertif);
}


