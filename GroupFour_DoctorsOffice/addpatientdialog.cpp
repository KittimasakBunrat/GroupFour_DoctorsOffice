#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"

AddPatientDialog::AddPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatientDialog)
{
    ui->setupUi(this);
}

AddPatientDialog::~AddPatientDialog()
{
    delete ui;
}

void AddPatientDialog::on_add_patient_buttonBox_accepted()
{

}

void AddPatientDialog::on_add_patient_buttonBox_rejected()
{

}
