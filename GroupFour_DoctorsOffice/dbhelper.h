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

/**
 * @brief Dette er klasse for å opprette et DbHelper objekt.
 */

class DbHelper
{

public:

    /**
     * @brief Konstruktør til DbHelper
     * @param path tar imot en path til database
     */

    DbHelper(const QString& path);

    /**
     * @brief Destruktor for klassen.
     */
    ~DbHelper();

    /**
     * @brief er en metode for å se om database connection er åpen eller lukket.
     * @return returnerer true/false basert på om databasen er åpen eller ikke
     */

    bool isOpen() const;
    
    /**
     * @brief create_table er en metode for å opprette database tabell
     * @param table_name tabellnavn
     * @return returnerer true/false basert på om tabellen ble opprettet eller ikke
     */
    
    bool create_table(const QString& table_name);

    
    /**
     * @brief create_new_patient vil opprette en ny pasient i databasen. 
     * @param patienten som man ønsker å sette inn i tabellen.
     * @return returnerer true/false basert på om det var success eller ikke
     */
    bool create_new_patient(Patient patient);
    
    /**
     * @brief get_patients er en getter for å kunne hente inn alle pasienter i en database
     * @return returnerer en vektor bestående av pasienter
     */
    vector<Patient> *get_patients();

    /**
     * @brief create_new_appointment oppretter et nytt appointment.
     * @param appointment bestilte timen man ønsker å legge inn i datbasen
     * @return returnerer true/false basert på om det var success eller ikke
     */
    bool create_new_appointment(Appointment appointment);
    
    /**
     * @brief update_appointment Dette vil oppdatere eksisterende appointment, med et notat
     * tilknyttet til seg. Variabelene under blir brukt til å finne og binde seg, slik at 
     * vi kan finne riktig appointment i datbasen
     * @param doctorId ID til doktoren
     * @param patientId ID til pasienten
     * @param appointmentTime appointment tiden.
     * @param notes er notat relatert til timen.
     * @return returnerer true/false basert på om det var success eller ikke
     */
    bool update_appointment(int doctorId, int patientId, QString appointmentTime, QString notes);
    
    /**
     * @brief get_distinct_appointments vil hente inn alle appointments tilknyttet til en doktor.
     * @param employee_id er id til doktoren vi skal hente appointmentsene til
     * @return returnerer en vektor bestående av alle appointments til en valgt doktor.
     */
    vector<Appointment> *get_distinct_appointments(int employee_id);
    
    /**
     * @brief get_single_patients_appointments alle timer som en pasient har bestilt. 
     * @param patient_id er id til pasient vi ønsker å hente timer til
     * @return returnerer en vektor bestående av timer til en pasient
     */
    vector<Appointment> *get_single_patients_appointments(int patient_id);
    
    /**
     * @brief get_appointments henter ut alle appointments fra databaen. 
     * @return returnerer en vektor bestående av alle appointments fra databasen
     */
    vector<Appointment> *get_appointments();

    /**
     * @brief create_new_doctor oppretter en ny doktor i databsen
     * @param doctor er doktoren vi ønsker å legge inn i datbasen
     * @return returnerer true/false basert på om det var success eller ikke
     */
    bool create_new_doctor(Doctor doctor);
    
    /**
     * @brief get_doctors henter ut alle doktorerer fra databasen
     * @return returnerer en vektor bestående av doktorer som er i datbasen
     */
    vector<Doctor> *get_doctors();


private:
    QSqlDatabase office_db;
};

#endif // DBHELPER_H
