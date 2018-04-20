#include "patientpage.h"
#include "ui_patientpage.h"
#include "dbhelper.h"

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
    add_appointment->set_doctorId(ui->label_DoctorID->text().toInt());

    Doctor *doctor;
    int doctorId = ui->label_DoctorID->text().toInt();

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        for(int i = 0; i < db.get_doctors()->size(); i++) {
            if(db.get_doctors()->at(i).get_employee_number() == doctorId) {
                QString firstname = db.get_doctors()->at(i).get_first_name();
                QString lastname = db.get_doctors()->at(i).get_last_name();
                int phoneNr = db.get_doctors()->at(i).get_phone_number();
                int employeeNr = db.get_doctors()->at(i).get_employee_number();
                doctor = new Doctor(firstname, lastname, phoneNr, employeeNr);
            }
        }
        qDebug() << "Database OK, managed to retrieve a single doctor";
    }
    else
    {
        qDebug() << "Database not connected";
    }

    add_appointment->set_doctorName(doctor->get_first_name());

    for(unsigned int i = 0; i < doctor->get_vector_time()->size(); i++)
    {
        add_appointment->set_listTime(doctor->get_vector_time()->at(i).c_str());

    }


    this->close();
    add_appointment->show();
}

