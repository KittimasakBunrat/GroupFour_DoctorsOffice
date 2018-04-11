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

void PatientPage::setSocialNumber(int socialNumber)
{
    ui->label_SocialNumber->setText(QString::number(socialNumber));
}

void PatientPage::setPhoneNumber(int phoneNumber)
{
    ui->label_PhoneNumber->setText(QString::number(phoneNumber));
}
