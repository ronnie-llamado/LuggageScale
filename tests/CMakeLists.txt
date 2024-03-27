project (LuggageScale)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)
set(CPPUTEST_LIBS CppUTest CppUTestExt)

# include project source
include_directories(${PROJECT_SOURCE_DIR}/source)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/mocks)

# HX711
set(FILENAME HX711Test.cpp)
set(TEST_LIBS HX711 FakeDIO FakeTimer)
get_filename_component(FILENAME_WE ${FILENAME} NAME_WE)
add_executable(${FILENAME_WE} RunAllTests.cpp ${FILENAME})
target_include_directories(${FILENAME_WE} PRIVATE "../include" "../mocks")
target_link_libraries(${FILENAME_WE} ${CPPUTEST_LIBS} ${TEST_LIBS})
add_custom_command(TARGET ${FILENAME_WE} COMMAND ./${FILENAME_WE} POST_BUILD)

# CircularBuffer
set(FILENAME CircularBufferTest.cpp)
set(TEST_LIBS CircularBuffer)
get_filename_component(FILENAME_WE ${FILENAME} NAME_WE)
add_executable(${FILENAME_WE} RunAllTests.cpp ${FILENAME})
target_include_directories(${FILENAME_WE} PRIVATE "../include" "../mocks")
target_link_libraries(${FILENAME_WE} ${CPPUTEST_LIBS} ${TEST_LIBS})
add_custom_command(TARGET ${FILENAME_WE} COMMAND ./${FILENAME_WE} POST_BUILD)

# LoadCell
set(FILENAME LoadCellTest.cpp)
set(TEST_LIBS CircularBuffer LoadCell FakeHX711)
get_filename_component(FILENAME_WE ${FILENAME} NAME_WE)
add_executable(${FILENAME_WE} RunAllTests.cpp ${FILENAME})
target_include_directories(${FILENAME_WE} PRIVATE "../include" "../mocks")
target_link_libraries(${FILENAME_WE} ${CPPUTEST_LIBS} ${TEST_LIBS})
add_custom_command(TARGET ${FILENAME_WE} COMMAND ./${FILENAME_WE} POST_BUILD)

