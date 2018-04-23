#include "addappointmentnotedialog.h"
#include "ui_addappointmentnotedialog.h"

AddAppointmentNoteDialog::AddAppointmentNoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppointmentNoteDialog)
{
    ui->setupUi(this);
}

void AddAppointmentNoteDialog::setAppointmentTime(QString appointmentTime)
{
    ui->appointment_label->setText(appointmentTime);
}

void AddAppointmentNoteDialog::setAppointmentDate(QString appointmentDate)
{
    ui->appointment_label_2->setText(appointmentDate);
}

void AddAppointmentNoteDialog::setDoctorInfo(int id)
{
    ui->doctorId_label->setNum(id);
}

void AddAppointmentNoteDialog::setPatientInfo(int patient_social_number)
{
    ui->patientId_label->setNum(patient_social_number);
}

AddAppointmentNoteDialog::~AddAppointmentNoteDialog()
{
    delete ui;
}

void AddAppointmentNoteDialog::on_buttonBox_accepted()
{
    int doctorId = ui->doctorId_label->text().toInt();
    int patientId = ui->patientId_label->text().toInt();
    QString appointmentTime = ui->appointment_label->text();
    QString notes = ui->note_textEdit->toPlainText();

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        db.update_appointment(doctorId, patientId, appointmentTime, notes);
        QMessageBox::information(this,tr("Success"),tr("Note added"));
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }
}
