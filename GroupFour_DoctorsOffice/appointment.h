#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

using namespace std;

class Appointment {

public:
    Appointment(QString appointment_time, int doctor_id, int patient_id);
    QString get_appointment_time();
    int get_doctor_id();
    int get_patient_id();

private:
    QString appointment_time_;
    int doctor_id_;
    int patient_id_;
};

#endif // APPOINTMENT_H
