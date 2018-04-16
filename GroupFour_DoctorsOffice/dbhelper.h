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

using namespace std;

class DbHelper
{
public:
    DbHelper(const QString& path);
    ~DbHelper();

    bool isOpen() const;
    bool create_table(const QString& table_name);
    bool create_new_patient(const int& social_number, const QString& first_name,
                            const QString& last_name, const int& phone_number, const int& doctor_id);
    /*bool remove_person();
    bool update_person();
    bool person_exists() const;
    void print_person();
    void print_all_persons() const;
    bool remove_all_persons();*/

    //doctor
    bool create_new_doctor(Doctor *doctor);
    void print_info(Doctor *doctor);

    //patients
    bool create_new_Patient(Patient *patient);
    void print_info(Patient *patient);

    bool update_patient(const int& social_number, const QString& first_name,
                            const QString& last_name, const int& phone_number, const int& doctor_id, const int& id);


private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
