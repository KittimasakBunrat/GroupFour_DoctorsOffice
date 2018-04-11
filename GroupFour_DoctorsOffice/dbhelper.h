#ifndef DBHELPER_H
#define DBHELPER_H

#include <QSqlDatabase>
#include <string>
#include <iostream>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

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

    bool create_new_doctor(Doctor *doctor);


private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
