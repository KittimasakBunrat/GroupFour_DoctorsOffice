#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include <string>
#include "patient.h"
using namespace std;


class Doctor
{
public:
    Doctor(string first_name, string last_name, int social_number, int phone_number, int employee_number);
    string get_first_name();
    string get_last_name();
    int get_social_number();
    int get_phone_number();
    int get_employee_number();
    vector<Patient> get_vector_patients();

private:
    string first_name_;
    string last_name_;
    int social_number_;
    int phone_number_;
    int employee_number_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
