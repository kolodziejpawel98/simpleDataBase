#pragma once
#include <string>

enum class Gender
{
    Male,
    Female
};

class Student
{
public:
    Student(std::string name,
            std::string surname,
            std::string adress,
            int studentIndex,
            std::string pesel,
            Gender gender);

    std::string show();

private:
    std::string name;
    std::string surname;
    std::string adress;
    int studentIndex;
    std::string pesel;
    Gender gender;

    friend class Database;
};