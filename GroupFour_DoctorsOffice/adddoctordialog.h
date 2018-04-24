#ifndef ADDDOCTORDIALOG_H
#define ADDDOCTORDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "constants.h"
#include "dbhelper.h"

namespace Ui {
class AddDoctorDialog;
}

/**
 * @brief Denne klassen har hovedansvaret å kontrollere doctordialog for å legge doctor objekt i databasen. Og klassen extender QDialog.
 */
class AddDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Konstruktør for klassen som tar inn QWidget som parameter.
     * @param parent
     */
    explicit AddDoctorDialog(QWidget *parent = 0);
    /**
     * @brief Destruktor for klassen.
     */
    ~AddDoctorDialog();

private slots:
    /**
     * @brief Når godkjent knappen blir trykket, så skapes det ett nytt doktor objekt og lagres i databasen.
     */
    void on_add_doctor_buttonBox_accepted();

    /**
     * @brief Når avbryt knappen blir trykket, så lukkes dialogen.
     */
    void on_add_doctor_buttonBox_rejected();

signals:
    /**
     * @brief Signal for når doctor knappen blir trykket.
     */
    void accept_doctor_button_clicked();

private:
    Ui::AddDoctorDialog *ui;
};

#endif // ADDDOCTORDIALOG_H
