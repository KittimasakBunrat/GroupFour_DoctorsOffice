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
                      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "social_number INTEGER,"
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

bool DbHelper::create_new_patient(const int& social_number, const QString& first_name,
                                  const QString& last_name, const int& phone_number, const int& doctor_id)
{
    bool success { false };

    QSqlQuery query;
    query.prepare("INSERT INTO patients (social_number, first_name,last_name, phone_number, doctor)"
                  "VALUES (:social_number, :first_name, :last_name, :phone_number, :doctor_id)");
    query.bindValue(":social_number", social_number);
    query.bindValue(":first_name", first_name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":phone_number", phone_number);
    query.bindValue(":doctor_id", doctor_id);

    if(!query.exec())
    {
        qDebug() << "Create patient error: " << query.lastError();
        success = { false };
    }
    else
    {
        qDebug() << "Created table";
    }
    return success;
}

bool DbHelper::update_patient(const int &social_number, const QString &first_name, const QString &last_name, const int &phone_number, const int &doctor_id, const int& id)
{
    QSqlQuery query;
    query.prepare("UPDATE patients SET social_number = ':social_number', first_name = ':first_name', last_name = ':last_name', phone_number = ':phone_number', doctor_id = ':doctor_id' WHERE id = ':id'");
    query.bindValue(":social_number", social_number);
    query.bindValue(":first_name", first_name);
    query.bindValue(":last_name", last_name);
    query.bindValue(":phone_number", phone_number);
    query.bindValue("doctor_id", doctor_id);
    query.bindValue(":id", id);
}

QSqlQuery DbHelper::query(const QString &sql)
{
    QSqlQuery query(sql);
    query.exec();
    return query;
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
