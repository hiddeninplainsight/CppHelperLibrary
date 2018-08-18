#ifndef CPPHELPERLIBRARY_OSTREAM_INDENT_H
#define CPPHELPERLIBRARY_OSTREAM_INDENT_H

#include <ostream>
#include <streambuf>
#include <string>

namespace chl
{
	class ostream_indent : public ::std::streambuf
	{
		bool is_at_start_of_line{true};
		::std::string indent;
		::std::streambuf* destination_streambuf;
		::std::ostream* owning_ostream;

	public:
		explicit ostream_indent(::std::streambuf* destination,
								::std::string::size_type indent = 4);
		explicit ostream_indent(::std::ostream& destination,
								::std::string::size_type indent = 4);
		~ostream_indent() override;

	protected:
		int overflow(int ch) override;
	};
}

#endif  // CPPHELPERLIBRARY_OSTREAM_INDENT_H
