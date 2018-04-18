#ifndef ADDPATIENTDIALOG_H
#define ADDPATIENTDIALOG_H

#include <QDialog>
#include <constants.h>
#include "dbhelper.h"
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
    void accept_button_clicked();

private:
    Ui::AddPatientDialog *ui; 
};

#endif // ADDPATIENTDIALOG_H
