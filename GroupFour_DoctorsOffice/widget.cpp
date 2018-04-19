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

    qDebug() << "DatabasePath: " << GLOBAL_CONST_app_data_path;

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
        //db.create_new_patient(12321, "Kitti", "Masak", 876, 9);
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }
      
    Doctor *doctor1 = new Doctor("Kittimasak", "Bunrat", 1112, 46937362);
    Doctor *doctor2 = new Doctor("Shohaib", "Muhammad", 1113, 45464847);
    Doctor *doctor3 = new Doctor("Pontus", "Skóld", 1113, 43234565);
    Doctor *doctor4 = new Doctor("Rudi", "Dahle", 1114, 93456543);

    /*
    db.create_new_patient(323,"Bundolf","Kittler", 665577, 442244);
    db.create_new_patient(545,"Rudislav","Captanikoskav",999666,44330);
    db.create_new_doctor(*doctor1);
    */


    doctors = new vector<Doctor>(*db.get_doctors());
    patients = new vector<Patient>(*db.get_patients());

    for(unsigned int i = 0; i < doctors->size(); i++)
    {
        ui->listWidget_Doctors->addItem(BuildDoctorNamespace(&doctors->at(i)).c_str());
    }

    for(unsigned int i = 0; i < patients->size(); i++)
    {
        ui->listWidget_Patients->addItem(BuildPatientNamespace(&patients->at(i)).c_str());
    }

    ui->button_SelectDoctor->setEnabled(false);

}

Widget::~Widget()
{
    delete doctors;
    delete patients;
    delete doctorPage;
    delete patientPage;
    delete add_patient_dialog_;
    delete ui;
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
    int phoneNumber = patients->at(ui->listWidget_Patients->currentRow()).get_phone_number();

    patientPage->setFullName(fullName.c_str());
    patientPage->setDoctorID(doctorID);
    patientPage->setPhoneNumber(phoneNumber);

    patientPage->show();
}

void Widget::on_listWidget_Doctors_itemClicked(QListWidgetItem *item)
{
    ui->button_SelectDoctor->setEnabled(true);
}

void Widget::on_button_AddPatient_clicked()
{
    add_patient_dialog_ = new AddPatientDialog(this);
    connect(add_patient_dialog_, SIGNAL (accept_button_clicked()), this, SLOT (refresh_lists()));
    add_patient_dialog_->show();
}

void Widget::on_button_AddDoctor_clicked()
{
    add_doctor_dialog_ = new AddDoctorDialog(this);
    connect(add_doctor_dialog_, SIGNAL (accept_button_clicked()), this, SLOT (refresh_lists()));
    add_doctor_dialog_->show();
}

void Widget::refresh_lists()
{
    qDebug() << "SLOTS n SIGNALS FUNKER SHOHAIBIBI";

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
