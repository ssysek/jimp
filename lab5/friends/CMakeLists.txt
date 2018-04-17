
project(friends)

set(HEDEAR_FILES Friends.h)
set(SOURCE_FILES Friends.cpp)

add_library(libfriends STATIC ${SOURCE_FILES})
target_include_directories(libfriends PUBLIC .)

add_executable(friends ${SOURCE_FILES} main.cpp)

target_link_libraries(friends libfriends)

