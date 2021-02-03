#include "inifile.h"

iniFile::iniFile()
{




}

int iniFile::lireformat()
{
//    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    return parametres.value("typedefichier/formatfichier").toInt();
}

void iniFile::lireports(QString *portA, QString *portB)
{
//    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    *portA = parametres.value("port/portData").toString();
    *portB = parametres.value("port/portConfig").toString();
}

void iniFile::lirevitesse(int *vitesse1, int *vitesse2)
{
 //   QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    *vitesse1 = parametres.value("vitesse/portData").toInt();
    *vitesse2 = parametres.value("vitesse/portConfig").toInt();
}

void iniFile::liremode(int *mode)
{
//    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    *mode = parametres.value("mode/mode").toInt();
}

void iniFile::lireAxe(int *minAz, int *maxAz, int *minNo, int *maxNo, int *minEl, int *maxEl)
{
//   QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");

    QSettings parametres(nomFichier, QSettings::IniFormat);

    *minAz = parametres.value("axe/minAz").toInt();
    *maxAz = parametres.value("axe/maxAz").toInt();
    *minNo = parametres.value("axe/minNo").toInt();
    *maxNo = parametres.value("axe/maxNo").toInt();
    *minEl = parametres.value("axe/minEl").toInt();
    *maxEl = parametres.value("axe/maxEl").toInt();
}

void iniFile::ecrireAxe(int minAz, int maxAz, int minNo, int maxNo, int minEl, int maxEl)
{
//    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");

    QSettings parametres(nomFichier, QSettings::IniFormat);

    parametres.setValue("axe/minAz",minAz);
    parametres.setValue("axe/maxAz",maxAz);
    parametres.setValue("axe/minNo",minNo);
    parametres.setValue("axe/maxNo",maxNo);
    parametres.setValue("axe/minEl",minEl);
    parametres.setValue("axe/maxEl",maxEl);

}

void iniFile::lireTCP(QString *ip, quint16 *numPort)
{
//    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetRadar_Socket/Demonstrateur_socket/fichierConfig.ini");
    QString nomFichier("fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    *ip = parametres.value("TCP/ip").toString();
    *numPort = parametres.value("TCP/port").toInt();
}

void iniFile::getPort(QString *ptFichierConfig)
{
    QString nomFichier("C:/Users/alexis.mainard/OneDrive - yncréa/Bureau/XtreamWave/ProjetReader/App_ChargementCertif/ChargementCert/fichierConfig.ini");
    QSettings parametres(nomFichier, QSettings::IniFormat);
    *ptFichierConfig = parametres.value("PORT/port1").toString();

    qDebug() << *ptFichierConfig;
}
