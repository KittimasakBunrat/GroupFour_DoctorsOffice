#include "patienthistory.h"
#include "ui_patienthistory.h"

PatientHistory::PatientHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientHistory)
{
    ui->setupUi(this);
}

PatientHistory::~PatientHistory()
{
    delete ui;
}

void PatientHistory::set_patient_name(QString name)
{
    ui->history_patient_label->setText(name);
}

void PatientHistory::copy_appointment_vector(vector<Appointment> *v_appointments)
{
    v_patient_appointments_ = v_appointments;
    populate_history_list_vector(v_patient_appointments_);
}

void PatientHistory::populate_history_list_vector(vector<Appointment> *v_patient_appointments)
{
    for (unsigned int i = 0; i < v_patient_appointments->size(); i++)
    {
        ui->history_listWidget->addItem(v_patient_appointments->at(i).get_appointment_date() +
                                        " : " + v_patient_appointments->at(i).get_appointment_time());
    }
}

void PatientHistory::on_history_listWidget_itemClicked()
{
    ui->history_patient_label->setText("halllooooo");
    ui->appointment_notes_textBrowser->setText(v_patient_appointments_->at(ui->history_listWidget->currentRow()).get_appointment_note());
    /*
    qDebug() << endl;
    for (unsigned int i = 0; i < v_patient_appointments_->size(); i++)
    {
        qDebug() << "Date: " << v_patient_appointments_->at(i).get_appointment_date();
        qDebug() << "Time: " << v_patient_appointments_->at(i).get_appointment_time();
        qDebug() << "Doctor Id: " << v_patient_appointments_->at(i).get_doctor_id();
        qDebug() << "Patient Id: " << v_patient_appointments_->at(i).get_patient_id();
        qDebug() << "Note: " << v_patient_appointments_->at(i).get_appointment_note();
        qDebug() << endl;
    }
*/
    qDebug() << v_patient_appointments_->at(ui->history_listWidget->currentRow()).get_appointment_note();
   // ui->appointment_notes_textBrowser->setText(v_patient_appointments_->at(ui->history_listWidget->currentRow()).get_appointment_note());

}
