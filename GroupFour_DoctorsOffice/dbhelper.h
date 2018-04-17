#ifndef DBHELPER_H
#define DBHELPER_H


#include <string>
#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include "doctor.h"
#include "patient.h"
#include "appointment.h"
#include <vector>
#include <QSqlQuery>

using namespace std;

class DbHelper
{
public:
    DbHelper(const QString& path);
    ~DbHelper();

    bool isOpen() const;
    bool create_table(const QString& table_name);

    bool create_new_patient(Patient patient);
    bool update_patient(Patient patient, int id);
    vector<Patient> *get_patients();

    bool create_new_appointment(Appointment appointment);
    vector<Appointment> *get_appointments();

    bool create_new_doctor(Doctor doctor);
    bool update_doctor(Doctor doctor, int doctor_id);
    vector<Doctor> *get_doctors();

    /*bool remove_person();
    bool update_person();
    bool person_exists() const;
    void print_person();
    void print_all_persons() const;
    bool remove_all_persons();
*/
    //doctor
    //bool create_new_doctor(Doctor *doctor);
    void print_info(Doctor *doctor);

    //patients
    bool create_new_Patient(Patient *patient);
    void print_info(Patient *patient);







private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
