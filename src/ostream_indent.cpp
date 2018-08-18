#include "chl/ostream_indent.h"

namespace chl
{
	ostream_indent::ostream_indent(std::streambuf *dest, ::std::string::size_type indent)
		: indent(indent, ' ')
		, destination_streambuf{dest}
		, owning_ostream{nullptr}
	{
	}

	ostream_indent::ostream_indent(std::ostream &dest, ::std::string::size_type indent)
		: indent(indent, ' ')
		, destination_streambuf(dest.rdbuf())
		, owning_ostream{&dest}
	{
		owning_ostream->rdbuf(this);
	}

	ostream_indent::~ostream_indent()
	{
		if (owning_ostream != nullptr)
		{
			owning_ostream->rdbuf(destination_streambuf);
		}
	}

	int ostream_indent::overflow(int ch)
	{
		if (is_at_start_of_line && ch != '\n')
		{
			destination_streambuf->sputn(indent.data(), indent.size());
		}
		is_at_start_of_line = ch == '\n';
		return destination_streambuf->sputc(ch);
	}
}
