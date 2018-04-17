#ifndef DOCTORPAGE_H
#define DOCTORPAGE_H
#include "doctor.h"

#include <QDialog>

namespace Ui {
class DoctorPage;
}

class DoctorPage : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorPage(QWidget *parent = 0);
    ~DoctorPage();

    void setFullName(QString name);
    void setSocialNumber(int socialNumber);
    void setPhoneNumber(int phoneNumber);
    //void setEmployeeNumber(int employeeNumber);


private:
    Ui::DoctorPage *ui;
};

#endif // DOCTORPAGE_H
