#pragma once
#include "student.hpp"

class Database
{
public:
    Database() = default;
    bool add(const Student &student);
};