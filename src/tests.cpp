#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(CheckStructure, CanAddStudentToDb)
{
  Student adam{"Adam",
               "Kowalski",
               "ul. Dobra 13 00 - 200 Warszawa ",
               123456,
               "23121311123",
               Gender::Male};
  Database db;
  EXPECT_TRUE(db.add(adam));
  EXPECT_FALSE(db.add(adam));
}