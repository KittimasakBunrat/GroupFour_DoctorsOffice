#include "addappointmentnotedialog.h"
#include "ui_addappointmentnotedialog.h"

AddAppointmentNoteDialog::AddAppointmentNoteDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAppointmentNoteDialog)
{
    ui->setupUi(this);
}

AddAppointmentNoteDialog::~AddAppointmentNoteDialog()
{
    delete ui;
}
