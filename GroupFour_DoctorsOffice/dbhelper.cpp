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
    /*
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE people(id INTEGER PRIMARY KEY, name TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'people': one might already exist.";
        success = false;
    }

    return success;
    */
    bool success { false };

    QSqlQuery query;
    if(table_name == "doctors")
    {
        query.prepare("CREATE TABLE IF NOT EXISTS doctors("
                      "employee_id INTEGER PRIMARY KEY,"
                      "first_name TEXT NOT NULL,"
                      "last_name TEXT NOT NULL"
                      ");");
    }
    else if (table_name == "patients")
    {
        query.prepare("CREATE TABLE patients("
                      "social_number INTEGER PRIMARY KEY,"
                      "first_name TEXT NOT NULL,"
                      "last_name TEXT NOT NULL,"
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
