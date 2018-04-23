#include "widget.h"
#include "ui_widget.h"
#include "doctor.h"
#include <iostream>
//ikke disse
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>


using namespace std;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QDir dir(GLOBAL_CONST_app_data_path);
    if (!dir.exists())
        dir.mkpath(GLOBAL_CONST_app_data_path);
    if (!dir.exists("SQLite"))
        dir.mkdir("SQLite");

    static const QString doctors_table { "doctors" };
    static const QString patients_table { "patients" };
    static const QString appointments_table { "appointments" };

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        db.create_table(doctors_table);
        db.create_table(patients_table);
        db.create_table(appointments_table);
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }

    doctors = new vector<Doctor>(*db.get_doctors());
    patients = new vector<Patient>(*db.get_patients());
    appointments = new vector<Appointment>(*db.get_appointments());

    for(unsigned int i = 0; i < doctors->size(); i++)
    {
        ui->listWidget_Doctors->addItem(BuildDoctorNamespace(&doctors->at(i)).c_str());
    }

    for(unsigned int i = 0; i < patients->size(); i++)
    {
        ui->listWidget_Patients->addItem(BuildPatientNamespace(&patients->at(i)).c_str());
    }

    ui->button_SelectDoctor->setEnabled(false);
    ui->button_SelectPatient->setEnabled(false);
    ui->button_SelectAppointment->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::filter_doctors(QString filter_string)
{
  hide_all_doctors();
  QList<QListWidgetItem*> matches;
  if(filter_string.toLongLong())
  {
      for (unsigned int i = 0; i < doctors->size(); i++)
      {
          if (to_string(doctors->at(i).get_employee_number()).find(filter_string.toLocal8Bit().constData()) != string::npos)
          {
              matches.append(ui->listWidget_Doctors->findItems(doctors->at(i).get_first_name() + " " + doctors->at(i).get_last_name(), Qt::MatchFlag::MatchContains));
          }
      }
  }
  else
  {
      matches.append(ui->listWidget_Doctors->findItems(filter_string, Qt::MatchFlag::MatchContains));
  }
  for(QListWidgetItem* item : matches)
    item->setHidden(false);
}

void Widget::hide_all_doctors()
{
  for(int row(0); row < ui->listWidget_Doctors->count(); row++ )
    ui->listWidget_Doctors->item(row)->setHidden(true);
}

void Widget::filter_patients(QString filter_string)
{
  hide_all_patients();
  QList<QListWidgetItem*> matches;
  if(filter_string.toLongLong())
  {
      for (unsigned int i = 0; i < patients->size(); i++)
      {
          if (to_string(patients->at(i).getSocialNumber()).find(filter_string.toLocal8Bit().constData()) != string::npos)
          {
              matches.append(ui->listWidget_Patients->findItems(patients->at(i).get_first_name() + " " + patients->at(i).get_last_name(), Qt::MatchFlag::MatchContains));
          }
      }
  }
  else
  {
      matches.append(ui->listWidget_Patients->findItems(filter_string, Qt::MatchFlag::MatchContains));
  }
  for(QListWidgetItem* item : matches)
    item->setHidden(false);
}

void Widget::hide_all_patients()
{
  for(int row(0); row < ui->listWidget_Patients->count(); row++ )
    ui->listWidget_Patients->item(row)->setHidden(true);
}

static string BuildDoctorNamespace(Doctor *doctor)
{
    string doctorInfo;
    ostringstream bodyStream;
    bodyStream << doctor->get_first_name().toStdString() << " " << doctor->get_last_name().toStdString();
    doctorInfo = bodyStream.str();
    return doctorInfo;
}

static string BuildPatientNamespace(Patient *patient)
{
    string patientInfo;
    ostringstream bodyStream;
    bodyStream << patient->get_first_name().toStdString() << " " << patient->get_last_name().toStdString();
    patientInfo = bodyStream.str();
    return patientInfo;
}

static string BuildAppointmentNamespace(Appointment *appointment)
{
    string appointmentInfo;
    ostringstream bodyStream;
    bodyStream << appointment->get_appointment_time().toStdString();
    appointmentInfo = bodyStream.str();
    return appointmentInfo;
}

void Widget::on_button_SelectDoctor_clicked()
{

    doctorPage = new DoctorPage(this);

    string fullName = BuildDoctorNamespace(&doctors->at(ui->listWidget_Doctors->currentRow())).c_str();
    int phoneNumber = doctors->at(ui->listWidget_Doctors->currentRow()).get_phone_number();
    int employeeNumber = doctors->at(ui->listWidget_Doctors->currentRow()).get_employee_number();

    doctorPage->setFullName(fullName.c_str());
    doctorPage->setPhoneNumber(phoneNumber);
    doctorPage->setEmployeeNumber(employeeNumber);

    doctorPage->show();
}

void Widget::on_button_SelectPatient_clicked()
{
    patientPage = new PatientPage(this);

    string fullName = BuildPatientNamespace(&patients->at(ui->listWidget_Patients->currentRow())).c_str();
    int doctorID = patients->at(ui->listWidget_Patients->currentRow()).getDoctorID();
    string doctorName;
    for(unsigned int i = 0; i < doctors->size(); i++)
    {
        if (doctors->at(i).get_employee_number() == doctorID)
        {
            doctorName = BuildDoctorNamespace(&doctors->at(i)).c_str();
        }
    }
    int patient_id = patients->at(ui->listWidget_Patients->currentRow()).getPatientId();
    qDebug() << "PASIENT ID: " << patient_id;
    int phoneNumber = patients->at(ui->listWidget_Patients->currentRow()).get_phone_number();
    long long socialNumber = patients->at(ui->listWidget_Patients->currentRow()).getSocialNumber();

    patientPage->setFullName(fullName.c_str());
    patientPage->setDoctorID(doctorID);
    patientPage->setPatientID(patient_id);
    patientPage->setDoctorName(doctorName.c_str());
    patientPage->setPhoneNumber(phoneNumber);
    patientPage->setSocialNumber(socialNumber);
    patientPage->show();
}

void Widget::on_button_SelectAppointment_clicked()
{
    add_appointment_note_dialog_ = new AddAppointmentNoteDialog(this);

    int doctorId = doctors->at(ui->listWidget_Doctors->currentRow()).get_employee_number();
    QString appointmentTime = appointments->at(ui->listWidget_DoctorTime->currentRow()).get_appointment_time();
    int patientId = appointments->at(ui->listWidget_DoctorTime->currentRow()).get_patient_id();
    qDebug() << patientId;
    add_appointment_note_dialog_->setPatientInfo(patientId);
    add_appointment_note_dialog_->setDoctorInfo(doctorId);
    add_appointment_note_dialog_->setAppointmentTime(appointmentTime);
    add_appointment_note_dialog_->show();
}


void Widget::on_listWidget_Doctors_itemClicked(QListWidgetItem *item)
{
    ui->button_SelectDoctor->setEnabled(true);
    int doctorId = doctors->at(ui->listWidget_Doctors->currentRow()).get_employee_number();
    list_doctor_time(doctorId);
}

void Widget::on_listWidget_Patients_itemClicked(QListWidgetItem *item)
{
    ui->button_SelectPatient->setEnabled(true);
}

void Widget::on_listWidget_DoctorTime_itemClicked(QListWidgetItem *item)
{
    ui->button_SelectAppointment->setEnabled(true);
    int patientId = appointments->at(ui->listWidget_DoctorTime->currentRow()).get_patient_id();
    qDebug() << "patientID" << patientId;
}

void Widget::on_button_AddPatient_clicked()
{
    add_patient_dialog_ = new AddPatientDialog(this);
    connect(add_patient_dialog_, SIGNAL (accept_patient_button_clicked()), this, SLOT (refresh_lists()));
    add_patient_dialog_->show();
}

void Widget::on_button_AddDoctor_clicked()
{
    add_doctor_dialog_ = new AddDoctorDialog(this);
    connect(add_doctor_dialog_, SIGNAL (accept_doctor_button_clicked()), this, SLOT (refresh_lists()));
    add_doctor_dialog_->show();
}

void Widget::refresh_lists()
{
    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        patients = new vector<Patient>(*db.get_patients());
        doctors = new vector<Doctor>(*db.get_doctors());
        ui->listWidget_Patients->clear();
        ui->listWidget_Doctors->clear();
        for(unsigned int i = 0; i < patients->size(); i++)
        {
            ui->listWidget_Patients->addItem(BuildPatientNamespace(&patients->at(i)).c_str());
        }
        for(unsigned int i = 0; i < doctors->size(); i++)
        {
            ui->listWidget_Doctors->addItem(BuildDoctorNamespace(&doctors->at(i)).c_str());
        }
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }
}

void Widget::on_filter_doctor_edit_textChanged(const QString &arg1)
{
    filter_doctors(arg1);
}

void Widget::on_filter_patient_edit_textChanged(const QString &arg1)
{
    filter_patients(arg1);
}

void Widget::list_doctor_time(int doctorId)
{
    DbHelper db(GLOBAL_CONST_db_path);

    ui->listWidget_DoctorTime->clear();

    vector<Patient> *patients = new vector<Patient>(*db.get_patients());

    vector<Appointment> *appointments = new vector<Appointment>(*db.get_appointments());

    for(unsigned int i=0; i < patients->size(); i++)
    {
        if(patients->at(i).getDoctorID() == doctorId)
        {
            int patient_id = patients->at(i).getPatientId();
            QString patientsSocial = QString::number(patients->at(i).getSocialNumber());
            QString patientsFirstName = patients->at(i).get_first_name();
            for(unsigned int j = 0; j < appointments->size(); j++)
            {

                if(appointments->at(j).get_patient_id() == patient_id)
                {

                    QString date = appointments->at(j).get_appointment_date();
                    QString time = appointments->at(j).get_appointment_time();
                    QString stringBinder = date + " : " + time + " - " + patientsFirstName + " : " + patientsSocial;
                    ui->listWidget_DoctorTime->addItem(stringBinder);
                }
            }
        }
    }
}
