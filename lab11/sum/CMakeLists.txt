
project(sum)

set(HEDEAR_FILES Sum.h)
set(SOURCE_FILES Sum.cpp)

add_library(libsum STATIC ${SOURCE_FILES})
target_include_directories(libsum PUBLIC .)

add_executable(sum ${SOURCE_FILES} main.cpp)

target_link_libraries(sum libsum)

