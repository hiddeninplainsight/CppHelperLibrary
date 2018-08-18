include(${gtest_SOURCE_DIR}/cmake/internal_utils.cmake)
config_compiler_and_linker()


add_executable(tests
	ostream_indent.tests.cpp
	)

target_link_libraries(tests PRIVATE
	CppHelperLibrary
	)

target_link_libraries(tests PRIVATE
	gmock
	gmock_main
	)

target_include_directories(tests PRIVATE
	"${gmock_SOURCE_DIR}/include"
	"${gtest_SOURCE_DIR}/include"
	)
