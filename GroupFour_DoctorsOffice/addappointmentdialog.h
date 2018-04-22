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
    void set_listTime(QString time);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddAppointmentDialog *ui;
    int patient_id_;
    int doctor_id_;
};

#endif // ADDAPPOINTMENTDIALOG_H
