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
                      "employee_id INTEGER PRIMARY KEY AUTOINCREMENT,"
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
                      "FOREIGN KEY(patient) REFERENCES patients(id)"
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

bool DbHelper::create_new_patient(Patient patient)
{
    bool success { false };

    QSqlQuery query;
    query.prepare("INSERT INTO patients (social_number, first_name,last_name, phone_number, doctor)"
                  "VALUES (:social_number, :first_name, :last_name, :phone_number, :doctor_id)");
    query.bindValue(":social_number", patient.getSocialNumber());
    query.bindValue(":first_name", patient.get_first_name());
    query.bindValue(":last_name", patient.get_last_name());
    query.bindValue(":phone_number", patient.get_phone_number());
    query.bindValue(":doctor_id", patient.getDoctorID());

    if(!query.exec())
    {
        qDebug() << "Create patient error: " << query.lastError();
        success = { false };
    }
    else
    {
        qDebug() << "Created patient";
    }
    return success;
}

bool DbHelper::update_patient(Patient patient, int id)
{
    QSqlQuery query;
    query.prepare("UPDATE patients SET social_number = ':social_number', first_name = ':first_name', last_name = ':last_name', phone_number = ':phone_number', doctor_id = ':doctor_id' WHERE id = ':id'");
    query.bindValue(":social_number", patient.getSocialNumber());
    query.bindValue(":first_name", patient.get_first_name());
    query.bindValue(":last_name", patient.get_last_name());
    query.bindValue(":phone_number", patient.get_phone_number());
    query.bindValue("doctor_id", patient.getDoctorID());
    query.bindValue(":id", id);
}

vector<Patient> *DbHelper::get_patients()
{
    QString sql = "SELECT * FROM patients";
    vector<Patient> *v_patients = new vector<Patient>;
    QSqlQuery query(sql);
    query.exec();

    while(query.next()) {
        int social = query.value(1).toInt();
        QString first = query.value(2).toString();
        QString last = query.value(3).toString();
        int phone = query.value(4).toInt();
        int doc = query.value(5).toInt();

        Patient *patient = new Patient(social, first, last, phone, doc);

        v_patients->push_back(*patient);
    }
    return v_patients;
}

bool DbHelper::create_new_appointment(Appointment appointment)
{
    bool success { false };
    QSqlQuery query;
    query.prepare("INSERT INTO appointments (appointment_time, doctor, patient)"
                  "VALUES (:appointment_time, :doctor_id, :patient_id)");
    query.bindValue(":appointment_time", appointment.get_appointment_time());
    query.bindValue(":doctor_id", appointment.get_doctor_id());
    query.bindValue(":patient_id", appointment.get_patient_id());

    if(!query.exec())
    {
        qDebug() << "Create appointment error: " << query.lastError();
        return success;
    }
    else
    {
        qDebug() << "Created new appointment";
    }
    return success;
}

vector<Appointment> *DbHelper::get_appointments()
{
    QString sql = "SELECT * FROM appointments";
    vector<Appointment> *v_appointments = new vector<Appointment>();
    QSqlQuery query(sql);
    query.exec();

    while(query.next()) {
        QString appointment_time = query.value(0).toString();
        int doctor_id = query.value(1).toInt();
        int patient_id = query.value(2).toInt();

        Appointment *appointment = new Appointment(appointment_time, doctor_id, patient_id);

        v_appointments->push_back(*appointment);
    }

    return v_appointments;
}

bool DbHelper::create_new_doctor(Doctor doctor)
{
    bool success { false };

    QSqlQuery query;
    query.prepare("INSERT INTO doctors (first_name, last_name, phone_number)"
                  "VALUES (:first_name, :last_name, :phone_number)");
    query.bindValue(":first_name", doctor.get_first_name());
    query.bindValue(":last_name", doctor.get_last_name());
    query.bindValue(":phone_number", doctor.get_phone_number());


    if(!query.exec())
    {
        qDebug() << "Create doctor error: " << query.lastError();
        success = { false };
    }
    else
    {
        qDebug() << "Created doctor";
    }
    return success;
}

bool DbHelper::update_doctor(Doctor doctor, int doctor_id)
{
    QSqlQuery query;
    query.prepare("UPDATE doctors SET first_name = ':first_name', last_name = ':last_name', phone_number = ':phone_number' WHERE employee_id = ':employee_id'");
    query.bindValue(":first_name", doctor.get_first_name());
    query.bindValue(":last_name", doctor.get_last_name());
    query.bindValue(":phone_number", doctor.get_phone_number());
    query.bindValue(":employee_id", doctor_id);
}

vector<Doctor> *DbHelper::get_doctors()
{
    QString sql = "SELECT * FROM doctors";
    vector<Doctor> *v_doctors = new vector<Doctor>;
    QSqlQuery query(sql);
    query.exec();

    while(query.next()) {
        int employee_number = query.value(0).toInt();
        QString first_name_db = query.value(1).toString();
        QString last_name_db = query.value(2).toString();
        int phone_db = query.value(3).toInt();

        Doctor *doctor = new Doctor(first_name_db, last_name_db, phone_db, employee_number);

        v_doctors->push_back(*doctor);
    }
    return v_doctors;
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
