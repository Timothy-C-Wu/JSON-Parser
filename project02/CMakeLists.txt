cmake_minimum_required(VERSION 3.12)
project(project02)

set(CMAKE_CXX_STANDARD 17)

#add_executable(project02 JSONToken.cpp JSONToken.hpp JSONTokenizer.cpp JSONTokenizer.hpp JSONParser.hpp JSONParser.cpp Entity.hpp Entity.cpp pair.h pair.cpp EntityInstance.hpp EntityInstance.cpp)

add_executable(project02 JSONToken.hpp JSONToken.cpp JSONTokenizer.hpp JSONTokenizer.cpp TestMain.cpp pair.cpp pair.h JSONParser.cpp JSONParser.hpp Entity.cpp Entity.hpp EntityInstance.cpp EntityInstance.hpp)