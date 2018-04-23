#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <QDialog>
#include "dbhelper.h"
#include "constants.h"
#include "appointment.h"

namespace Ui {

class PatientHistory;
}

class PatientHistory : public QDialog
{
    Q_OBJECT

public:
    explicit PatientHistory(QWidget *parent = 0);
    ~PatientHistory();
    void set_patient_name(QString name);
   // void setDoctorID(int doctorID);
    //void set_patient_id(int patient_id);
   // void setDoctorName(QString doctorName);
   // void setPhoneNumber(int phoneNumber);
   // void setSocialNumber(long long socialNumber);
    //vector<Appointment> set_appointments_vector(vector<Appointment> &v_appointments);
    void copy_appointment_vector(vector<Appointment> *v_appointments);
    void populate_history_list_vector(vector<Appointment> *v_appointments);

private slots:
    void on_history_listWidget_itemClicked();

private:
    Ui::PatientHistory *ui;
    vector<Appointment> *v_patient_appointments_;
    int patient_id_;
};

#endif // PATIENTHISTORY_H
