#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "constants.h"
#include "dbhelper.h"

namespace Ui {
class AddPatientDialog;
}

/**
 * @brief Denne klassen har hovedansvaret å kontrollere patientdialog for å legge pasient objekt i databasen. Og klassen extender QDialog.
 */
class AddPatientDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktør for klassen som tar inn QWidget som parameter.
     * @param parent
     */
    explicit AddPatientDialog(QWidget *parent = 0);

    /**
     * @brief Destruktor for klassen.
     */
    ~AddPatientDialog();

private slots:
    /**
     * @brief Når godkjent knappen blir trykket, så skapes det ett nytt pasient objekt og lagres i databasen.
     */
    void on_add_patient_buttonBox_accepted();

    /**
     * @brief Når avbryt knappen blir trykket, så lukkes dialogen.
     */
    void on_add_patient_buttonBox_rejected();

signals:
    /**
     * @brief Signal for når pasient knapp blir trykket.
     */
    void accept_patient_button_clicked();

private:
    Ui::AddPatientDialog *ui;
    vector<Doctor> *v_doctors_;
    QString doctors_first_name_;
    QString doctors_last_name_;
    int employee_id_;
};
#endif // ADDPATIENTDIALOG_H
