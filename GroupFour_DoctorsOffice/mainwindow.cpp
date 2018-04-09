#include "doctor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

struct MainWindow::Appointment
{
    Appointment(const Doctor &doctor, const Patient &patient):
        Doctor(doctor), Patient(patient),
    {

    }

    Doctor doctor;
    Patient patient;
    //Date??
};

void MainWindow::openRegisterAppointment()
{
    registerAppointmentWindow = new RegisterAppointment();

    registerAppointmentWindow->show();
    mainWindow->hide();
}

void MainWindow::on_pushButton_clicked()
{
    openRegisterAppointment();
}
