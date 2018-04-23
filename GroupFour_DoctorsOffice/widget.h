#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"
#include <QListWidgetItem>
#include "doctorpage.h"
#include "patientpage.h"
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "addappointmentnotedialog.h"
#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <string>
#include <sstream>
#include "dbhelper.h"
#include "constants.h"
#include <QApplication>

namespace Ui {
class Widget;
}

/**
 * @brief Dette er hovedklassen som vil ved hjelp av widget.ui vise
 *  hovedvinduet til hele prosjektet.
 */
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    /**
     * @brief filter_doctors brukes til å filtrere i søkeboksen doktorer.
     */
    void filter_doctors(QString filter_string);
    
    /**
     * @brief filter_patients brukes til å filtrere i søkeboksen til pasienter
     */
    void filter_patients(QString filter_string);
    //void filter_appointments(QString filter_string);
    
    /**
     * @brief hide_all_doctors fjerner alle doktorer som ikke matcher søkefeltet
     */
    void hide_all_doctors();
    
    /**
     * @brief hide_all_patients fjerner alle pasienter som ikke matcher søkefeltet
     */
    void hide_all_patients();
    
    /**
     * @brief hide_all_appointments fjerner alle appointments som ikke matcher søkefeltet
     */
    void hide_all_appointments();
    
    /**
     * @brief buildEmptyComboBox tømmer hele søkefeltet, og setter en streng der
     */
    void buildEmptyComboBox();


private slots:
  
    void on_button_SelectDoctor_clicked();

    void on_listWidget_Doctors_itemClicked();

    void on_button_SelectPatient_clicked();

    void on_button_AddPatient_clicked();

    void on_button_AddDoctor_clicked();

    void refresh_lists();

    void filter_appointments(const QString& filter_string);

    void on_filter_doctor_edit_textChanged(const QString &arg1);

    void on_filter_patient_edit_textChanged(const QString &arg1);

    void on_listWidget_Patients_itemClicked();

    void on_listWidget_Appointments_itemClicked();

    void on_button_SelectAppointment_clicked();

    void list_doctor_time(int doctorId);

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Widget *ui;
    vector<Doctor> *doctors;
    vector<Patient> *patients;
    vector<Appointment> *appointments;
    DoctorPage *doctorPage;
    PatientPage *patientPage;
    AddPatientDialog *add_patient_dialog_;
    AddDoctorDialog *add_doctor_dialog_;
    AddAppointmentNoteDialog *add_appointment_note_dialog_;
};

/**
 * @brief BuildDoctorNamespace er en hjelpefunksjon som skal bygge ut en streng
 * for å få vist denne strengen videre i Doctordialog. Dette er for at brukeren skal kunne
 * se fornavn og etternavn i et og samme felt.
 * @param doctor objeketet som vi er interessert i å bygge navnstreng utifra.
 * @return Returnerer en streng som inneholder fornavn og etternavn
 */
static string BuildDoctorNamespace(Doctor *doctor);
/**
 * @brief BuildPatientNamespace er en hjelpefunksjon som skal bygge ut en streng
 * for å få vist denne strengen videre i Patientdialog. Dette er for at brukeren skal kunne
 * se fornavn og etternavn i et og samme felt.
 * @param patient objektet som vi er interessert i å bygge navnestreng utifra
 * @return Returnerer en streng som inneholder fornavn og etternavn
 */
static string BuildPatientNamespace(Patient *patient);

//tenk over denne
static string BuildAppointmentNamespace(Appointment *appointment);

/**
 * @brief getPatientSocialNumberForNoteDialog brukes til å få ut informasjon fra 
 * det som står relatert til appointment. På denne måten har vi mulighetent til å finne ut 
 * socialnumber, som skal brukes til å identifisere og finne ut ID til en pasient som har
 * denne bestilte timen. 
 * @param displayedText er teksten som viser timebestilling.
 * @return returnerer socialnumber
 */
static int getPatientSocialNumberForNoteDialog(QString displayedText);

//duplikat?
string BuildDoctorNamespace(Doctor *doctor);

//duplikat?
string BuildPatientNamespace(Patient *patient);

//duplikat?
string BuildAppointmentNamespace(Appointment *appointment);

#endif // WIDGET_H
