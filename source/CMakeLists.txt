set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

set(APPLICATION_SOURCE_LIST 
	CircularBuffer.c
	DIO.c
	HX711.c
	LoadCell.c
	Timer.c
	UART.c
)

# Build each source file
foreach(FILENAME IN LISTS APPLICATION_SOURCE_LIST)
	get_filename_component(FILENAME_WE ${FILENAME} NAME_WE)
	add_library(${FILENAME_WE} ${FILENAME})
	target_include_directories(${FILENAME_WE} PRIVATE ${INCLUDE_DIR})
endforeach()

add_executable(${APPLICATION_NAME} main.c)
target_include_directories(${APPLICATION_NAME} PRIVATE ${INCLUDE_DIR})
target_link_libraries(${APPLICATION_NAME} DIO HX711 LoadCell Timer UART)

