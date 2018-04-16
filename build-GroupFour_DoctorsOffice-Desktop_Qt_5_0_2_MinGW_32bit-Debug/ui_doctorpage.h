/********************************************************************************
** Form generated from reading UI file 'doctorpage.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOCTORPAGE_H
#define UI_DOCTORPAGE_H

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

class Ui_DoctorPage
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_DoctorName;
    QLabel *label_SocialNumber;
    QLabel *label_PhoneNumber;
    QLabel *label_EmployeeNumber;

    void setupUi(QDialog *DoctorPage)
    {
        if (DoctorPage->objectName().isEmpty())
            DoctorPage->setObjectName(QStringLiteral("DoctorPage"));
        DoctorPage->resize(400, 300);
        buttonBox = new QDialogButtonBox(DoctorPage);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_5 = new QLabel(DoctorPage);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(90, 10, 281, 51));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans"));
        font.setPointSize(18);
        label_5->setFont(font);
        widget = new QWidget(DoctorPage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(50, 80, 286, 110));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Optima"));
        font1.setPointSize(18);
        label->setFont(font1);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_DoctorName = new QLabel(widget);
        label_DoctorName->setObjectName(QStringLiteral("label_DoctorName"));

        verticalLayout_2->addWidget(label_DoctorName);

        label_SocialNumber = new QLabel(widget);
        label_SocialNumber->setObjectName(QStringLiteral("label_SocialNumber"));

        verticalLayout_2->addWidget(label_SocialNumber);

        label_PhoneNumber = new QLabel(widget);
        label_PhoneNumber->setObjectName(QStringLiteral("label_PhoneNumber"));

        verticalLayout_2->addWidget(label_PhoneNumber);

        label_EmployeeNumber = new QLabel(widget);
        label_EmployeeNumber->setObjectName(QStringLiteral("label_EmployeeNumber"));

        verticalLayout_2->addWidget(label_EmployeeNumber);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(DoctorPage);
        QObject::connect(buttonBox, SIGNAL(accepted()), DoctorPage, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DoctorPage, SLOT(reject()));

        QMetaObject::connectSlotsByName(DoctorPage);
    } // setupUi

    void retranslateUi(QDialog *DoctorPage)
    {
        DoctorPage->setWindowTitle(QApplication::translate("DoctorPage", "Dialog", 0));
        label_5->setText(QApplication::translate("DoctorPage", "Information About Doctor", 0));
        label->setText(QApplication::translate("DoctorPage", "Name: ", 0));
        label_2->setText(QApplication::translate("DoctorPage", "Social Number: ", 0));
        label_3->setText(QApplication::translate("DoctorPage", "Phone Number: ", 0));
        label_4->setText(QApplication::translate("DoctorPage", "Employee Number: ", 0));
        label_DoctorName->setText(QApplication::translate("DoctorPage", "DoctorName", 0));
        label_SocialNumber->setText(QApplication::translate("DoctorPage", "Social Number: ", 0));
        label_PhoneNumber->setText(QApplication::translate("DoctorPage", "Phone Number: ", 0));
        label_EmployeeNumber->setText(QApplication::translate("DoctorPage", "Employee Number: ", 0));
    } // retranslateUi

};

namespace Ui {
    class DoctorPage: public Ui_DoctorPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOCTORPAGE_H
