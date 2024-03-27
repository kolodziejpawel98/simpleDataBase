#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test
{ // common data for all test suites
    Database db;
    std::vector<Student> students = {{"Adam",
                                      "Kowalski",
                                      "ul. Dobra 13 00 - 200 Warszawa",
                                      11,
                                      "11111",
                                      Gender::Male},
                                     {"Adam",
                                      "Nowak",
                                      "ul. Zla 13 00 - 200 Krakow",
                                      22,
                                      "22222",
                                      Gender::Male}};

    std::string expectedStudent(int index)
    {
        return students.at(index).show();
    }
};

TEST_F(DatabaseTest, CanAddStudentToDb)
{

    EXPECT_TRUE(db.add(students.at(0)));
}

TEST_F(DatabaseTest, CanAddSameStudentToDb)
{
    EXPECT_TRUE(db.add(students.at(0)));
    EXPECT_FALSE(db.add(students.at(0)));
}

TEST_F(DatabaseTest, DisplayEmptyDb)
{
    EXPECT_EQ(db.show(), "");
}

TEST_F(DatabaseTest, DisplayNonEmptyDbWithoutGender)
{
    db.add(students.at(0));
    EXPECT_EQ(db.show(), expectedStudent(0));
}

TEST_F(DatabaseTest, DisplayNonEmptyDbWithoutGenderAddPersonTwice)
{
    db.add(students.at(0));
    db.add(students.at(0));
    EXPECT_EQ(db.show(), expectedStudent(0));
}

TEST_F(DatabaseTest, RemoveStudents)
{
    db.add(students.at(0));
    db.add(students.at(1));
    db.remove(students.at(0));
    EXPECT_EQ(db.show(), expectedStudent(1));

    db.remove(students.at(0));
    EXPECT_EQ(db.show(), expectedStudent(1));

    db.remove(students.at(1));
    EXPECT_EQ(db.show(), "");
}

TEST_F(DatabaseTest, PrintWholeDbContent)
{
    db.add(students.at(0));
    db.add(students.at(1));
    db.print();
}
