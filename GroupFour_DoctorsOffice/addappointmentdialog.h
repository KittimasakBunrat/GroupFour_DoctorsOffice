#ifndef ADDAPPOINTMENTDIALOG_H
#define ADDAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "patient.h"
#include "dbhelper.h"
#include "constants.h"
#include "appointment.h"


namespace Ui {
class AddAppointmentDialog;
}

class AddAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppointmentDialog(QWidget *parent = 0);
    ~AddAppointmentDialog();
    void set_patientId(int id);
    void set_patientName(QString name);
    void set_patient_social_number(QString social_number);
    void set_doctorId(int id);
    void set_doctorName(QString name);
    void set_listTime(vector<string> *vector_time);
    void set_time_vector(vector<string> *time);

private slots:
    void on_buttonBox_accepted();
    void on_date_userDateChanged();

private:
    Ui::AddAppointmentDialog *ui;
    vector<string> *time_vector;
    int patient_id_;
    int doctor_id_;
};

#endif // ADDAPPOINTMENTDIALOG_H
