#ifndef PATIENTHISTORY_H
#define PATIENTHISTORY_H

#include <QDialog>

namespace Ui {
class PatientHistory;
}

class PatientHistory : public QDialog
{
    Q_OBJECT

public:
    explicit PatientHistory(QWidget *parent = 0);
    ~PatientHistory();

private slots:
    void on_pushButton_pressed();

private:
    Ui::PatientHistory *ui;
};

#endif // PATIENTHISTORY_H
