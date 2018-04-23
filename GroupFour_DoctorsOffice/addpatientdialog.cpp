#include "addpatientdialog.h"
#include "ui_addpatientdialog.h"
#include <sstream>
#include <QMessageBox>
#include <QStringList>
#include <iostream>

using namespace std;
AddPatientDialog::AddPatientDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPatientDialog)
{
    ui->setupUi(this);


    DbHelper db(GLOBAL_CONST_db_path);
    if(db.isOpen())
    {
        v_doctors_ ={ new vector<Doctor>(*db.get_doctors()) };
    }

    for(unsigned int i = 0; i < v_doctors_->size(); i++)
    {
        employee_id_ ={ v_doctors_->at(i).get_employee_number() };
        doctors_first_name_ ={  v_doctors_->at(i).get_first_name() };
        doctors_last_name_ ={  v_doctors_->at(i).get_last_name() };
        QString doctor_info { QString::number(employee_id_) + " : " + doctors_first_name_ + " " + doctors_last_name_ };
        ui->doctor_combo_box->addItem(doctor_info);
    }
}

AddPatientDialog::~AddPatientDialog()
{
    delete ui;
}

void AddPatientDialog::on_add_patient_buttonBox_accepted()
{
    if(ui->social_number_edit->text().isEmpty()
            || ui->first_name_edit->text().isEmpty()
            || ui->last_name_edit->text().isEmpty()
            || ui->phone_number_edit->text().isEmpty())

    {
        QMessageBox::warning(this, "validation failed", "Pleae fill out all empty fields");
    }
    else
    {
        long long social_number { ui->social_number_edit->text().toLongLong() };
        QString first_name { ui->first_name_edit->text() };
        QString last_name { ui->last_name_edit->text() };
        QString comboBox {ui->doctor_combo_box->currentText()};
        int phone_number { ui->phone_number_edit->text().toInt() };

        QStringList comboBoxSplit = comboBox.split(" : ");
        QString employee_id_split = comboBoxSplit.first();
        int employee_id = employee_id_split.toInt();

        DbHelper db(GLOBAL_CONST_db_path);
        if (db.isOpen())
        {
            Patient *patient = new Patient(0, social_number,first_name,last_name,phone_number, employee_id);
            db.create_new_patient(*patient);
            emit this->accept_patient_button_clicked();
            QMessageBox::information(this,tr("Success"),tr("Patient added"));
            qDebug() << "Database OK";
        }
        else
        {
            qDebug() << "Database not connected";
        }
    }
}

void AddPatientDialog::on_add_patient_buttonBox_rejected()
{

}
