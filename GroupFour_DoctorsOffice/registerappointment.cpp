#include "registerappointment.h"
#include "ui_registerappointment.h"

RegisterAppointment::RegisterAppointment(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterAppointment)
{
    ui->setupUi(this);
}

RegisterAppointment::~RegisterAppointment()
{
    delete ui;
}

void RegisterAppointment::on_registerButton_clicked()
{

}

void RegisterAppointment::on_listView_clicked(const QModelIndex &index)
{

}
