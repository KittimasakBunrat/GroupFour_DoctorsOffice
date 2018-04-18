#ifndef ADDDOCTORDIALOG_H
#define ADDDOCTORDIALOG_H

#include <QDialog>
#include <constants.h>
#include "dbhelper.h"

namespace Ui {
class AddDoctorDialog;
}

class AddDoctorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDoctorDialog(QWidget *parent = 0);
    ~AddDoctorDialog();

private slots:
    void on_add_doctor_buttonBox_accepted();

    void on_add_doctor_buttonBox_rejected();

signals:
    void accept_button_clicked();

private:
    Ui::AddDoctorDialog *ui;
};

#endif // ADDDOCTORDIALOG_H
