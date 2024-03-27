#pragma once
#include "student.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

class Database
{
public:
    Database() = default;
    bool add(const Student &student);
    bool remove(const Student &student);
    std::string show();
    void printStudent(int index);

private:
    std::vector<Student> students;
};