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
    ui->edit_PatientName->setText(name);
}

void PatientPage::setDoctorID(int doctorID)
{
    this->doctor_id_ = { doctorID };
}

void PatientPage::setPatientID(int patient_id)
{
    this->patient_id_ = { patient_id };
}

void PatientPage::setDoctorName(QString doctorName)
{
    ui->edit_DoctorsName->setText(doctorName);
}

void PatientPage::setPhoneNumber(int phoneNumber)
{
    ui->edit_PhoneNumber->setText(QString::number(phoneNumber));
}

void PatientPage::setSocialNumber(long long socialNumber)
{
    ui->edit_SocialNumber->setText(QString::number(socialNumber));
}

void PatientPage::on_pushButton_clicked()
{
    add_appointment = new AddAppointmentDialog(this);
    add_appointment->set_patientId(this->patient_id_);
    add_appointment->set_patientName(ui->edit_PatientName->text());
    add_appointment->set_patient_social_number(ui->edit_SocialNumber->text());
    add_appointment->set_doctorName(ui->edit_DoctorsName->text());
    add_appointment->set_doctorId(this->doctor_id_);

    Doctor *doctor;

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        for(unsigned int i = 0; i < db.get_doctors()->size(); i++) {
            if(db.get_doctors()->at(i).get_employee_number() == doctor_id_) {
                QString firstname = db.get_doctors()->at(i).get_first_name();
                QString lastname = db.get_doctors()->at(i).get_last_name();
                int phoneNr = db.get_doctors()->at(i).get_phone_number();
                int employeeNr = db.get_doctors()->at(i).get_employee_number();
                doctor = new Doctor(firstname, lastname, phoneNr, employeeNr);
                add_appointment->set_time_vector(doctor->get_vector_time());
                add_appointment->set_listTime(doctor->get_vector_time());
            }
        }
    }

    this->close();
    add_appointment->show();
}

void PatientPage::on_pushButton_2_clicked()
{
    this->close();
}

void PatientPage::on_open_patient_history_clicked()
{
    patient_history = new PatientHistory(this);
    patient_history->set_patient_name(ui->edit_PatientName->text());
    vector<Appointment> *v_appointments_;
    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        v_appointments_ = new vector<Appointment>(*db.get_single_patients_appointments(this->patient_id_));
    }

    patient_history->copy_appointment_vector(v_appointments_);
    patient_history->show();
}
