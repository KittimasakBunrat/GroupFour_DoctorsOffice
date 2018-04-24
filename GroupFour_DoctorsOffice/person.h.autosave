#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;

/**
 * @brief Denne klassen er en klasse for å opprette objekt av en person.
 */
class Person
{
public:
    /**
     * @brief Person er Konstruktør for å opprette person objekt som tar imot 
     * parametere som er nevnt under
     * @param first_name er fornavnet på personen
     * @param last_name er etternavnet på personen
     * @param phone_number er telefonNR til personen
     */
    
    Person(QString first_name, QString last_name, int phone_number);
    /**
     * @brief Person er en standardkonstruktør
     */
    Person();
    
    /**
     * @brief get_first_name er en getter for firstname
     * @return returnerer firstname
     */
    
    QString get_first_name();
    
    /**
     * @brief get_last_name er en getter for lastname
     * @return returnerer lastname
     */
    
    QString get_last_name();
    
    /**
     * @brief get_phone_number er en getter for phone number
     * @return returnerer phonenumber
     */
    
    int get_phone_number();

protected:
    QString first_name_;
    QString last_name_;
    int phone_number_;
};

#endif // PERSON_H
