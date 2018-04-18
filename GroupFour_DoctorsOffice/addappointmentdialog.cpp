#include "addappointmentdialog.h"
#include "ui_addappointmentdialog.h"

AddAppointmentDialog::AddAppointmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppointmentDialog)
{
    ui->setupUi(this);
}

AddAppointmentDialog::~AddAppointmentDialog()
{
    delete ui;
}

void AddAppointmentDialog::set_patientId(int id)
{
    ui->patientId->setText(QString::number(id));
}

void AddAppointmentDialog::set_patientName(QString name)
{
    ui->patientName->setText(name);
}
