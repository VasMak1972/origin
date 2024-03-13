
cmake_minimum_required(VERSION 3.18)
project(CMakekp LANGUAGES CXX)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(SOURCE_LIB races.cpp transport.cpp airTransport.cpp erthTransport.cpp)
set(SOURCE_HD types.h races.h transport.h airTransport.h erthTransport.h)
add_library(RacesLibStatic SHARED ${SOURCE_LIB} ${SOURCE_HD})

set(SOURCE_EXE vasmakkp.cpp)
add_executable(vasmakkpexe ${SOURCE_EXE})

target_link_libraries(vasmakkpexe RacesLibStatic)

