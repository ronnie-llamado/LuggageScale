cmake_minimum_required(VERSION 3.27)
project(LuggageScale)

enable_language(C ASM CXX)

set(APPLICATION_NAME luggageScale)
set(APPLICATION_LIBRARY_NAME luggageScaleLib)

add_subdirectory(mocks)
add_subdirectory(source)
add_subdirectory(tests)
