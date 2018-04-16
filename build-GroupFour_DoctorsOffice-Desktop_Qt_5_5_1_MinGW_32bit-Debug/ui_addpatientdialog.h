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
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AddPatientDialog
{
public:
    QDialogButtonBox *add_patient_buttonBox;

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

        retranslateUi(AddPatientDialog);
        QObject::connect(add_patient_buttonBox, SIGNAL(accepted()), AddPatientDialog, SLOT(accept()));
        QObject::connect(add_patient_buttonBox, SIGNAL(rejected()), AddPatientDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddPatientDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPatientDialog)
    {
        AddPatientDialog->setWindowTitle(QApplication::translate("AddPatientDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPatientDialog: public Ui_AddPatientDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPATIENTDIALOG_H
