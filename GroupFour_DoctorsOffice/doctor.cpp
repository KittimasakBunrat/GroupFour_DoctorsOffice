#include "doctor.h"

Doctor::Doctor(QString first_name, QString last_name, int phone_number, int employee_number) : Person(first_name, last_name, phone_number)

{
    this->first_name_ = first_name;
    this->last_name_ = last_name;
    this->phone_number_ = phone_number;
    this->employee_number_ = employee_number;
    this->v_time_ = new vector<string>();

    for(int i = 8; i <= 16; i++) {
        string time;
        if(i < 10) {
            time = "0" + to_string(i) + ":00";
        } else {
            time = to_string(i) + ":00";
        }
        v_time_->push_back(time);
    }
}

Doctor::Doctor() { }


int Doctor::get_employee_number()
{
    return this->employee_number_;
}

vector<Patient> Doctor::get_vector_patients()
{
    return this->v_patients_;
}

vector<string> *Doctor::get_vector_time()
{
    return this->v_time_;
}


