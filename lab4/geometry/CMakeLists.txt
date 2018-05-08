
project(geometry)

set(HEDEAR_FILES Square.h Point.h)
set(SOURCE_FILES Square.cpp Point.cpp)

add_library(libsquare STATIC ${SOURCE_FILES})
target_include_directories(libsquare PUBLIC .)

add_executable(geometry ${SOURCE_FILES} main.cpp)

target_link_libraries(geometry libsquare)

