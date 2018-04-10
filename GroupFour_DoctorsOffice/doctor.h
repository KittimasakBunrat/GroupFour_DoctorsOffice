#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include <string>
#include "patient.h"
using namespace std;


class Doctor
{

public:
    Doctor(string first_name, string last_name, int social_number, int phone_number);

private:

    string first_name;
    string last_name;
    int social_number;
    int phone_number;

    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
