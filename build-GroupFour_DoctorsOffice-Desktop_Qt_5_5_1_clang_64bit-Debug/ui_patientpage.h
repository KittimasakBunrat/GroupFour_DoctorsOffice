/********************************************************************************
** Form generated from reading UI file 'patientpage.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATIENTPAGE_H
#define UI_PATIENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientPage
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_6;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_PatientName;
    QLabel *label_SocialNumber;
    QLabel *label_PhoneNumber;

    void setupUi(QDialog *PatientPage)
    {
        if (PatientPage->objectName().isEmpty())
            PatientPage->setObjectName(QStringLiteral("PatientPage"));
        PatientPage->resize(400, 300);
        buttonBox = new QDialogButtonBox(PatientPage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_6 = new QLabel(PatientPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 10, 281, 51));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans"));
        font.setPointSize(18);
        label_6->setFont(font);
        widget = new QWidget(PatientPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 70, 291, 111));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font1;
        font1.setFamily(QStringLiteral("Optima"));
        font1.setPointSize(18);
        label_5->setFont(font1);

        verticalLayout->addWidget(label_5);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_PatientName = new QLabel(widget);
        label_PatientName->setObjectName(QStringLiteral("label_PatientName"));

        verticalLayout_2->addWidget(label_PatientName);

        label_SocialNumber = new QLabel(widget);
        label_SocialNumber->setObjectName(QStringLiteral("label_SocialNumber"));

        verticalLayout_2->addWidget(label_SocialNumber);

        label_PhoneNumber = new QLabel(widget);
        label_PhoneNumber->setObjectName(QStringLiteral("label_PhoneNumber"));

        verticalLayout_2->addWidget(label_PhoneNumber);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(PatientPage);
        QObject::connect(buttonBox, SIGNAL(accepted()), PatientPage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PatientPage, SLOT(reject()));

        QMetaObject::connectSlotsByName(PatientPage);
    } // setupUi

    void retranslateUi(QDialog *PatientPage)
    {
        PatientPage->setWindowTitle(QApplication::translate("PatientPage", "Dialog", 0));
        label_6->setText(QApplication::translate("PatientPage", "Information About Patient", 0));
        label_5->setText(QApplication::translate("PatientPage", "Patient Name: ", 0));
        label_4->setText(QApplication::translate("PatientPage", "Social Number: ", 0));
        label_3->setText(QApplication::translate("PatientPage", "Phone Number", 0));
        label_PatientName->setText(QApplication::translate("PatientPage", "PatientName", 0));
        label_SocialNumber->setText(QApplication::translate("PatientPage", "SocialNumber", 0));
        label_PhoneNumber->setText(QApplication::translate("PatientPage", "PhoneNumber", 0));
    } // retranslateUi

};

namespace Ui {
    class PatientPage: public Ui_PatientPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPAGE_H
