#include "addappointmentnotedialog.h"
#include "ui_addappointmentnotedialog.h"

AddAppointmentNoteDialog::AddAppointmentNoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppointmentNoteDialog)
{
    ui->setupUi(this);
}

void AddAppointmentNoteDialog::setAppointmentInfo(QString appointmentinfo)
{
    ui->appointment_label->setText(appointmentinfo);
}

void AddAppointmentNoteDialog::setDoctorInfo(int doctorinfo)
{
    ui->doctorId_label->setText(QString::number(doctorinfo));
}

AddAppointmentNoteDialog::~AddAppointmentNoteDialog()
{
    delete ui;
}

void AddAppointmentNoteDialog::on_buttonBox_accepted()
{
    /*
    QString appointment_time = ui->date->text() + " - " + ui->listTime->currentItem()->text();
    int doctorId = ui->doctorId->text().toInt();
    int patientId = ui->patientId->text().toInt();

    Appointment *appointment = new Appointment(appointment_time, doctorId, patientId);

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
    */


}
