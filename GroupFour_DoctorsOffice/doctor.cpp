#include "doctor.h"


Doctor::Doctor(string first_name, string last_name, int social_number, int phone_number) : Person(first_name, last_name, social_number, phone_number)
{
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->social_number_ = social_number;
    this->phone_number_ = phone_number;
    //this->employee_number_ = employee_number;
}

/*
int Doctor::get_employee_number()
{
    return this->employee_number_;
}
*/

vector<Patient> Doctor::get_vector_patients()
{
    return this->v_patients_;
}

