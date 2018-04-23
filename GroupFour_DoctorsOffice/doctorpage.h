#ifndef DOCTORPAGE_H
#define DOCTORPAGE_H
#include "doctor.h"

#include <QDialog>

namespace Ui {

/**
 *@brief Dette er en klasse for at oprette et DoctorPage objekt.
 */

class DoctorPage;
}
/**
 * @brief DoctorPage klassen
 */
class DoctorPage : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Konstruktøren til DoctorPage
     * @param parent
     */
    explicit DoctorPage(QWidget *parent = 0);
    ~DoctorPage();

    /**
     * @brief setFullName
     * @param name
     */

    void setFullName(QString name);
    void setPhoneNumber(int phoneNumber);
    void setEmployeeNumber(int employeeNumber);


private:
    Ui::DoctorPage *ui;
};

#endif // DOCTORPAGE_H
