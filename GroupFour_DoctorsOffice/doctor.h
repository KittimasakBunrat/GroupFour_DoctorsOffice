#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include <string>
using namespace std;


class Doctor: public Person
{
public:
    Doctor(string first_name, string last_name, int social_number, int phone_number);
    int get_employee_number();

private:
    int employee_number_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
