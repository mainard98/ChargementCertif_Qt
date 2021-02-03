#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>
#include "Serial.h"
#include "inifile.h"
#include "mycrc.h"
#include <cstdint>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BtnParcourir_clicked();
    void on_BtnAnnuler_clicked();
    void on_BtnEnvoyer_clicked();

private:
    Ui::MainWindow *ui;

    Serial *Uart;
    myCRC *calculCRC;

    QString fichier;
    QString filename = "D:/Projet_Reader";

};
#endif // MAINWINDOW_H
