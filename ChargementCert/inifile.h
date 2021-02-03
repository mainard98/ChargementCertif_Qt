#ifndef INIFILE_H
#define INIFILE_H
#include <QFile>
#include <QDebug>
#include <QSettings>
#include <QApplication>

class iniFile
{

public:

    iniFile();
    int lireformat();
    void lireports(QString *portA, QString *portB);
    void lirevitesse(int *vitesse1, int *vitesse2);
    void liremode(int *mode);
    void getPort(QString *ptFichierConfig);

    void lireAxe(int *minAz, int *maxAz, int *minNo, int *maxNo, int *minEl, int *maxEl);
    void ecrireAxe(int minAz, int maxAz, int minNo, int maxNo, int minEl, int maxEl);

    void lireTCP(QString *ip, quint16 *numPort);

private:

};

#endif // INIFILE_H
