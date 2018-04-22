#include "person.h"

Person::Person(QString first_name, QString last_name, int phone_number)
{
    this->first_name_ = first_name ;
    this->last_name_ = last_name ;
    this->phone_number_ = phone_number;
}

Person::Person() {}

QString Person::get_first_name()
{
    return this->first_name_;
}

QString Person::get_last_name()
{
    return this->last_name_;
}

int Person::get_phone_number()
{
    return this->phone_number_;
}
