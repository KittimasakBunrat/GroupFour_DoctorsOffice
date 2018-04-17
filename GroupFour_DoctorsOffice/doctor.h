#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include "patient.h"
#include "person.h"
using namespace std;

class Doctor : public Person
{
public:
    Doctor(QString first_name, QString last_name, int phone_number, int employee_number);
    int get_employee_number();

    vector<Patient> get_vector_patients();

private:
    int employee_number_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
