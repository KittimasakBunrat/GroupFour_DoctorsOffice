#include "createnewappointment.h"
#include "ui_createnewappointment.h"

CreateNewAppointment::CreateNewAppointment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNewAppointment)
{
    ui->setupUi(this);
}

CreateNewAppointment::~CreateNewAppointment()
{
    delete ui;
}

Patient CreateNewAppointment::getPatient()
{
    return this->patient;
}

Patient CreateNewAppointment::setPatient(Patient *patient)
{
    this->patient = patient;
}
