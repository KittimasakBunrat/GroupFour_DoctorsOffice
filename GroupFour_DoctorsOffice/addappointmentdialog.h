#ifndef ADDAPPOINTMENTDIALOG_H
#define ADDAPPOINTMENTDIALOG_H

#include <QDialog>
#include "patient.h"

namespace Ui {
class AddAppointmentDialog;
}

class AddAppointmentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppointmentDialog(QWidget *parent = 0);
    ~AddAppointmentDialog();
    void set_patientId(int id);
    void set_patientName(QString name);


private:
    Ui::AddAppointmentDialog *ui;
    Patient *patient;
};

#endif // ADDAPPOINTMENTDIALOG_H
