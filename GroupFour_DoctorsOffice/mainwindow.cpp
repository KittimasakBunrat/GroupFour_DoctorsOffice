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
    Appointment(const Doctor &doctor_, const Patient &patient_)
    {
        Doctor doctor = doctor_;
        Patient patient = patient_;
    }
};

vector<MainWindow::Appointment> MainWindow::getAppointments()
{
    return v_appointments_;
}

void MainWindow::addAppointment(Appointment &appointment)
{
    getAppointments().push_back(appointment);
}


void MainWindow::on_pushButton_clicked()
{
    dialog = new Dialog(this);
    dialog->show();
}
