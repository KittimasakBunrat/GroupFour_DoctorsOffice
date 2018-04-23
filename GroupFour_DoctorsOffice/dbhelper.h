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
    bool update_appointment(int doctorId, int patientId, QString appointmentTime, QString notes);
    vector<Appointment> *get_distinct_appointments(int employee_id);
    vector<Appointment> *get_appointments();

    bool create_new_doctor(Doctor doctor);
    bool update_doctor(Doctor doctor, int doctor_id);
    vector<Doctor> *get_doctors();


private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
