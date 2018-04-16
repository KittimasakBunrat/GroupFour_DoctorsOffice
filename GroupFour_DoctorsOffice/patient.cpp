#include "patient.h"

Patient::Patient(string first_name, string last_name, int social_number, int phone_number) : Person(first_name, last_name, social_number, phone_number)
{
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->social_number_ = social_number;
    this->phone_number_ = phone_number;
}
