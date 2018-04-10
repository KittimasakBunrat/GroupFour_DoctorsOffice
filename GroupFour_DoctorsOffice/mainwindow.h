#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "doctor.h"
#include "patient.h"
#include "dialog.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    struct Appointment;

    vector<Appointment> getAppointments();
    void addAppointment(Appointment &appointment);

    ~MainWindow();

private:
    MainWindow *mainWindow;
    vector<Appointment> v_appointments_;

private slots:

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *dialog;
};

#endif // MAINWINDOW_H
