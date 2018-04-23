#ifndef ADDAPPOINTMENTNOTEDIALOG_H
#define ADDAPPOINTMENTNOTEDIALOG_H

#include <QDialog>

namespace Ui {
class AddAppointmentNoteDialog;
}

class AddAppointmentNoteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAppointmentNoteDialog(QWidget *parent = 0);
    void setAppointmentTime(QString appointmentTime);
    void setDoctorInfo(int id);
    void setPatientInfo(int id);
    ~AddAppointmentNoteDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::AddAppointmentNoteDialog *ui;
};

#endif // ADDAPPOINTMENTNOTEDIALOG_H
