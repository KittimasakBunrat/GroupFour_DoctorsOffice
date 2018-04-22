#include "patienthistory.h"
#include "ui_patienthistory.h"

PatientHistory::PatientHistory(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PatientHistory)
{
    ui->setupUi(this);
}

PatientHistory::~PatientHistory()
{
    delete ui;
}

void PatientHistory::on_pushButton_pressed()
{
    this->close();
}
