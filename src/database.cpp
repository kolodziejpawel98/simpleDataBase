#include "database.hpp"

bool Database::add(const Student &student)
{
    auto isStudentInDb = std::find_if(students.begin(), students.end(), [student](const Student &s)
                                      { return student.pesel == s.pesel; });
    if (isStudentInDb != students.end())
    {
        return false;
    }
    else
    {
        students.push_back(student);
        return true;
    }
}

std::string Database::show()
{
    if (students.size())
    {
        std::string studentAsRecord = {};
        studentAsRecord = students.at(0).name + " " + students.at(0).surname + "; " + students.at(0).adress + "; " + std::to_string(students.at(0).studentIndex) + "; " + students.at(0).pesel;
        return studentAsRecord;
    }
    else
    {
        return "";
    }
}