
project(academiateacherhash)

set(HEDEAR_FILES TeacherHash.h)
set(SOURCE_FILES TeacherHash.cpp)

add_library(libacademiateacherhash STATIC ${SOURCE_FILES})
target_include_directories(libacademiateacherhash PUBLIC .)

add_executable(academiateacherhash ${SOURCE_FILES} main.cpp)

target_link_libraries(academiateacherhash libacademiateacherhash)

