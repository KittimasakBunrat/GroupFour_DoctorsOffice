#include "dbhelper.h"

DbHelper::DbHelper(const QString &path)
{
    office_db = QSqlDatabase::addDatabase("QSQLITE");
    office_db.setDatabaseName(path);

    if(!office_db.open())
    {
        //TODO: Legg inn melding om databaseconnection error her
         qDebug() << "Error: connection with database fail";
    }
    else
    {
        //TODO: Legg inn melding om databaseconnection success her
        qDebug() << "Database: connection ok";
    }
}

DbHelper::~DbHelper()
{
    if (office_db.isOpen())
    {
        office_db.close();
    }
}

bool DbHelper::isOpen() const
{
    return office_db.isOpen();
}

bool DbHelper::create_table(const QString& table_name)
{
    bool success { false };

    QSqlQuery query;
    if(table_name == "doctors")
    {
        query.prepare("CREATE TABLE IF NOT EXISTS doctors("
                      "employee_id INTEGER PRIMARY KEY,"
                      "first_name TEXT NOT NULL,"
                      "last_name TEXT NOT NULL,"
                      "phone_number INT NOT NULL"
                      ");");
    }
    else if (table_name == "patients")
    {
        query.prepare("CREATE TABLE patients("
                      "social_number INTEGER PRIMARY KEY,"
                      "first_name TEXT NOT NULL,"
                      "last_name TEXT NOT NULL,"
                      "phone_number INT NOT NULL,"
                      "doctor INTEGER,"
                      "FOREIGN KEY(doctor) REFERENCES doctors(employee_id)"
                      ");");
    }
    else if (table_name == "appointments")
    {
        query.prepare("CREATE TABLE appointments("
                      "appointment_time TEXT PRIMARY KEY,"
                      "doctor INTEGER,"
                      "patient INTEGER,"
                      "FOREIGN KEY(doctor) REFERENCES doctors(employee_id),"
                      "FOREIGN KEY(patient) REFERENCES patients(social_number)"
                      ");");
    }

    if(query.exec())
    {
        cout << "Created table";
    }
    else
    {
        cout << "Couldn't create the table ': one might already exist.";
        success = { false };
    }
    return success;

}

bool DbHelper::create_new_patient()
{
    bool success { false };

    QSqlQuery query;
    query.prepare("INSERT INTO patients social_number, first_name,"
                  "last_name, phone_number, doctor"
                  "VALUES (123, hei, nei, 12345, 1);");

    if(!query.exec())
    {
        cout << "Couldn't create the table ': one might already exist.";
        success = { false };
    }
    else
    {
        cout << "Created table";
    }
    return success;
}
/*
bool DbManager::addPerson(const QString& name)
{
    bool success = false;

    if (!name.isEmpty())
    {
        QSqlQuery queryAdd;
        queryAdd.prepare("INSERT INTO people (name) VALUES (:name)");
        queryAdd.bindValue(":name", name);

        if(queryAdd.exec())
        {
            success = true;
        }
        else
        {
            qDebug() << "add person failed: " << queryAdd.lastError();
        }
    }
    else
    {
        qDebug() << "add person failed: name cannot be empty";
    }

    return success;
}
*/
