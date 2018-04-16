#include "widget.h"
#include "ui_widget.h"
#include "doctor.h"
#include <iostream>
//ikke disse
#include <QMessageBox>



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

    Doctor *doctor1 = new Doctor("Kittimasak", "Bunrat", 1112, 12345678, 35463);
    Doctor *doctor2 = new Doctor("Shohaib", "Muhammad", 1113, 12345678, 35464);
    Doctor *doctor3 = new Doctor("Pontus", "Skóld", 1113, 12345678, 35465);
    Doctor *doctor4 = new Doctor("Rudi", "Dahle", 1114, 12345678, 35466);

    /*
    Patient *patient1 = new Patient("Shohaib", "Muhammad", 123321123, 46937362);
    Patient *patient2 = new Patient("Kittimasak", "Bunrat", 34534345, 456765);
    Patient *patient3 = new Patient("Rudi", "Dahle", 6785677, 92567894);
    Patient *patient4 = new Patient("Pontus", "Skóld", 98786758, 80904930);
    */

    db.create_new_patient(323,"Bundolf","Kittler", 665577, 442244);
    db.create_new_patient(545,"Rudislav","Captanikoskav",999666,44330);

    doctors = new vector<Doctor>();
    patients = new vector<Patient>();

    doctors->push_back(*doctor1);
    doctors->push_back(*doctor2);
    doctors->push_back(*doctor3);
    doctors->push_back(*doctor4);

 /*   patients->push_back(*patient1);
    patients->push_back(*patient2);
    patients->push_back(*patient3);
    patients->push_back(*patient4);*/

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
    bodyStream << doctor->get_first_name() << " " << doctor->get_last_name();
    doctorInfo = bodyStream.str();
    return doctorInfo;
}

static string BuildPatientNamespace(Patient *patient)
{
    string patientInfo;
    ostringstream bodyStream;
    bodyStream << patient->get_first_name() << " " << patient->get_last_name();
    patientInfo = bodyStream.str();
    return patientInfo;
}

void Widget::on_button_SelectDoctor_clicked()
{

    doctorPage = new DoctorPage(this);

    string fullName = BuildDoctorNamespace(&doctors->at(ui->listWidget_Doctors->currentRow())).c_str();
    static const int socialNumber = doctors->at(ui->listWidget_Doctors->currentRow()).get_social_number();
    static const int phoneNumber = doctors->at(ui->listWidget_Doctors->currentRow()).get_phone_number();
    static const int employeeNumber = doctors->at(ui->listWidget_Doctors->currentRow()).get_employee_number();

    doctorPage->setFullName(fullName.c_str());
    doctorPage->setSocialNumber(socialNumber);
    doctorPage->setPhoneNumber(phoneNumber);
    doctorPage->setEmployeeNumber(employeeNumber);

    doctorPage->show();
}

void Widget::on_button_SelectPatient_clicked()
{
    patientPage = new PatientPage(this);

    string fullName = BuildPatientNamespace(&patients->at(ui->listWidget_Patients->currentRow())).c_str();
    static const int socialNumber = patients->at(ui->listWidget_Patients->currentRow()).get_social_number();
    static const int phoneNumber = patients->at(ui->listWidget_Patients->currentRow()).get_phone_number();

    patientPage->setFullName(fullName.c_str());
    patientPage->setSocialNumber(socialNumber);
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
    add_patient_dialog_->show();
}

void Widget::on_button_AddDoctor_clicked()
{
    //add_doctor_page = new AddDoctorPage(this);
    //add_doctor_page->show();
}
