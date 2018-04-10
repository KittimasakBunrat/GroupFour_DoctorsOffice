#include "widget.h"
#include "ui_widget.h"
#include "doctor.h"
#include <iostream>
//flytt disse til header
#include <QtGui>
#include <QtCore>
#include <string>
#include <sstream>

using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    Doctor *doctor1 = new Doctor("Kittimasak1", "Bunrat1", 1112, 12345678, 35463);
    Doctor *doctor2 = new Doctor("Kittimasak2", "Bunrat2", 1113, 12345678, 35464);
    Doctor *doctor3 = new Doctor("Kittimasak3", "Bunrat3", 1113, 12345678, 35465);
    Doctor *doctor4 = new Doctor("Kittimasak4", "Bunrat4", 1114, 12345678, 35466);
    Doctor *doctor5 = new Doctor("Kittimasak5", "Bunrat5", 1115, 12345678, 35467);
    Doctor *doctor6 = new Doctor("Kittimasak6", "Bunrat6", 1116, 12345678, 35468);
    Doctor *doctor7 = new Doctor("Kittimasak7", "Bunrat7", 1117, 12345678, 354699);
    Doctor *doctor8 = new Doctor("Kittimasak8", "Bunrat8", 1118, 12345678, 35467655);

    doctors = new vector<Doctor>();

    doctors->push_back(*doctor1);
    doctors->push_back(*doctor2);
    doctors->push_back(*doctor3);
    doctors->push_back(*doctor4);
    doctors->push_back(*doctor5);
    doctors->push_back(*doctor6);
    doctors->push_back(*doctor7);
    doctors->push_back(*doctor8);

    for(int i = 0; i < doctors->size(); i++)
    {
        ui->listWidget_Doctors->addItem(BuildDoctorNamespace(&doctors->at(i)).c_str());
    }

    ui->button_SelectDoctor->setEnabled(false);

}

Widget::~Widget()
{
    delete doctors;
    delete ui;
}

static string BuildDoctorNamespace(Doctor *doctor)
{
    string doctorInfo;
    ostringstream bodyStream;
    bodyStream << doctor->get_first_name() << " " << doctor->get_last_name() << " " << doctor->get_employee_number();
    doctorInfo = bodyStream.str();
    return doctorInfo;
}



void Widget::on_listWidget_Doctors_itemActivated(QListWidgetItem *item)
{
    ui->button_SelectDoctor->setEnabled(true);
}
