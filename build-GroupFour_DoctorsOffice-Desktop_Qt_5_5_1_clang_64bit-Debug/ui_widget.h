/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QListWidget *listWidget_Doctors;
    QPushButton *button_SelectDoctor;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QListWidget *listWidget_Patients;
    QPushButton *button_SelectPatient;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(606, 400);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 10, 281, 51));
        QFont font;
        font.setFamily(QStringLiteral("Gill Sans"));
        font.setPointSize(36);
        label->setFont(font);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 80, 524, 260));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Gill Sans"));
        font1.setPointSize(24);
        font1.setBold(false);
        font1.setWeight(50);
        label_3->setFont(font1);

        verticalLayout->addWidget(label_3);

        listWidget_Doctors = new QListWidget(widget);
        listWidget_Doctors->setObjectName(QStringLiteral("listWidget_Doctors"));

        verticalLayout->addWidget(listWidget_Doctors);

        button_SelectDoctor = new QPushButton(widget);
        button_SelectDoctor->setObjectName(QStringLiteral("button_SelectDoctor"));

        verticalLayout->addWidget(button_SelectDoctor);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4);

        listWidget_Patients = new QListWidget(widget);
        listWidget_Patients->setObjectName(QStringLiteral("listWidget_Patients"));

        verticalLayout_2->addWidget(listWidget_Patients);

        button_SelectPatient = new QPushButton(widget);
        button_SelectPatient->setObjectName(QStringLiteral("button_SelectPatient"));

        verticalLayout_2->addWidget(button_SelectPatient);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label->setText(QApplication::translate("Widget", "iDoctor Software", 0));
        label_3->setText(QApplication::translate("Widget", "Doctors", 0));
        button_SelectDoctor->setText(QApplication::translate("Widget", "Select Doctor", 0));
        label_4->setText(QApplication::translate("Widget", "Patients", 0));
        button_SelectPatient->setText(QApplication::translate("Widget", "Select Patient", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
