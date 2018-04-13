#ifndef CREATENEWAPPOINTMENT_H
#define CREATENEWAPPOINTMENT_H
#include "patient.h"

#include <QDialog>

namespace Ui {
class CreateNewAppointment;
}

class CreateNewAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit CreateNewAppointment(QWidget *parent = 0);
    ~CreateNewAppointment();

    void setFirstName(QString firstName);
    void setLastName(QString lastName);
    void setSocialNumber(int socialNumber);
    void setPhoneNumber(int phoneNumber);
    void setPatient(Patient* patient);


    Patient getPatient();


private:
    Ui::CreateNewAppointment *ui;
    Patient *patient;
};

#endif // CREATENEWAPPOINTMENT_H
