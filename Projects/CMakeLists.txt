# CMakeList.txt: проект CMake для CMakeProject; включите исходный код и определения

cmake_minimum_required (VERSION 3.8)

project ("CMakeProject1")

add_subdirectory("C://Projects//libpqxx//libpqxx-7.9.1" libpqxx-build)

add_executable (CMakeProject1 "CMakeProject1.cpp" )

target_compile_features(CMakeProject1 PRIVATE cxx_std_17)

target_link_libraries(CMakeProject1 PRIVATE pqxx)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject1 PROPERTY CXX_STANDARD 20)
endif()




