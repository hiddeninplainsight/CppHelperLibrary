#include <chl/ostream_indent.h>

#include <gtest/gtest.h>

#include <sstream>

using namespace ::std;

TEST(ostream_indent, indenting_with_default_number_of_spaces_with_no_new_line)
{
	stringstream stream;
	chl::ostream_indent indent{stream};

	stream << 1;

	EXPECT_EQ("    1", stream.str());
}

TEST(ostream_indent, indenting_with_default_number_of_spaces_with_new_line)
{
	stringstream stream;
	chl::ostream_indent indent{stream};

	stream << 1 << "\n" << 2;

	EXPECT_EQ("    1\n    2", stream.str());
}

TEST(ostream_indent, indenting_with_custom_number_of_spaces)
{
	stringstream stream;
	chl::ostream_indent indent{stream, 2};

	stream << 1 << "\n" << 2;

	EXPECT_EQ("  1\n  2", stream.str());
}

TEST(ostream_indent, two_ostream_indents_can_be_combined)
{
	stringstream stream;
	chl::ostream_indent indent{stream, 2};
	chl::ostream_indent indent2{stream, 2};

	stream << 1 << "\n" << 2;

	EXPECT_EQ("    1\n    2", stream.str());
}
