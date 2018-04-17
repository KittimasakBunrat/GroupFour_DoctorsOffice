#include "adddoctordialog.h"
#include "ui_adddoctordialog.h"

AddDoctorDialog::AddDoctorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDoctorDialog)
{
    ui->setupUi(this);
}

AddDoctorDialog::~AddDoctorDialog()
{
    delete ui;
}

void AddDoctorDialog::on_add_doctor_buttonBox_accepted()
{
    QString first_name { ui->first_name_doctor_edit->text() };
    QString last_name { ui->last_name_doctor_edit->text() };
    int social_number { ui->social_number_doctor_edit->text().toInt() };
    int phone_number { ui->phone_number_doctor_edit->text().toInt() };

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        db.create_new_doctor(first_name, last_name, social_number, phone_number);
        qDebug() << "Database OK";
    }
    else
    {
        qDebug() << "Database not connected";
    }
}

void AddDoctorDialog::on_add_doctor_buttonBox_rejected()
{

}
