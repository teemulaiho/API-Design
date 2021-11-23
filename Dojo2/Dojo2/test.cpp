#include "pch.h"
#include <string>
#include <string_view>

using namespace std::literals;
using namespace ::testing;

static constexpr auto isDivisibleBy = {
	std::make_pair(3u, "Fizz"sv),
	std::make_pair(5u, "Buzz"sv),
	std::make_pair(7u, "Whizz"sv)
};
static constexpr auto containsInteger = {
	std::make_pair("3"sv, "Fizz"sv),
};

std::string IsDivisbleByPair(std::string result, int value)
{
	for (const auto& [divisor, name] : isDivisibleBy) {
		if (value % divisor == 0) {
			result += name;
		}
	}

	return result;
}

std::string ContainsValue(std::string result, int value)
{
	const std::string comparison = std::to_string(value);
	for (const auto& [needle, name] : containsInteger) {
		auto i = comparison.find(needle);
		if (i != std::string::npos) {
			result += name;
		}
	}

	return result;
}

std::string fizzBuzz(int value) {	
	if (value > 0) {
		std::string result;

		result = IsDivisbleByPair(result, value);

		if (result.empty()) {
			result = ContainsValue(result, value);
		}

		if (!result.empty())
		{
			return result;
		}
		else
			return std::to_string(value);
	}
	return std::to_string(value);	
}

TEST(fizzBuzz, HandlesUpToFour) {
	EXPECT_EQ(fizzBuzz(0), "0"sv);
	EXPECT_EQ(fizzBuzz(1), "1"sv);
	EXPECT_EQ(fizzBuzz(2), "2"sv);
	EXPECT_EQ(fizzBuzz(4), "4"sv);
}

TEST(fizzBuzz, HandlesFactorsOfThree) {
	EXPECT_EQ(fizzBuzz(3), "Fizz"sv);
	EXPECT_EQ(fizzBuzz(6), "Fizz"sv);
	EXPECT_EQ(fizzBuzz(333), "Fizz"sv);
}

TEST(fizzBuzz, HandlesFactorsOfFive) {
	EXPECT_EQ(fizzBuzz(5), "Buzz"sv);
	EXPECT_EQ(fizzBuzz(15), "FizzBuzz"sv);
}

TEST(fizzBuzz, HandlesFactorsOfSeven) {
	EXPECT_EQ(fizzBuzz(7), "Whizz"sv);
	EXPECT_EQ(fizzBuzz(14), "Whizz"sv);
}

TEST(fizzBuzz, ContainsThree) {
	EXPECT_EQ(fizzBuzz(13), "Fizz"sv);
	EXPECT_EQ(fizzBuzz(23), "Fizz"sv);
	EXPECT_EQ(fizzBuzz(53), "Fizz"sv);
	EXPECT_EQ(fizzBuzz(443), "Fizz"sv);
}
