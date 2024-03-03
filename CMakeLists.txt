cmake_minimum_required(VERSION 3.27)
project(LuggageScale)

enable_language(C ASM)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(EXECUTABLE ${PROJECT_NAME}.out)

set(SOURCE_DIR "./source")
set(INCLUDE_DIR "./include")

set(CMAKE_BINARY_DIR, "./bin")

set(SOURCE_LIST 
	"${SOURCE_DIR}/main.c"
)

set(INCLUDE_LIST
	"${INCLUDE_DIR}/main.h"
)

include_directories(${INCLUDE_DIR})

add_executable(${EXECUTABLE} ${SOURCE_LIST} ${INCLUDE_LIST})

