#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <QDialog>
#include "dbhelper.h"
#include "constants.h"
#include "appointment.h"

namespace Ui {

class PatientHistory;
}

class PatientHistory : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktør for klassen.
     * @param parent
     */
    explicit PatientHistory(QWidget *parent = 0);

    /**
     * @brief Destruktor for klassen.
     */
    ~PatientHistory();
    
    /**
     * @brief set_patient_name er en set metode for å sette pasienten sitt navn.
     * @param tar imot navn som skal settes i denne metoden.
     */
    void set_patient_name(QString name);
    
    /**
     * @brief copy_appointment_vector er en set metode for å sette inn appointments.
     * @param v_appointments er vektor bestående av appointments.
     */
    void copy_appointment_vector(vector<Appointment> *v_appointments);
    
    /**
     * @brief populate_history_list_vector er en set metode for å sette inn liste 
     * bestående av historier. 
     * @param v_appointments tar imot en vektor bestående av appointments.
     */
    void populate_history_list_vector(vector<Appointment> *v_appointments);

private slots:
    /**
     * @brief on_history_listWidget_itemClicked er en slot som er bundet med itemclicked på 
     * listwidget over historie.
     */
    void on_history_listWidget_itemClicked();

private:
    Ui::PatientHistory *ui;
    vector<Appointment> *v_patient_appointments_;
};

#endif // PATIENTHISTORY_H
