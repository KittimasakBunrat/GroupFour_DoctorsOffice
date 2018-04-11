#ifndef PATIENTPAGE_H
#define PATIENTPAGE_H

#include <QDialog>

namespace Ui {
class PatientPage;
}

class PatientPage : public QDialog
{
    Q_OBJECT

public:
    explicit PatientPage(QWidget *parent = 0);
    ~PatientPage();

    void setFullName(QString name);
    void setSocialNumber(int socialNumber);
    void setPhoneNumber(int phoneNumber);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientPage *ui;
};

#endif // PATIENTPAGE_H
