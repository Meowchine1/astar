cmake_minimum_required(VERSION 3.14)

project(astar LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CPP main.cpp node.cpp graph.cpp heuristic.cpp)
set(HEADER node.h graph.h heuristic.h splitter.h)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(astar
    ${CPP} ${HEADER}
)
target_link_libraries(astar Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS astar
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
