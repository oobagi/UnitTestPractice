/**
 * Unit Tests for Password class
 **/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
protected:
	PasswordTest() {}		   // constructor runs before each test
	virtual ~PasswordTest() {} // destructor cleans up after tests
	virtual void SetUp() {}	   // sets up before each test (after constructor)
	virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, count_leading_characters)
{
	Password pwd;
	EXPECT_EQ(1, pwd.count_leading_characters("Z"));
	EXPECT_EQ(2, pwd.count_leading_characters("ZZz"));
	EXPECT_EQ(4, pwd.count_leading_characters("aaaa"));
	EXPECT_EQ(1, pwd.count_leading_characters("zZZ"));
	EXPECT_EQ(3, pwd.count_leading_characters("!!!abc"));
	EXPECT_EQ(1, pwd.count_leading_characters("Zz"));
}

TEST(PasswordTest, has_mixed_case)
{
	Password pwd;
	EXPECT_TRUE(pwd.has_mixed_case("Zz"));
	EXPECT_TRUE(pwd.has_mixed_case("ZzZz"));
	EXPECT_TRUE(pwd.has_mixed_case("Aa1"));

	EXPECT_FALSE(pwd.has_mixed_case("ZZ"));
	EXPECT_FALSE(pwd.has_mixed_case("zz"));
	EXPECT_FALSE(pwd.has_mixed_case("a1"));
	EXPECT_FALSE(pwd.has_mixed_case("abc123"));
	EXPECT_FALSE(pwd.has_mixed_case(""));
	EXPECT_FALSE(pwd.has_mixed_case("ABC!@#"));
}
