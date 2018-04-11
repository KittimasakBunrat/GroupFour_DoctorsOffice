#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <string>
#include <iostream>
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
  /*  bool create_new_entry();
    bool remove_person();
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

private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
