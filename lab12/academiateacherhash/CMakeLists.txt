
project(academiateacherhash)

set(HEDEAR_FILES AcademiaTeacherHash.h)
set(SOURCE_FILES AcademiaTeacherHash.cpp)

add_library(libacademiateacherhash STATIC ${SOURCE_FILES})
target_include_directories(libacademiateacherhash PUBLIC .)

add_executable(academiateacherhash ${SOURCE_FILES} main.cpp)

target_link_libraries(academiateacherhash libacademiateacherhash)

