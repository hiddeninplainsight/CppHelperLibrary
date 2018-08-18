add_library(CppHelperLibrary
	include/chl/ostream_indent.h
	ostream_indent.cpp
	)

target_include_directories(CppHelperLibrary PRIVATE
	./include
	)


target_include_directories(CppHelperLibrary SYSTEM INTERFACE
	./include
	)
