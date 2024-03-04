project (LuggageScale)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

# include project source
include_directories(${PROJECT_SOURCE_DIR}/../source)

set(TEST_EXE "TestExecutable")

set(SOURCE_DIR ".")
set(SOURCE_LIST 
	"${SOURCE_DIR}/RunAllTests.cpp"
	"${SOURCE_DIR}/FirstTest.cpp"
)

add_executable(${TEST_EXE} ${SOURCE_LIST})
target_link_libraries(${TEST_EXE} CppUTest CppUTestExt)

add_custom_command(TARGET ${TEST_EXE} COMMAND ./${TEST_EXE} POST_BUILD)
