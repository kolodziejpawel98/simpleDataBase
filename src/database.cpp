#include "database.hpp"

bool Database::add(const Student &student)
{
    auto studentIndex = std::find_if(students.begin(), students.end(), [student](const Student &s)
                                     { return student.pesel == s.pesel; });
    if (studentIndex != students.end())
    {
        return false;
    }
    else
    {
        students.push_back(student);
        return true;
    }
}

bool Database::remove(const Student &student)
{
    auto studentIndex = std::find_if(students.begin(), students.end(), [student](const Student &s)
                                     { return student.pesel == s.pesel; });
    if (studentIndex == students.end())
    {
        return false;
    }
    else
    {
        students.erase(studentIndex);
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

void Database::printStudent(int index)
{
    std::cout << "#    name: " << students.at(index).name << "\n"
              << "# surname: " << students.at(index).surname << std::endl;
}

void Database::print()
{

    std::cout << "=============================\n";
    for (const auto &student : students)
    {
        std::cout << "# " << student.name << ", " << student.surname << " #" << std::endl;
    }
    std::cout << "=============================\n";
}