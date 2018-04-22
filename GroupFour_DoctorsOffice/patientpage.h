#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H
#include "addappointmentdialog.h"
#include "patienthistory.h"
#include "doctor.h"
#include "constants.h"

#include <QDialog>

namespace Ui {
class PatientPage;
}

class PatientPage : public QDialog
{
    Q_OBJECT

public:
    explicit PatientPage(QWidget *parent = 0);
    ~PatientPage();

    void setFullName(QString name);
    void setDoctorID(int doctorID);
    void setPhoneNumber(int phoneNumber);
    void setSocialNumber(long long socialNumber);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_pressed();

private:
    Ui::PatientPage *ui;
    AddAppointmentDialog *add_appointment;
    PatientHistory *patient_history;
};

#endif // PATIENTPAGE_H
