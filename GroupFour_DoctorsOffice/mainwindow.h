#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "registerappointment.h"
#include "doctor.h"
#include "patient.h"
#include "dialog.h"
#include <vector>
#include <string>
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
<<<<<<< HEAD
//    struct Appointment;
=======
    struct Appointment;

    vector<Appointment> getAppointments();
    void addAppointment(Appointment &appointment);

>>>>>>> f8043197a3bab7c0ca9f147ed7c2ef7082f96705
    ~MainWindow();

private:
    RegisterAppointment *registerAppointmentWindow;
    MainWindow *mainWindow;
   // vector<Appointment> v_appointments_;

private slots:

    void on_pushButton_clicked();
    void openRegisterAppointment();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
};

#endif // MAINWINDOW_H
