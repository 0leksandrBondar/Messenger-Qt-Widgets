cmake_minimum_required(VERSION 3.16...3.29)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Source
    main.cpp

    mainwindow.h
    mainwindow.cpp

    client/clientwidget.h
    client/clientwidget.cpp

    client/ChatViewWidget/chatviewwidget.h
    client/ChatListWidget/chatlistwidget.h
    client/ChatViewWidget/chatviewwidget.cpp
    client/ChatListWidget/chatlistwidget.cpp

    client/ChatViewWidget/MessageListWidget/Messages/message.h
    client/ChatViewWidget/MessageListWidget/Messages/message.cpp

    client/ChatViewWidget/InputWidget/inputmessegefield.h
    client/ChatViewWidget/InputWidget/inputmessagewidget.h
    client/ChatViewWidget/InputWidget/inputmessegefield.cpp
    client/ChatViewWidget/InputWidget/inputmessagewidget.cpp

)

find_package(Qt6 COMPONENTS Core Widgets Gui REQUIRED)


add_executable(${PROJECT_NAME} ${Source}
    client/ChatViewWidget/MessageListWidget/messagelistwidget.h client/ChatViewWidget/MessageListWidget/messagelistwidget.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets)



