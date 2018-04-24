#ifndef PATIENT_H
#define PATIENT_H
#include <QString>
#include "person.h"
using namespace std;

/**
 * @brief Dette er en klasse for at upprette et Patient objekt. Den arver fra Person klassen.
 */

class Patient : public Person
{

public:

    /**
     * @brief Konstruktør til Patient, tar imot variablerne nedanfør.
     * @param patient_id er ID til en pasient. 
     * @param social_number er social number til pasienten.
     * @param first_name er fornavnet til pasienten.
     * @param last_name er etternavnet til pasienten
     * @param phone_number er telefonNR til pasienten
     * @param doctor_id_ er doktorID til en pasient.
     */

    Patient(int patient_id, long long social_number, QString first_name, QString last_name, int phone_number, int doctor_id_);

    /**
     * @brief getDoctorID er en get metode for å hente inn ID til Doktoren som pasienten har som fastlege. 
     * @return retunerer doctor_id_
     */

    int getDoctorID();

    /**
     * @brief getSocialNumber er en get metode for å hente inn socialNR til en pasient.
     * @return returnerer social_number_
     */

    long long getSocialNumber();

    /**
     * @brief getPatientId er en get metode for å hente inn ID til en pasient.
     * @return returnerer patient_id_
     */

    int getPatientId();


private:
    int doctor_id_;
    int patient_id_;
    long long social_number_;
};

#endif // PATIENT_H
