#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Uart = new Serial();

    ui->lineEdit->setText(filename);


    calculCRC = new myCRC();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnParcourir_clicked()
{
    fichier = QFileDialog::getOpenFileName(this,"Choix du certificat",ui->lineEdit->text(),"*.c");

    if(fichier.isEmpty())
    {
        fichier = filename;
        ui->lineEdit->setText(fichier);
    }else
    {
        filename=fichier;
        ui->lineEdit->setText(fichier);
    }
}

void MainWindow::on_BtnAnnuler_clicked()
{
    Uart->close();
    qApp->closeAllWindows();
}

void MainWindow::on_BtnEnvoyer_clicked()
{
  QByteArray dataToSend;
  QString delimiteur("56474B3321");

  if(ui->lineEdit->text().contains(".c"))
    {
        QFile certif(fichier);
        if (!certif.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        qDebug() << "Envoie de" << fichier;

        QByteArray data = certif.readAll();
        data.replace(QByteArray(","), QByteArray(""));
        data.replace(QByteArray("\n"), QByteArray(""));
        data.replace(QByteArray("0x"), QByteArray(""));

//        qDebug() << data.size();

        quint16 crc = 0xFFFF;
//      crc = qChecksum(data,data.size(),Qt::ChecksumItuV41);
//      qDebug() << "crc" << crc;

        crc = calculCRC->crc_init();
//        qDebug() << "init :" << crc;

        crc = calculCRC->crc_update(crc,&data,data.size());
//        qDebug() << "update :" << crc;

        crc = calculCRC->crc_finalize(crc);
//        qDebug() << "finalize :" << crc;

        dataToSend.append(delimiteur); //délimineur
        qDebug() <<"delimiteur :" << delimiteur;

        QString crcHex = QString().number(crc,16);  //crc
        if(crcHex.size() <= 3)
        {
            crcHex.prepend("0");
        }

        QString sizeHex = QString().number(data.size(),16);

        if(sizeHex.size() <= 3)
        {
            sizeHex.prepend("0");
        }

        qDebug() << "size :" << sizeHex;
        dataToSend.append(sizeHex);

        qDebug() << "crc " << crcHex;
        dataToSend.append(crcHex);

        dataToSend.append(data);

        qDebug() << "data to send : " << dataToSend;

        Uart->write(dataToSend);
        certif.close();
  }
  else
  {
        QMessageBox::critical(this, "Certificat non valide", "Veuillez choisir un certificat valide");
  }
}
