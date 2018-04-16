#ifndef PATIENT_H
#define PATIENT_H
#include <string>
#include "person.h"
using namespace std;

class Patient : public Person
{
public:
    Patient(string first_name, string last_name, int social_number, int phone_number);
};

#endif // PATIENT_H
