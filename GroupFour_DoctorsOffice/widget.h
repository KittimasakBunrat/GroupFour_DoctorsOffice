#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"
#include <QListWidgetItem>
#include "doctorpage.h"
#include "patientpage.h"
#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <string>
#include <sstream>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_button_SelectDoctor_clicked();
    void on_listWidget_Doctors_itemClicked(QListWidgetItem *item);

    void on_button_SelectPatient_clicked();

private:
    Ui::Widget *ui;
    vector<Doctor> *doctors;
    vector<Patient> *patients;
    DoctorPage *doctorPage;
    PatientPage *patientPage;
};

static string BuildDoctorNamespace(Doctor *doctor);
static string BuildPatientNamespace(Patient *patient);

#endif // WIDGET_H
