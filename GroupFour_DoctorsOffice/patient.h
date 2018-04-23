#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include "person.h"
using namespace std;

/**
 * @brief Dette er en klasse for at upprette et Patient objekt
 */
class Patient : public Person
{

public:

    /**
     * @brief Konstruktør til Patient
     * @param patient_id
     * @param social_number
     * @param first_name
     * @param last_name
     * @param phone_number
     * @param doctor_id_
     */

    Patient(int patient_id, long long social_number, QString first_name, QString last_name, int phone_number, int doctor_id_);

    /**
     * @brief getDoctorID
     * @return retunerer doctor_id_
     */

    int getDoctorID();

    /**
     * @brief getSocialNumber
     * @return returnerer social_number_
     */

    long long getSocialNumber();

    /**
     * @brief getPatientId
     * @return returnerer patient_id_
     */

    int getPatientId();


private:
    int doctor_id_;
    int patient_id_;
    long long social_number_;
};

#endif // PATIENT_H
