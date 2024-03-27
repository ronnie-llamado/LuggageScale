project(LuggageScale)

include_directories(${PROJECT_SOURCE_DIR}/../include)

add_library(FakeDIO FakeDIO.c)
add_library(FakeTimer FakeTimer.c)
add_library(FakeHX711 FakeHX711.c)
