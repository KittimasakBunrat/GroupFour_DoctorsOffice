#ifndef REGISTERAPPOINTMENT_H
#define REGISTERAPPOINTMENT_H

#include <QMainWindow>

namespace Ui {
class RegisterAppointment;
}

class RegisterAppointment : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterAppointment(QWidget *parent = 0);
    ~RegisterAppointment();

private slots:
    void on_registerButton_clicked();

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::RegisterAppointment *ui;
};

#endif // REGISTERAPPOINTMENT_H
