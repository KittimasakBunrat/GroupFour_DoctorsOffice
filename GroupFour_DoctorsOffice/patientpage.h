#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H
#include "addappointmentdialog.h"
#include "patienthistory.h"
#include "doctor.h"
#include "constants.h"

#include <QDialog>

namespace Ui {

/**
 *@brief Dette er en klasse for at oprette et PatientPage objekt.
 */

class PatientPage;
}

/**
 * @brief PatientPage klassen
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
     * @brief setFullName
     * @param tar emot name
     */
    void setFullName(QString name);
    /**
     * @brief setDoctorID
     * @param tar emot doctorID
     */
    void setDoctorID(int doctorID);
    /**
     * @brief setPatientID
     * @param tar emot patient_id
     */
    void setPatientID(int patient_id);
    /**
     * @brief setDoctorName
     * @param tar emot doctorName
     */
    void setDoctorName(QString doctorName);
    /**
     * @brief setPhoneNumber
     * @param tar emot phoneNumber
     */
    void setPhoneNumber(int phoneNumber);
    /**
     * @brief setSocialNumber
     * @param tar emot socialNumber
     */
    void setSocialNumber(long long socialNumber);

private slots:

    /**
     * @brief hanterer knappetrykk for on_pushButton_clicked
     */

    void on_pushButton_clicked();

    /**
     * @brief hanterer knappetrykk for on_pushButton_3_pressed
     */

    void on_pushButton_3_pressed();

    /**
     * @brief hanterer knappetrykk for on_pushButton_2_clicked
     */

    void on_pushButton_2_clicked();

    void on_open_patient_history_clicked();

private:
    int doctor_id_;
    int patient_id_;
    Ui::PatientPage *ui;
    AddAppointmentDialog *add_appointment;
    PatientHistory *patient_history;
    //vector<Appointment> *v_appointments_;
};

#endif // PATIENTPAGE_H
