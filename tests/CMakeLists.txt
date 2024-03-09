project (LuggageScale)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

# include project source
include_directories(${PROJECT_SOURCE_DIR}/source)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/mocks)

set(TEST_EXE "TestExecutable")
set(TEST_FILES)

# HX711
add_library(HX711Test HX711Test.cpp)
target_include_directories(HX711Test PRIVATE "../include")
target_include_directories(HX711Test PRIVATE "../mocks")
target_link_libraries(HX711Test HX711 FakeDIO FakeTimer)
list(APPEND TEST_FILES "HX711Test")

# CircularBuffer
add_library(CircularBufferTest CircularBufferTest.cpp)
target_include_directories(CircularBufferTest PRIVATE "../include")
target_include_directories(CircularBufferTest PRIVATE "../mocks")
target_link_libraries(CircularBufferTest CircularBuffer)
list(APPEND TEST_FILES "CircularBufferTest")

add_executable(${TEST_EXE} RunAllTests.cpp)
target_link_libraries(${TEST_EXE} CppUTest CppUTestExt ${TEST_FILES})
add_custom_command(TARGET ${TEST_EXE} COMMAND ./${TEST_EXE} POST_BUILD)
