#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient
{
public:
    Patient(string first_name, string last_name, int social_number, int phone_number);
    string get_first_name();
    string get_last_name();
    int get_social_number();
    int get_phone_number();

private:
    string first_name_;
    string last_name_;
    int social_number_;
    int phone_number_;
};

#endif // PATIENT_H
