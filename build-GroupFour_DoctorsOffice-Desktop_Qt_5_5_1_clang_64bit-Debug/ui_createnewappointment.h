/********************************************************************************
** Form generated from reading UI file 'createnewappointment.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENEWAPPOINTMENT_H
#define UI_CREATENEWAPPOINTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CreateNewAppointment
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateNewAppointment)
    {
        if (CreateNewAppointment->objectName().isEmpty())
            CreateNewAppointment->setObjectName(QStringLiteral("CreateNewAppointment"));
        CreateNewAppointment->resize(400, 300);
        buttonBox = new QDialogButtonBox(CreateNewAppointment);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(CreateNewAppointment);
        QObject::connect(buttonBox, SIGNAL(accepted()), CreateNewAppointment, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CreateNewAppointment, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateNewAppointment);
    } // setupUi

    void retranslateUi(QDialog *CreateNewAppointment)
    {
        CreateNewAppointment->setWindowTitle(QApplication::translate("CreateNewAppointment", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class CreateNewAppointment: public Ui_CreateNewAppointment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENEWAPPOINTMENT_H
