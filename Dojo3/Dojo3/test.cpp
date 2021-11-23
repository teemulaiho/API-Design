#include "pch.h"

bool CheckOutOfBounds(unsigned int year) {
	if (year < 1752) {
		return true;
	}

	return false;
}

bool IsLeapYear(unsigned int year)
{
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return true;
			}
		}

		return true;
	}

	return false;
}

// Gregorian Calendar?
bool checkForLeapYear(unsigned int year) {
	if (CheckOutOfBounds(year)) {
		return false;
	}

	return IsLeapYear(year);
}

TEST(checkForLeapYear, isLeapYear)
{
	EXPECT_EQ(checkForLeapYear(2001), false);
	EXPECT_EQ(checkForLeapYear(2000), true);
	EXPECT_EQ(checkForLeapYear(1996), true);
	EXPECT_EQ(checkForLeapYear(1900), true);
	EXPECT_EQ(checkForLeapYear(1751), false);
}