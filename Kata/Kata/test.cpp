#include "pch.h"

using namespace ::testing;
using namespace std;

string convert(unsigned int arabic)
{
	const auto arabicToRomanConversions = {
	make_pair(1000u, "M"),
	make_pair(900u, "CM"),
	make_pair(500u, "D"),
	make_pair(400u, "CD"),
	make_pair(100u, "C"),
	make_pair(90u, "XC"),
	make_pair(50u, "L"),
	make_pair(40u, "XL"),
	make_pair(10u, "X"),
	make_pair(9u, "IX"),
	make_pair(5u, "V"),
	make_pair(4u, "IV"),
	make_pair(1u, "I")
	};

	string roman{ "" };
	for (auto arabicToRoman: arabicToRomanConversions)
		while (arabic >= arabicToRoman.first)
		{
			roman += arabicToRoman.second;
			arabic -= arabicToRoman.first;
		}
	return roman;
}

TEST(RomanConverter, CanConvertPositiveDigits)
{
	EXPECT_EQ(convert(1), "I");
	EXPECT_EQ(convert(2), "II");
	EXPECT_EQ(convert(3), "III");
	EXPECT_EQ(convert(4), "IV");
	EXPECT_EQ(convert(5), "V");
	EXPECT_EQ(convert(10), "X");
	EXPECT_EQ(convert(11), "XI");
	EXPECT_EQ(convert(12), "XII");
	EXPECT_EQ(convert(13), "XIII");
	EXPECT_EQ(convert(20), "XX");
	EXPECT_EQ(convert(50), "L");
	EXPECT_EQ(convert(80), "LXXX");
	EXPECT_EQ(convert(100), "C");
	EXPECT_EQ(convert(288), "CCLXXXVIII");
	EXPECT_EQ(convert(2999), "MMCMXCIX");
	EXPECT_EQ(convert(3447), "MMMCDXLVII");
	EXPECT_EQ(convert(1513), "MDXIII");
}