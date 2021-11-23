#include "pch.h"
#include <string>

using namespace ::testing;
using namespace std;

string fizzBuzz(int value) {
	string result;

	if (value <= 0)
		return result += to_string(value);

	const auto isDivisibleBy = {
		make_pair(3u, "Fizz"),
		make_pair(5u, "Buzz"),
		make_pair(7u, "Whizz")
	};

	const auto containsInteger = {
		make_pair("3", "Fizz"),
	};

	for each (auto var in isDivisibleBy)
		if (value % var.first == 0)
			result += var.second;

	if (result.empty())
	{
		string comparison = to_string(value);
		for each (auto var in containsInteger)
		{
			string str = var.first;
			int i = comparison.find(str);
			if (i >= 0)
				result += var.second;
		}

		if (result.empty())
			result += to_string(value);
	}
	return result;
}

TEST(fizzBuzz, IsDivisibleBy)
{
	EXPECT_EQ(fizzBuzz(0), "0");
	EXPECT_EQ(fizzBuzz(1), "1");
	EXPECT_EQ(fizzBuzz(2), "2");
	EXPECT_EQ(fizzBuzz(3), "Fizz");
	EXPECT_EQ(fizzBuzz(4), "4");
	EXPECT_EQ(fizzBuzz(5), "Buzz");
	EXPECT_EQ(fizzBuzz(6), "Fizz");
	EXPECT_EQ(fizzBuzz(7), "Whizz");
	EXPECT_EQ(fizzBuzz(13), "Fizz");
	EXPECT_EQ(fizzBuzz(14), "Whizz");
	EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
	EXPECT_EQ(fizzBuzz(23), "Fizz");
	EXPECT_EQ(fizzBuzz(53), "Fizz");
	EXPECT_EQ(fizzBuzz(333), "Fizz");
	EXPECT_EQ(fizzBuzz(443), "Fizz");
}