/********************************************************************************
** Form generated from reading UI file 'patientpage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatientPage
{
public:
    QLabel *label_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
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
        label_6 = new QLabel(PatientPage);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 10, 281, 51));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans"));
        font.setPointSize(18);
        label_6->setFont(font);
        pushButton = new QPushButton(PatientPage);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(200, 240, 161, 24));
        pushButton_2 = new QPushButton(PatientPage);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 240, 80, 24));
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

        QMetaObject::connectSlotsByName(PatientPage);
    } // setupUi

    void retranslateUi(QDialog *PatientPage)
    {
        PatientPage->setWindowTitle(QApplication::translate("PatientPage", "Dialog", nullptr));
        label_6->setText(QApplication::translate("PatientPage", "Information About Patient", nullptr));
        pushButton->setText(QApplication::translate("PatientPage", "New Appointment", nullptr));
        pushButton_2->setText(QApplication::translate("PatientPage", "Cancel", nullptr));
        label_5->setText(QApplication::translate("PatientPage", "Patient Name: ", nullptr));
        label_4->setText(QApplication::translate("PatientPage", "Social Number: ", nullptr));
        label_3->setText(QApplication::translate("PatientPage", "Phone Number", nullptr));
        label_PatientName->setText(QApplication::translate("PatientPage", "PatientName", nullptr));
        label_SocialNumber->setText(QApplication::translate("PatientPage", "SocialNumber", nullptr));
        label_PhoneNumber->setText(QApplication::translate("PatientPage", "PhoneNumber", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatientPage: public Ui_PatientPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATIENTPAGE_H
