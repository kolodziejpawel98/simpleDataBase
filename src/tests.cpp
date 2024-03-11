#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test
{ // common data for all test suites
    Database db;
};

// remove
TEST_F(DatabaseTest, CanAddStudentToDb)
{
    Student adam{"Adam",
                 "Kowalski",
                 "ul. Dobra 13 00 - 200 Warszawa",
                 123456,
                 "23121311123",
                 Gender::Male};

    EXPECT_TRUE(db.add(adam));
}

TEST_F(DatabaseTest, CanAddSameStudentToDb)
{
    Student adam{"Adam",
                 "Kowalski",
                 "ul. Dobra 13 00 - 200 Warszawa",
                 123456,
                 "23121311123",
                 Gender::Male};

    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}

TEST_F(DatabaseTest, DisplayEmptyDb)
{
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDbWithoutGender)
{
    Student adam{"Adam",
                 "Kowalski",
                 "ul. Dobra 13 00 - 200 Warszawa",
                 123456,
                 "23121311123",
                 Gender::Male};

    db.add(adam);
    // check adding the same person twice
    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 13 00 - 200 Warszawa; 123456; 23121311123";
    EXPECT_EQ(content, expected);
}