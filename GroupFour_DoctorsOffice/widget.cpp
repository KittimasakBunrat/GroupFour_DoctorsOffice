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

    //temp
    Doctor *doctor1 = new Doctor("Kittimasak1", "Bunrat1", 1112, 12345678, 3546);
    Doctor *doctor2 = new Doctor("Kittimasak2", "Bunrat2", 1113, 12345678, 3546);
    Doctor *doctor3 = new Doctor("Kittimasak3", "Bunrat3", 1113, 12345678, 3546);
    Doctor *doctor4 = new Doctor("Kittimasak4", "Bunrat4", 1114, 12345678, 3546);
    Doctor *doctor5 = new Doctor("Kittimasak5", "Bunrat5", 1115, 12345678, 3546);
    Doctor *doctor6 = new Doctor("Kittimasak6", "Bunrat6", 1116, 12345678, 3546);
    Doctor *doctor7 = new Doctor("Kittimasak7", "Bunrat7", 1117, 12345678, 3546);
    Doctor *doctor8 = new Doctor("Kittimasak8", "Bunrat8", 1118, 12345678, 3546);


    ui->listWidget_Doctors->addItem(buildDoctorNamespace(doctor1).c_str());

}

Widget::~Widget()
{
    delete ui;
}

static string buildDoctorNamespace(Doctor *doctor)
{
    string doctorInfo;

    ostringstream bodyStream;

    bodyStream << doctor->get_first_name() << " " << doctor->get_last_name() << " " << doctor->get_social_number();

    doctorInfo = bodyStream.str();

    return doctorInfo;
}
