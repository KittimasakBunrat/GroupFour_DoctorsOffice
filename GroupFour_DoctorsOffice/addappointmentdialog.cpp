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

void AddAppointmentDialog::set_listTime(QString time)
{
    ui->listTime->addItem(time);
}

void AddAppointmentDialog::on_buttonBox_accepted()
{

    QString appointment_time = ui->date->text() + " - " + ui->listTime->currentItem()->text();
    int doctorId = ui->doctorId->text().toInt();

    Appointment *appointment = new Appointment(appointment_time, doctorId, this->patient_id_);

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
