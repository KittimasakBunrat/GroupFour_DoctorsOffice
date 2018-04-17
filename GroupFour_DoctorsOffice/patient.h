#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include "person.h"
using namespace std;

class Patient : public Person
{
public:
    Patient(int social_number, QString first_name, QString last_name, int phone_number, int doctor_id_);
    int getDoctorID();
    int getSocialNumber();


private:
    int doctor_id_;
    int social_number_;
};

#endif // PATIENT_H
