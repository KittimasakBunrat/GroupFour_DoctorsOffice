#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "registerappointment.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    RegisterAppointment *registerAppointmentWindow;
    MainWindow *mainWindow;

private slots:
    void on_pushButton_clicked();
    void openRegisterAppointment();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
