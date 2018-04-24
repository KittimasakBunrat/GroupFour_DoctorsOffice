#ifndef DOCTORPAGE_H
#define DOCTORPAGE_H
#include "doctor.h"

#include <QDialog>

namespace Ui {

/**
 *@brief Dette er hovedklassen for doktorpage. Funksjonene under vil beskrive 
 * hvordan doktorpagen vil bli opprettet, og hva som blant annet blir vist frem.
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

    /**
     * @brief Destruktor for klassen.
     */
    ~DoctorPage();

    /**
     * @brief setFullName er en set metode for å sette hele navnet til en doktor som du 
     * får fra en valgt doktor når du velger en doktor fra parent widget.
     * @param name blir sendt inn fra valgt doktor som blir navnet som vises frem. 
     */

    void setFullName(QString name);

    /**
     * @brief setPhoneNumber er en set metode for å sette telefonNR til en doktor. 
     * @param phonenumber blir sendt inn fra valgt doktor. Dette blir vist frem som telefonnr
     */

    void setPhoneNumber(int phoneNumber);

    /**
     * @brief setEmployeeNumber er en set metode for å sette employeenumber til en doktor. 
     * @param employeenumber som blir sendt inn fra valgt doktor. Denne variabelen blir satt som det
     * som blir vist frem i vinduet.
     */

    void setEmployeeNumber(int employeeNumber);


private:
    Ui::DoctorPage *ui;
};

#endif // DOCTORPAGE_H
