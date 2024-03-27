#include "student.hpp"

Student::Student(std::string name,
                 std::string surname,
                 std::string adress,
                 int studentIndex,
                 std::string pesel,
                 Gender gender) : name(name),
                                  surname(surname),
                                  adress(adress),
                                  studentIndex(studentIndex),
                                  pesel(pesel),
                                  gender(gender) {}

std::string Student::show()
{
    return name + " " + surname + "; " + adress + "; " + std::to_string(studentIndex) + "; " + pesel;
}