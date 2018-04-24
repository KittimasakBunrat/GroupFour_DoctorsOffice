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
     * @brief Konstruktør til Doctor som tar imot variablerne nedanfør
     * @param first_name
     * @param last_name
     * @param phone_number
     * @param employee_number
     */

    Doctor(QString first_name, QString last_name, int phone_number, int employee_number);

    /**
     * @brief Konstruktør til Doctor
     */

    Doctor();

    /**
     * @brief get_employee_number
     * @return returnerer employee_number
     */

    int get_employee_number();

    /**
     * @brief get_vector_patients
     * @return returnerer v_patients_
     */

    vector<Patient> get_vector_patients();

    /**
     * @brief get_vector_time
     * @return returnerer v_time_
     */

    vector<string> *get_vector_time();

private:
    int employee_number_;
    vector<string> *v_time_;
    vector<Patient> v_patients_;
};

#endif // DOCTOR_H
