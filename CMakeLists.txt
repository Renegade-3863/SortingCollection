# 本项目为对于主要的排序算法进行复习使用的小型测试项目，并不具有实战作用
# 版本号为作者本机的cmake版本，测试者可以根据自己本地的cmake版本进行调整
cmake_minimum_required(VERSION 3.16.3)
# 编译使用的C++版本
set(CMAKE_CXX_STANDARD 14)
# 指定本项目的项目名，同时也是PROJECT_SOURCE_DIR的引用目录标识器
project(SortingCollection)

include_directories(${PROJECT_SOURCE_DIR}/include)
# 设定编译用到的源码找寻目录，注意，这个aux命令只能检测到对应目录下的.cpp/.cc源文件存入SRC，不能找到对应的.h头文件
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)
# list(REMOVE_ITEM SRC ${PROJECT_SOURCE_DIR}/src/RandomArray.cc)
add_definitions(-DDEBUG)
# 指定测试文件的输出目录为运行编译命令时所在的目录
set(EXECUTABLE_OUTPUT_PATH ./)
add_executable(app ${SRC})
# 也可使用下面的FILE命令进行源码搜索，注意FILE命令需要明确指定需要寻找什么样的文件(可用正则指定)，否则它会抓取对应目录下所有的文件
# FILE(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.cc)
# message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
# message("PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})