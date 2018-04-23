#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H
#include "addappointmentdialog.h"
#include "patienthistory.h"
#include "doctor.h"
#include "constants.h"

#include <QDialog>

namespace Ui {
class PatientPage;
}

class PatientPage : public QDialog
{
    Q_OBJECT

public:
    explicit PatientPage(QWidget *parent = 0);
    ~PatientPage();

    void setFullName(QString name);
    void setDoctorID(int doctorID);
    void setPatientID(int patient_id);
    void setDoctorName(QString doctorName);
    void setPhoneNumber(int phoneNumber);
    void setSocialNumber(long long socialNumber);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_open_patient_history_clicked();

private:
    int doctor_id_;
    int patient_id_;
    Ui::PatientPage *ui;
    AddAppointmentDialog *add_appointment;
    PatientHistory *patient_history;
    //vector<Appointment> *v_appointments_;
};

#endif // PATIENTPAGE_H
