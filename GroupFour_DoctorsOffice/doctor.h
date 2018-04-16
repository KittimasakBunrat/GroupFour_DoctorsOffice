#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include <string>
#include "patient.h"
#include "person.h"
using namespace std;


class Doctor : public Person
{
public:
    Doctor(string first_name, string last_name, int social_number, int phone_number, int employee_number);
    int get_employee_number();
    vector<Patient> get_vector_patients();

private:
    int employee_number_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
