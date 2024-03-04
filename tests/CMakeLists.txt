project (LuggageScale)

# include project source
include_directories(${PROJECT_SOURCE_DIR}/../source)

# include CppUTest headers
include_directories($ENV{CPPUTEST_HOME}/include)
link_directories($ENV{CPPUTEST_HOME}/lib)

# add cpputest library
#add_library(imp_cpputest STATIC IMPORTED)
#set_property(TARGET imp_cpputest PROPERTY
#             IMPORTED_LOCATION $ENV{CPPUTEST_HOME}/src/CppUTest/libCppUTest.a)



# build test library
# add_library(FirstTest FirstTest.cpp)

add_executable(TestExecutable RunAllTests.cpp FirstTest.cpp)
target_link_libraries(TestExecutable CppUTest CppUTestExt)

add_custom_command(TARGET TestExecutable COMMAND ./TestExecutable POST_BUILD)
