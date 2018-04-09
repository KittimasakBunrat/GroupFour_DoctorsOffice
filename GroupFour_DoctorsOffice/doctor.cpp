#include "doctor.h"


Doctor::Doctor(string first_name, string last_name, int social_number, int phone_number, int employee_number)
{
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->social_number_ = social_number;
    this->phone_number_ = phone_number;
    this->employee_number_ = employee_number;
}

string Doctor::get_first_name()
{
    return this->first_name_;
}

string Doctor::get_last_name()
{
    return this->last_name_;
}

int Doctor::get_social_number()
{
    return this->social_number_;
}

int Doctor::get_phone_number()
{
    return this->phone_number_;
}

int Doctor::get_employee_number()
{
    return this->employee_number_;
}

vector<Patient> Doctor::get_vector_patients()
{
    return this->v_patients_;
}

