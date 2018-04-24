#ifndef ADDAPPOINTMENTDIALOG_H
#define ADDAPPOINTMENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "patient.h"
#include "dbhelper.h"
#include "constants.h"
#include "appointment.h"


namespace Ui {
class AddAppointmentDialog;
}

/**
 * @brief Denne klassen har hovedansvaret å kontrollere dialog for når appointments blir lagt til. Og klassen extender QDialog.
 */

class AddAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktør for klassen som tar inn QWidget som parameter.
     * @param parent
     */
    explicit AddAppointmentDialog(QWidget *parent = 0);

    /**
     * @brief Destruktor for klassen.
     */
    ~AddAppointmentDialog();

    /**
     * @brief Funksjon for å sette den grafiske pasient Id.
     * @param id
     */
    void set_patientId(int id);

    /**
     * @brief Funksjon for å sette den grafiske pasientnavn.
     * @param name
     */
    void set_patientName(QString name);

    /**
     * @brief Funksjon for å sette den grafiske personnummeret.
     * @param social_number
     */
    void set_patient_social_number(QString social_number);

    /**
     * @brief Funksjon for å sette den grafiske doktor Id.
     * @param id
     */
    void set_doctorId(int id);

    /**
     * @brief Funksjon for å sette den grafiske doctornavn.
     * @param name
     */
    void set_doctorName(QString name);

    /**
     * @brief Funksjon for å sette QListWidget med tid når dialogen starter. Med kondisjon om tiden eksisterer fra før eller ikke.
     * @param vector_time
     */
    void set_listTime(vector<string> *vector_time);

    /**
     * @brief Funksjon for å sette klasse vektoren.
     * @param time
     */
    void set_time_vector(vector<string> *time);

private slots:
    /**
     * @brief Når godkjent knappen blir trykket, blir en appointment objekt opprettet og lagret til database.
     */
    void on_buttonBox_accepted();

    /**
     * @brief Når Dato blir endret, så sjekkes det om det finnes eksisterende tidspunkter.
     */
    void on_date_userDateChanged();

private:
    Ui::AddAppointmentDialog *ui;
    vector<string> *time_vector;
    int patient_id_;
    int doctor_id_;
};

#endif // ADDAPPOINTMENTDIALOG_H
