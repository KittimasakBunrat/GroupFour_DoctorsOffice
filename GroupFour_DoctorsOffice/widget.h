#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"
#include <QListWidgetItem>

#include <QWidget>

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
    void on_listWidget_Doctors_itemActivated(QListWidgetItem *item);

private:
    Ui::Widget *ui;
    vector<Doctor> *doctors;
};

static string BuildDoctorNamespace(Doctor *doctor);

#endif // WIDGET_H
