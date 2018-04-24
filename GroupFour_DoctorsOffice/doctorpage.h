#ifndef DOCTORPAGE_H
#define DOCTORPAGE_H
#include "doctor.h"

#include <QDialog>

namespace Ui {

/**
 *@brief Dette er en klasse for at oprette et DoctorPage objekt
 */

class DoctorPage;
}
/**
 * @brief DoctorPage klassen som extender QDialog klassen
 */
class DoctorPage : public QDialog
{
    Q_OBJECT

public:

    /**
     * @brief Konstruktøren til DoctorPage
     * @param tar imot parent som er et QWidget objekt
     */

    explicit DoctorPage(QWidget *parent = 0);
    ~DoctorPage();

    /**
     * @brief setFullName
     * @param setter name variabel
     */

    void setFullName(QString name);

    /**
     * @brief setPhoneNumber
     * @param setter phoneNumber variabel
     */

    void setPhoneNumber(int phoneNumber);

    /**
     * @brief setEmployeeNumber
     * @param setter employeeNumber variabel
     */

    void setEmployeeNumber(int employeeNumber);


private:
    Ui::DoctorPage *ui;
};

#endif // DOCTORPAGE_H
