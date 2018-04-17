#include "appointment.h"

Appointment::Appointment(QString appointment_time, int doctor_id, int patient_id)
{
    this->appointment_time_ = appointment_time;
    this->doctor_id_ = doctor_id;
    this->patient_id_ = patient_id;
}

QString Appointment::get_appointment_time()
{
    return this->appointment_time_;
}

int Appointment::get_doctor_id()
{
    return this->doctor_id_;
}

int Appointment::get_patient_id()
{
    return this->patient_id_;
}
