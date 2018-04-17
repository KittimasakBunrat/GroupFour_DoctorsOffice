/********************************************************************************
** Form generated from reading UI file 'adddoctordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDOCTORDIALOG_H
#define UI_ADDDOCTORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddDoctorDialog
{
public:
    QLabel *phone_number_doctor_label;
    QLabel *social_number_doctor_label;
    QLabel *last_name_doctor_label;
    QLineEdit *phone_number_doctor_edit;
    QLabel *first_name_doctor_label;
    QDialogButtonBox *add_doctor_buttonBox;
    QLineEdit *first_name_doctor_edit;
    QLineEdit *last_name_doctor_edit;
    QLineEdit *social_number_doctor_edit;

    void setupUi(QDialog *AddDoctorDialog)
    {
        if (AddDoctorDialog->objectName().isEmpty())
            AddDoctorDialog->setObjectName(QStringLiteral("AddDoctorDialog"));
        AddDoctorDialog->resize(400, 300);
        phone_number_doctor_label = new QLabel(AddDoctorDialog);
        phone_number_doctor_label->setObjectName(QStringLiteral("phone_number_doctor_label"));
        phone_number_doctor_label->setGeometry(QRect(80, 140, 81, 16));
        social_number_doctor_label = new QLabel(AddDoctorDialog);
        social_number_doctor_label->setObjectName(QStringLiteral("social_number_doctor_label"));
        social_number_doctor_label->setGeometry(QRect(80, 50, 81, 16));
        last_name_doctor_label = new QLabel(AddDoctorDialog);
        last_name_doctor_label->setObjectName(QStringLiteral("last_name_doctor_label"));
        last_name_doctor_label->setGeometry(QRect(80, 110, 81, 16));
        phone_number_doctor_edit = new QLineEdit(AddDoctorDialog);
        phone_number_doctor_edit->setObjectName(QStringLiteral("phone_number_doctor_edit"));
        phone_number_doctor_edit->setGeometry(QRect(180, 140, 113, 21));
        first_name_doctor_label = new QLabel(AddDoctorDialog);
        first_name_doctor_label->setObjectName(QStringLiteral("first_name_doctor_label"));
        first_name_doctor_label->setGeometry(QRect(80, 80, 71, 16));
        add_doctor_buttonBox = new QDialogButtonBox(AddDoctorDialog);
        add_doctor_buttonBox->setObjectName(QStringLiteral("add_doctor_buttonBox"));
        add_doctor_buttonBox->setGeometry(QRect(30, 240, 341, 32));
        add_doctor_buttonBox->setOrientation(Qt::Horizontal);
        add_doctor_buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        first_name_doctor_edit = new QLineEdit(AddDoctorDialog);
        first_name_doctor_edit->setObjectName(QStringLiteral("first_name_doctor_edit"));
        first_name_doctor_edit->setGeometry(QRect(180, 50, 113, 21));
        last_name_doctor_edit = new QLineEdit(AddDoctorDialog);
        last_name_doctor_edit->setObjectName(QStringLiteral("last_name_doctor_edit"));
        last_name_doctor_edit->setGeometry(QRect(180, 80, 113, 21));
        social_number_doctor_edit = new QLineEdit(AddDoctorDialog);
        social_number_doctor_edit->setObjectName(QStringLiteral("social_number_doctor_edit"));
        social_number_doctor_edit->setGeometry(QRect(180, 110, 113, 21));

        retranslateUi(AddDoctorDialog);

        QMetaObject::connectSlotsByName(AddDoctorDialog);
    } // setupUi

    void retranslateUi(QDialog *AddDoctorDialog)
    {
        AddDoctorDialog->setWindowTitle(QApplication::translate("AddDoctorDialog", "Dialog", nullptr));
        phone_number_doctor_label->setText(QApplication::translate("AddDoctorDialog", "Phone Number:", nullptr));
        social_number_doctor_label->setText(QApplication::translate("AddDoctorDialog", "First Name:", nullptr));
        last_name_doctor_label->setText(QApplication::translate("AddDoctorDialog", "Social Number:", nullptr));
        first_name_doctor_label->setText(QApplication::translate("AddDoctorDialog", "Last Name:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDoctorDialog: public Ui_AddDoctorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDOCTORDIALOG_H
