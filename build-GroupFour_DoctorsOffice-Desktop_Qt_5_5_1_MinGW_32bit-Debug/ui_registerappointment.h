/********************************************************************************
** Form generated from reading UI file 'registerappointment.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERAPPOINTMENT_H
#define UI_REGISTERAPPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterAppointment
{
public:
    QWidget *centralwidget;
    QPushButton *registerButton;
    QListView *listView;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterAppointment)
    {
        if (RegisterAppointment->objectName().isEmpty())
            RegisterAppointment->setObjectName(QStringLiteral("RegisterAppointment"));
        RegisterAppointment->resize(800, 600);
        centralwidget = new QWidget(RegisterAppointment);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(639, 500, 101, 31));
        listView = new QListView(centralwidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(50, 170, 256, 381));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(false);
        lineEdit->setGeometry(QRect(110, 40, 113, 21));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(110, 70, 113, 21));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 40, 47, 13));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 70, 47, 13));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 150, 47, 13));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(191, 140, 111, 22));
        RegisterAppointment->setCentralWidget(centralwidget);
        menubar = new QMenuBar(RegisterAppointment);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        RegisterAppointment->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterAppointment);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        RegisterAppointment->setStatusBar(statusbar);

        retranslateUi(RegisterAppointment);

        QMetaObject::connectSlotsByName(RegisterAppointment);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterAppointment)
    {
        RegisterAppointment->setWindowTitle(QApplication::translate("RegisterAppointment", "MainWindow", 0));
        registerButton->setText(QApplication::translate("RegisterAppointment", "Confirm", 0));
        label->setText(QApplication::translate("RegisterAppointment", "TextLabel", 0));
        label_2->setText(QApplication::translate("RegisterAppointment", "TextLabel", 0));
        label_3->setText(QApplication::translate("RegisterAppointment", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterAppointment: public Ui_RegisterAppointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERAPPOINTMENT_H
