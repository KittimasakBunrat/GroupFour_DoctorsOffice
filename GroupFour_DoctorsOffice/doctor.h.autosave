#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include "patient.h"
#include "person.h"
using namespace std;

/**
 * @brief Doctor klassen arver fra Person
 */

class Doctor : public Person
{
public:

    /**
     * @brief Konstruktør til Doctor
     * @param first_name er fornavnet til doktoren
     * @param last_name er etternavnet til doktoren
     * @param phone_number er telefonNR til doktoren
     * @param employee_number er employeenr/id til en doktor.
     */

    Doctor(QString first_name, QString last_name, int phone_number, int employee_number);

    /**
     * @brief Standardkonstrukør til Doctor.
     */

    Doctor();

    /**
     * @brief get_employee_number er en get metode for å hente inn employeenumber til en doktor.
     * @return returnerer employee_number
     */

    int get_employee_number();

    /**
     * @brief get_vector_patients er en get metode for å hente inn en vektor bestående av pasienter, som
     * er tilknyttet til doktoren. 
     * @return returnerer en vektor bestående av pasienter
     */

    vector<Patient> get_vector_patients();

    /**
     * @brief get_vector_time er en get metode for å hente inn vektor bestående av tid.
     * @return returnerer vektor bestående av tid
     */

    vector<string> *get_vector_time();

private:
    int employee_number_;
    vector<string> *v_time_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
