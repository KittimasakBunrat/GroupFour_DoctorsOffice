#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "constants.h"
#include "dbhelper.h"

namespace Ui {
class AddPatientDialog;
}

class AddPatientDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddPatientDialog(QWidget *parent = 0);
    ~AddPatientDialog();

private slots:
    void on_add_patient_buttonBox_accepted();

    void on_add_patient_buttonBox_rejected();

signals:
    void accept_patient_button_clicked();

private:
    Ui::AddPatientDialog *ui;
    vector<Doctor> *v_doctors_;
    QString doctors_first_name_;
    QString doctors_last_name_;
    int employee_id_;
};
#endif // ADDPATIENTDIALOG_H
