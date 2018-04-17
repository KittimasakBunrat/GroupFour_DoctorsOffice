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
    int social_number { ui->social_number_edit->text().toInt() };
    QString first_name { ui->first_name_edit->text() };
    QString last_name { ui->last_name_edit->text() };
    int phone_number { ui->phone_number_edit->text().toInt() };
    // TODO: LEGG INN ID FRA LEGE COMBOBOX

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        Patient *patient = new Patient(social_number,first_name,last_name,phone_number, 9);
        db.create_new_patient(*patient);
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }
}

void AddPatientDialog::on_add_patient_buttonBox_rejected()
{

}
