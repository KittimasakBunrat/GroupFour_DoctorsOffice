/********************************************************************************
** Form generated from reading UI file 'registerappointment.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERAPPOINTMENT_H
#define UI_REGISTERAPPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterAppointment
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterAppointment)
    {
        if (RegisterAppointment->objectName().isEmpty())
            RegisterAppointment->setObjectName(QStringLiteral("RegisterAppointment"));
        RegisterAppointment->resize(800, 600);
        centralwidget = new QWidget(RegisterAppointment);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        RegisterAppointment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterAppointment);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        RegisterAppointment->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterAppointment);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RegisterAppointment->setStatusBar(statusbar);

        retranslateUi(RegisterAppointment);

        QMetaObject::connectSlotsByName(RegisterAppointment);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterAppointment)
    {
        RegisterAppointment->setWindowTitle(QApplication::translate("RegisterAppointment", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterAppointment: public Ui_RegisterAppointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERAPPOINTMENT_H
