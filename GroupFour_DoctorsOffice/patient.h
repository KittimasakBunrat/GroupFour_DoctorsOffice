#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "person.h"
using namespace std;

class Patient : public Person
{
public:
    Patient(int social_number, string first_name, string last_name, int phone_number, int doctor_id_);

private:
    int doctor_id_;
};

#endif // PATIENT_H
