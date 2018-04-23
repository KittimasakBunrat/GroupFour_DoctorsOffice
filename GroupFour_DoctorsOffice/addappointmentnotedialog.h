#ifndef ADDAPPOINTMENTNOTEDIALOG_H
#define ADDAPPOINTMENTNOTEDIALOG_H

#include <QDialog>

namespace Ui {
class AddAppointmentNoteDialog;
}

class AddAppointmentNoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppointmentNoteDialog(QWidget *parent = 0);
    void setAppointmentTime(QString appointmentTime);
    void setDoctorInfo(int id);
<<<<<<< HEAD
    void setPatientInfo(int patient_social_number);
=======
    void setPatientInfo(int patientId);
>>>>>>> 1b92e10b8858f77a2add0432259ef27858bbc8ea
    ~AddAppointmentNoteDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddAppointmentNoteDialog *ui;
<<<<<<< HEAD
    int patient_social_number;
=======
    int patientId;
>>>>>>> 1b92e10b8858f77a2add0432259ef27858bbc8ea
};

#endif // ADDAPPOINTMENTNOTEDIALOG_H
