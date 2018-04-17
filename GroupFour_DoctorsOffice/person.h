#ifndef PERSON_H
#define PERSON_H
#include <QString>
using namespace std;

class Person
{
public:
    Person(QString first_name, QString last_name, int phone_number);
    QString get_first_name();
    QString get_last_name();
    int get_phone_number();

protected:
    QString first_name_;
    QString last_name_;
    int phone_number_;
};

#endif // PERSON_H
