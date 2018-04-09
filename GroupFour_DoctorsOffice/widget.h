#ifndef WIDGET_H
#define WIDGET_H
#include "doctor.h"

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

private:
    Ui::Widget *ui;
};

static string buildDoctorNamespace(Doctor *doctor);

#endif // WIDGET_H
