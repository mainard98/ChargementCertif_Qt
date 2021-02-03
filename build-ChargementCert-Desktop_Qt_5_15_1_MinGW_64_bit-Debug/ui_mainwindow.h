/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *LabelChoix;
    QPushButton *BtnParcourir;
    QSpacerItem *horizontalSpacer;
    QPushButton *BtnEnvoyer;
    QLineEdit *lineEdit;
    QPushButton *BtnAnnuler;
    QLabel *LabelTitre;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(455, 416);
        MainWindow->setMaximumSize(QSize(455, 416));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 199, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 2);

        LabelChoix = new QLabel(centralwidget);
        LabelChoix->setObjectName(QString::fromUtf8("LabelChoix"));

        gridLayout->addWidget(LabelChoix, 3, 0, 1, 1);

        BtnParcourir = new QPushButton(centralwidget);
        BtnParcourir->setObjectName(QString::fromUtf8("BtnParcourir"));

        gridLayout->addWidget(BtnParcourir, 4, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 6, 0, 1, 1);

        BtnEnvoyer = new QPushButton(centralwidget);
        BtnEnvoyer->setObjectName(QString::fromUtf8("BtnEnvoyer"));

        gridLayout->addWidget(BtnEnvoyer, 6, 1, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setReadOnly(true);

        gridLayout->addWidget(lineEdit, 4, 0, 1, 2);

        BtnAnnuler = new QPushButton(centralwidget);
        BtnAnnuler->setObjectName(QString::fromUtf8("BtnAnnuler"));

        gridLayout->addWidget(BtnAnnuler, 6, 2, 1, 1);

        LabelTitre = new QLabel(centralwidget);
        LabelTitre->setObjectName(QString::fromUtf8("LabelTitre"));
        LabelTitre->setStyleSheet(QString::fromUtf8("font: 14pt \"MS Shell Dlg 2\";"));
        LabelTitre->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(LabelTitre, 1, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 78, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 2);

        verticalSpacer_2 = new QSpacerItem(70, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 455, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        LabelChoix->setText(QCoreApplication::translate("MainWindow", "Choix du certificat", nullptr));
        BtnParcourir->setText(QCoreApplication::translate("MainWindow", "Parcourir", nullptr));
        BtnEnvoyer->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        lineEdit->setText(QCoreApplication::translate("MainWindow", "D:/Projet_Reader", nullptr));
        BtnAnnuler->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        LabelTitre->setText(QCoreApplication::translate("MainWindow", "XtreamWave Reader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
