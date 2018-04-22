#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"
#include <QListWidgetItem>
#include "doctorpage.h"
#include "patientpage.h"
#include "addpatientdialog.h"
#include "adddoctordialog.h"
#include "addappointmentnotedialog.h"
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
    void filter_doctors(QString filter_string);
    void filter_patients(QString filter_string);
    void hide_all_doctors();
    void hide_all_patients();


private slots:
    void on_button_SelectDoctor_clicked();
    void on_listWidget_Doctors_itemClicked(QListWidgetItem *item);
    void on_button_SelectPatient_clicked();
    void on_button_AddPatient_clicked();
    void on_button_AddDoctor_clicked();
    void refresh_lists();
    void on_filter_doctor_edit_textChanged(const QString &arg1);
    void on_filter_patient_edit_textChanged(const QString &arg1);
    void list_doctor_time(int doctorId);

    void on_listWidget_Patients_itemClicked(QListWidgetItem *item);

    void on_listWidget_DoctorTime_itemClicked(QListWidgetItem *item);

    //void on_pushButton_clicked();

    void on_button_SelectAppointment_clicked();

private:
    Ui::Widget *ui;
    vector<Doctor> *doctors;
    vector<Patient> *patients;
    DoctorPage *doctorPage;
    PatientPage *patientPage;
    AddPatientDialog *add_patient_dialog_;
    AddDoctorDialog *add_doctor_dialog_;
    AddAppointmentNoteDialog *add_appointment_note_dialog_;
};

static string BuildDoctorNamespace(Doctor *doctor);
static string BuildPatientNamespace(Patient *patient);

#endif // WIDGET_H
