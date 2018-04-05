#include "person.h"

Person::Person(string first_name, string last_name, int social_number, int phone_number)
{
    this->first_name_ = { first_name };
    this->last_name_ = { last_name };
    this->social_number_ = { social_number };
    this->phone_number_ = { phone_number };
}

string Person::get_first_name()
{
    return first_name_;
}

string Person::get_last_name()
{
    return last_name_;
}

int Person::get_social_number()
{
    return social_number_;
}

int Person::get_phone_number()
{
    return phone_number_;
}

void Person::set_first_name(string first_name)
{
    this->first_name_ = { first_name };
}

void Person::set_last_name(string last_name)
{
    this->last_name_ = { last_name };
}

void Person::set_phone_number(int phone_number)
{
    this->phone_number_ = { phone_number};
}
