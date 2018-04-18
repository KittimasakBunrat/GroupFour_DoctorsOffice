#include "patientpage.h"
#include "ui_patientpage.h"

PatientPage::PatientPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientPage)
{
    ui->setupUi(this);
}

PatientPage::~PatientPage()
{
    delete ui;
}

void PatientPage::setFullName(QString name)
{
    ui->label_PatientName->setText(name);
}

void PatientPage::setDoctorID(int doctorID)
{
    ui->label_DoctorID->setText(QString::number(doctorID));
}

void PatientPage::setPhoneNumber(int phoneNumber)
{
    ui->label_PhoneNumber->setText(QString::number(phoneNumber));
}

void PatientPage::setSocialNumber(int socialNumber)
{
    ui->label_SocialNumber->setText(QString::number(socialNumber));
}

void PatientPage::on_pushButton_clicked()
{
    add_appointment = new AddAppointmentDialog(this);
    add_appointment->set_patientId(ui->label_SocialNumber->text().toInt());
    add_appointment->set_patientName(ui->label_PatientName->text());

    this->close();
    add_appointment->show();
}
