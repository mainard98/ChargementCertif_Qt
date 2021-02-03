#ifndef SERIAL_H
#define SERIAL_H
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QIODevice>
#include <QDebug>
#include <QString>
#include <QThread>
#include <QStringList>
#include <QFile>
#include "inifile.h"

class Serial : public QObject
{

    Q_OBJECT

public:

    Serial();
    Serial(QString nomPort, int typeSerial);
    ~Serial();

    bool openSerial(QIODevice::OpenModeFlag pType);
    void startRadar(QByteArrayList texte);
    void close();
    void settingsConfig(int vitesse);
    void settingsLecture(int vitesse);
    void ecrireCMD(int numLigne);
    bool testCommande(QString strCommande);
    void writeStart();
    void writeStop();
    void write(QByteArray tabCertif);
    QByteArray lireTrame();

public slots:

    void serialRead();

signals:
    void dataTrame(QByteArray);



private:

    QSerialPort *m_serial;
    iniFile *fichierConfig;
    QString uart;
    int i = 0, j = 0;
    bool flag = false;
    bool flag2 = false;
    int cptError = 0, mEtape = 0;
    QString mStr;
    QByteArray  mData;
    QString tabCMD[20];
    bool ok;
    QByteArrayList ligneCMD;
    QByteArray lStr, trame;
    int type;
};


#endif // SERIAL_H
