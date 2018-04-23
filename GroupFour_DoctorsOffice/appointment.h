#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

using namespace std;

class Appointment {

public:
    Appointment(QString appointment_date, QString appointment_time, int doctor_id, int patient_id, QString note);
    QString get_appointment_date();
    QString get_appointment_time();
    QString get_appointment_note();
    int get_doctor_id();
    int get_patient_id();

private:
    QString appointment_date_;
    QString appointment_time_;
    QString appointment_note_;
    int doctor_id_;
    int patient_id_;
};

#endif // APPOINTMENT_H
