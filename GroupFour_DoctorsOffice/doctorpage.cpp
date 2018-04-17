#include "doctorpage.h"
#include "ui_doctorpage.h"
#include "doctor.h"
#include <string>
#include <iostream>

using namespace std;

DoctorPage::DoctorPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorPage)
{
    ui->setupUi(this);
}

DoctorPage::~DoctorPage()
{
    delete ui;
}

void DoctorPage::setFullName(QString name)
{
    ui->label_DoctorName->setText(name);
}

void DoctorPage::setPhoneNumber(int phoneNumber)
{
    ui->label_PhoneNumber->setText(QString::number(phoneNumber));
}

/*
void DoctorPage::setEmployeeNumber(int employeeNumber)
{
    ui->label_EmployeeNumber->setText(QString::number(employeeNumber));
}
*/
