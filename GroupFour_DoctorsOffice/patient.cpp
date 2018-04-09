#include "patient.h"

Patient::Patient(string first_name, string last_name, int social_number, int phone_number)
{
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->social_number_ = social_number;
    this->phone_number_ = phone_number;
}

string Patient::get_first_name()
{
    return this->first_name_;
}

string Patient::get_last_name()
{
    return this->last_name_;
}

int Patient::get_social_number()
{
    return this->social_number_;
}

int Patient::get_phone_number()
{
    return this->phone_number_;
}
