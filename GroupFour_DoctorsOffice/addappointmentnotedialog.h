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
    ~AddAppointmentNoteDialog();

private:
    Ui::AddAppointmentNoteDialog *ui;
};

#endif // ADDAPPOINTMENTNOTEDIALOG_H
