/********************************************************************************
** Form generated from reading UI file 'addpatientdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPATIENTDIALOG_H
#define UI_ADDPATIENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPatientDialog
{
public:
    QDialogButtonBox *add_patient_buttonBox;
    QLabel *social_number_label;
    QLabel *first_name_label;
    QLabel *last_name_label;
    QLabel *phone_label;
    QLabel *doctor_label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;

    void setupUi(QDialog *AddPatientDialog)
    {
        if (AddPatientDialog->objectName().isEmpty())
            AddPatientDialog->setObjectName(QStringLiteral("AddPatientDialog"));
        AddPatientDialog->resize(400, 300);
        add_patient_buttonBox = new QDialogButtonBox(AddPatientDialog);
        add_patient_buttonBox->setObjectName(QStringLiteral("add_patient_buttonBox"));
        add_patient_buttonBox->setGeometry(QRect(30, 240, 341, 32));
        add_patient_buttonBox->setOrientation(Qt::Horizontal);
        add_patient_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        social_number_label = new QLabel(AddPatientDialog);
        social_number_label->setObjectName(QStringLiteral("social_number_label"));
        social_number_label->setGeometry(QRect(50, 30, 81, 16));
        first_name_label = new QLabel(AddPatientDialog);
        first_name_label->setObjectName(QStringLiteral("first_name_label"));
        first_name_label->setGeometry(QRect(50, 60, 71, 16));
        last_name_label = new QLabel(AddPatientDialog);
        last_name_label->setObjectName(QStringLiteral("last_name_label"));
        last_name_label->setGeometry(QRect(50, 90, 71, 16));
        phone_label = new QLabel(AddPatientDialog);
        phone_label->setObjectName(QStringLiteral("phone_label"));
        phone_label->setGeometry(QRect(50, 120, 81, 16));
        doctor_label = new QLabel(AddPatientDialog);
        doctor_label->setObjectName(QStringLiteral("doctor_label"));
        doctor_label->setGeometry(QRect(50, 150, 51, 16));
        comboBox = new QComboBox(AddPatientDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(150, 150, 72, 22));
        lineEdit = new QLineEdit(AddPatientDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 120, 113, 21));
        lineEdit_2 = new QLineEdit(AddPatientDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 90, 113, 21));
        lineEdit_3 = new QLineEdit(AddPatientDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 60, 113, 21));
        lineEdit_4 = new QLineEdit(AddPatientDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(150, 30, 113, 21));

        retranslateUi(AddPatientDialog);
        QObject::connect(add_patient_buttonBox, SIGNAL(accepted()), AddPatientDialog, SLOT(accept()));
        QObject::connect(add_patient_buttonBox, SIGNAL(rejected()), AddPatientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPatientDialog)
    {
        AddPatientDialog->setWindowTitle(QApplication::translate("AddPatientDialog", "Dialog", 0));
        social_number_label->setText(QApplication::translate("AddPatientDialog", "Social Number:", 0));
        first_name_label->setText(QApplication::translate("AddPatientDialog", "First Name:", 0));
        last_name_label->setText(QApplication::translate("AddPatientDialog", "LastName:", 0));
        phone_label->setText(QApplication::translate("AddPatientDialog", "Phone Number:", 0));
        doctor_label->setText(QApplication::translate("AddPatientDialog", "Doctor:", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPatientDialog: public Ui_AddPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDIALOG_H
