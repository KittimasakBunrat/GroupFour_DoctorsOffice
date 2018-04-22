#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include "person.h"
using namespace std;

class Patient : public Person
{
public:
    Patient(int patient_id, long long social_number, QString first_name, QString last_name, int phone_number, int doctor_id_);
    int getDoctorID();
    long long getSocialNumber();
    int getPatientId();


private:
    int doctor_id_;
    int patient_id_;
    long long social_number_;
};

#endif // PATIENT_H
