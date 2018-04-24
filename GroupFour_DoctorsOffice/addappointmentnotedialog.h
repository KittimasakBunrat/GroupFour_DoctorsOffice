#ifndef ADDAPPOINTMENTNOTEDIALOG_H
#define ADDAPPOINTMENTNOTEDIALOG_H

#include <QDialog>
#include "dbhelper.h"
#include <QMessageBox>
#include "constants.h"

namespace Ui {
class AddAppointmentNoteDialog;
}

/**
 * @brief Denne klassen har hovedansvaret å kontrollere notedialig for når notater skal bli lagt til i appointments. Og klassen extender QDialog.
 */
class AddAppointmentNoteDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktør for klassen som tar inn QWidget som parameter.
     * @param parent
     */
    explicit AddAppointmentNoteDialog(QWidget *parent = 0);

    /**
     * @brief Destruktor for klassen.
     */
    ~AddAppointmentNoteDialog();

    /**
     * @brief Funksjon for å sette det grafiske appointment tid.
     * @param appointmentTime
     */
    void setAppointmentTime(QString appointmentTime);

    /**
     * @brief Funksjon for å sette det grafiske appointment dato.
     * @param appointmentDate
     */
    void setAppointmentDate(QString appointmentDate);

    /**
     * @brief Funksjon for sette det grafiske doctor info.
     * @param id
     */
    void setDoctorInfo(int id);

    /**
     * @brief Funksjon for å sette det grafiske pasient info.
     * @param patient_social_number
     */
    void setPatientInfo(int patient_social_number);


private slots:
    /**
     * @brief Når godkjent knappen blir trykket, så blir det laget ett nytt appointment objekt med note og oppdatere databasen med notes.
     */
    void on_buttonBox_accepted();

private:
    Ui::AddAppointmentNoteDialog *ui;
    int patient_social_number;
};

#endif // ADDAPPOINTMENTNOTEDIALOG_H
