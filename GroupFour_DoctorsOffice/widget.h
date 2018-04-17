#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"
#include <QListWidgetItem>
#include "doctorpage.h"
#include "patientpage.h"
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include <QWidget>
#include <QtGui>
#include <QtCore>
#include <string>
#include <sstream>
#include "dbhelper.h"
#include "constants.h"
#include <QApplication>

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

    void on_button_AddPatient_clicked();

    void on_button_AddDoctor_clicked();

private:
    Ui::Widget *ui;
    vector<Doctor> *doctors;
    vector<Patient> *patients;
    DoctorPage *doctorPage;
    PatientPage *patientPage;
    AddPatientDialog *add_patient_dialog_;
    AddDoctorDialog *add_doctor_dialog_;
};

/*static const QString db_path { "C:/Sqlite/office.db" };
static const QString doctors_table { "doctors" };
static const QString patients_table { "patients" };
static const QString appointments_table { "appointments" };*/

static string BuildDoctorNamespace(Doctor *doctor);
static string BuildPatientNamespace(Patient *patient);

//fjern
vector<Patient> getPatients();

#endif // WIDGET_H
