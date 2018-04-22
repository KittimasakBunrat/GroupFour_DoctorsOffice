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
    QString first_name { ui->first_name_edit->text() };
    QString last_name { ui->last_name_edit->text() };
    int phone_number { ui->phone_number_edit->text().toInt() };

    DbHelper db(GLOBAL_CONST_db_path);
    if (db.isOpen())
    {
        Doctor *doctor = new Doctor(first_name, last_name, phone_number, 0);
        db.create_new_doctor(*doctor);
        emit this->accept_doctor_button_clicked();
        QMessageBox::information(this,tr("Success"),tr("Doctor added"));
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
