#include "patient.h"

Patient::Patient(int social_number, QString first_name, QString last_name, int phone_number, int doctor_id) : Person(first_name, last_name, phone_number)
{
    this->social_number_ = social_number;
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->phone_number_ = phone_number;
    this->doctor_id_ = doctor_id;
}

int Patient::getDoctorID()
{
    return this->doctor_id_;
}

int Patient::getSocialNumber()
{
    return this->social_number_;
}
