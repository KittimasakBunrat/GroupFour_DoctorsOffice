#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H
#include "addappointmentdialog.h"
#include "patienthistory.h"
#include "doctor.h"
#include "constants.h"

#include <QDialog>

namespace Ui {

/**
 *@brief Dette er hovedklassen for patientpage. Funksjonene under vil beskrive 
 * hvordan pasientpagen vil bli opprettet, og hva som blant annet blir vist frem.
 */

class PatientPage;
}

/**
 * @brief PatientPage klassen arver fra QDialog klassen
 */

class PatientPage : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief PatientPage konstruktør
     * @param parent
     */
    explicit PatientPage(QWidget *parent = 0);
    ~PatientPage();

    /**
     * @brief setFullName er en Set metode for å sette fulle navnstreng for personen 
     * som blir vist frem i vinduet
     * @param tar imot navn som kommer fra personen vi ønsker å vise informasjon om.
     */
    void setFullName(QString name);
    /**
     * @brief setDoctorID er en set metode for å sette doktoren sin id. En pasient har en 
     * doktor tilknyttet til seg. 
     * @param tar imot en doktor id, som er id til doktoren pasienten har.
     */
    void setDoctorID(int doctorID);
    /**
     * @brief setPatientID er en set metode for å sette pasienten sin id.
     * @param tar imot id til pasienten.
     */
    void setPatientID(int patient_id);
    /**
     * @brief setDoctorName er en set metode for å sette doktoren sitt navn.
     * @param tar imot navnet til doktoren.
     */
    void setDoctorName(QString doctorName);
    /**
     * @brief setPhoneNumber er en set metode for å sette telefonNR til pasienten. 
     * @param tar emot phoneNumber
     */
    void setPhoneNumber(int phoneNumber);
    /**
     * @brief setSocialNumber er en set metode for å sette social number til pasienten.
     * @param tar imot socialNumber fra en valgt pasient.
     */
    void setSocialNumber(long long socialNumber);

private slots:

    /**
     * @brief hanterer knappetrykk for on_pushButton_clicked
     */

    void on_pushButton_clicked();

    /**
     * @brief hanterer knappetrykk for on_open_patient_history_clicked
     */

    void on_open_patient_history_clicked();

    /**
     * @brief hanterer knappetrykk for on_pushButton_2_clicked
     */

    void on_pushButton_2_clicked();

private:
    int doctor_id_;
    int patient_id_;
    Ui::PatientPage *ui;
    AddAppointmentDialog *add_appointment;
    PatientHistory *patient_history;
    //vector<Appointment> *v_appointments_;
};

#endif // PATIENTPAGE_H
