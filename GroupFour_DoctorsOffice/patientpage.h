#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H
#include "addappointmentdialog.h"

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
    void setSocialNumber(int socialNumber);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientPage *ui;
    AddAppointmentDialog *add_appointment;
};

#endif // PATIENTPAGE_H
