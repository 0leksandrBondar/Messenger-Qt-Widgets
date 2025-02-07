cmake_minimum_required(VERSION 3.16...3.29)

project(MessengerServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Source
        main.cpp
        server.h
        server.cpp
)

find_package(Qt6 COMPONENTS Core Network REQUIRED)


add_executable(${PROJECT_NAME} ${Source})

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Core
        Qt6::Network
)





