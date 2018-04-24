#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

using namespace std;

/**
 * @brief Denne klassen har klasse strukturen for appointments.
 */
class Appointment {

public:
    /**
     * @brief Konstruktor for objektet appointments.
     * @param appointment_date
     * @param appointment_time
     * @param doctor_id
     * @param patient_id
     * @param note
     */
    Appointment(QString appointment_date, QString appointment_time, int doctor_id, int patient_id, QString note);

    /**
     * @brief Funksjon for å hente appointment dato fra objektet.
     * @return
     */
    QString get_appointment_date();

    /**
     * @brief Funksjon for å hente appointment tid fra objektet.
     * @return
     */
    QString get_appointment_time();

    /**
     * @brief Funksjon for å hente notat fra objektet.
     * @return
     */
    QString get_appointment_note();

    /**
     * @brief Funksjon for å hente doktor id.
     * @return
     */
    int get_doctor_id();

    /**
     * @brief Funksjon for å hente pasient id.
     * @return
     */
    int get_patient_id();

private:
    QString appointment_date_;
    QString appointment_time_;
    QString appointment_note_;
    int doctor_id_;
    int patient_id_;
};

#endif // APPOINTMENT_H
