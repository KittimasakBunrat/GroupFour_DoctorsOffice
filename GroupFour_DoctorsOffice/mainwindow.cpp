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
/*
struct MainWindow::Appointment
{
    Appointment(const Doctor &doctor, const Patient &patient):
        Doctor(doctor), Patient(patient),
    Appointment(const Doctor &doctor_, const Patient &patient_)
    {

        Doctor doctor = doctor_;
        Patient patient = patient_;
    }
<<<<<<< HEAD

    Doctor doctor;
    Patient patient;
    //Date??
};*/
=======
};
>>>>>>> f8043197a3bab7c0ca9f147ed7c2ef7082f96705

void MainWindow::openRegisterAppointment()
vector<MainWindow::Appointment> MainWindow::getAppointments()
{
    registerAppointmentWindow = new RegisterAppointment();
    return v_appointments_;
}

    registerAppointmentWindow->show();
    mainWindow->hide();
void MainWindow::addAppointment(Appointment &appointment)
{
    getAppointments().push_back(appointment);
}


void MainWindow::on_pushButton_clicked()
{
    openRegisterAppointment();
    dialog = new Dialog(this);
    dialog->show();
}
