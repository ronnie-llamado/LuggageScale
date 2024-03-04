set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(EXECUTABLE ${PROJECT_NAME}.out)


set(SOURCE_DIR ".")
set(INCLUDE_DIR "../include")

set(SOURCE_LIST 
	"${SOURCE_DIR}/main.c"
)

set(INCLUDE_LIST
	"${INCLUDE_DIR}/main.h"
)

include_directories(${INCLUDE_DIR})

add_executable(${EXECUTABLE} ${SOURCE_LIST} ${INCLUDE_LIST})

