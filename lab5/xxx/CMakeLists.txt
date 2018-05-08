
project(xxx)

set(HEDEAR_FILES Xxx.h)
set(SOURCE_FILES Xxx.cpp)

add_library(libxxx STATIC ${SOURCE_FILES})
target_include_directories(libxxx PUBLIC .)

add_executable(xxx ${SOURCE_FILES} main.cpp)

target_link_libraries(xxx libxxx)

