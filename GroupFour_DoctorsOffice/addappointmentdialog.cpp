#include "addappointmentdialog.h"
#include "ui_addappointmentdialog.h"

AddAppointmentDialog::AddAppointmentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppointmentDialog)
{
    ui->setupUi(this);
    this->time_vector = new vector<string>();
}

AddAppointmentDialog::~AddAppointmentDialog()
{
    delete ui;
}

void AddAppointmentDialog::set_patientId(int id)
{
    this->patient_id_ = { id };
}

void AddAppointmentDialog::set_patientName(QString name)
{
    ui->patientName->setText(name);
}

void AddAppointmentDialog::set_patient_social_number(QString social_number)
{
    ui->label_social_number->setText(social_number);
}

void AddAppointmentDialog::set_doctorId(int id)
{
    ui->doctorId->setText(QString::number(id));
}

void AddAppointmentDialog::set_doctorName(QString name)
{
    ui->doctorName->setText(name);
}

void AddAppointmentDialog::set_listTime(vector<string> *vector_time)
{

    for(unsigned int i = 0; i < vector_time->size(); i++)
    {
        ui->listTime->addItem(vector_time->at(i).c_str());
    }

    vector<Appointment> *v_appointment;
    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        v_appointment = db.get_appointments();
        qDebug() << "Retrieved appointments";
    }
    else
    {
        qDebug() << "Appointment add failed!";
    }

    for (int i = 0; i < v_appointment->size(); ++i) {
        if(ui->date->text() == v_appointment->at(i).get_appointment_date()
                && ui->doctorId->text().toInt() == v_appointment->at(i).get_doctor_id()) {
            for(int j = 0; j < ui->listTime->count(); j++) {
                if(v_appointment->at(i).get_appointment_time() == ui->listTime->item(j)->text()) {
                    delete ui->listTime->item(j);
                }
            }
        }
    }
}

void AddAppointmentDialog::set_time_vector(vector<string> *time)
{
    this->time_vector = time;
}

void AddAppointmentDialog::on_buttonBox_accepted()
{
    QString appointment_date = ui->date->text();
    QString appointment_time = ui->listTime->currentItem()->text();
    int doctorId = ui->doctorId->text().toInt();

    Appointment *appointment = new Appointment(appointment_date, appointment_time, doctorId, this->patient_id_);

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {   
        db.create_new_appointment(*appointment);
        QMessageBox::information(this,tr("Success"),tr("Appointment added"));
        qDebug() << "Added new appointment";
    }
    else
    {
        qDebug() << "Appointment add failed!";
    }
}

void AddAppointmentDialog::on_date_userDateChanged(const QDate &date)
{

    ui->listTime->clear();

    for(unsigned int i = 0; i < time_vector->size(); i++)
    {
        ui->listTime->addItem(time_vector->at(i).c_str());
    }

    vector<Appointment> *v_appointment;
    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        v_appointment = db.get_appointments();
        qDebug() << "Retrieved appointments";
    }
    else
    {
        qDebug() << "Appointment add failed!";
    }

    for (int i = 0; i < v_appointment->size(); ++i) {
        if(ui->date->text() == v_appointment->at(i).get_appointment_date()
                && ui->doctorId->text().toInt() == v_appointment->at(i).get_doctor_id()) {
            for(int j = 0; j < ui->listTime->count(); j++) {
                if(v_appointment->at(i).get_appointment_time() == ui->listTime->item(j)->text()) {
                    delete ui->listTime->item(j);
                }
            }
        }
    }
}
