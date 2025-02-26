cmake_minimum_required(VERSION 3.16...3.29)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(Source
        main.cpp

        mainwindow.h
        mainwindow.cpp

        network/Client.h
        network/Client.cpp

        client/clientwidget.h
        client/welcomewidget.h
        client/clientwidget.cpp
        client/welcomewidget.cpp

        client/Style/Style.h
        client/Style/Style.cpp

        client/ChatViewWidget/chatviewwidget.h
        client/ChatListWidget/chatlistwidget.h
        client/ChatViewWidget/chatviewwidget.cpp
        client/ChatListWidget/chatlistwidget.cpp

        client/ChatViewWidget/ChatInfoWidget/ChatInfoWidget.h
        client/ChatViewWidget/ChatInfoWidget/ChatInfoWidget.cpp

        client/ChatViewWidget/MessageListWidget/messagelistwidget.h
        client/ChatViewWidget/MessageListWidget/messagelistwidget.cpp

        client/ChatViewWidget/MessageListWidget/Messages/message.cpp
        client/ChatViewWidget/MessageListWidget/Messages/message.h

        client/ChatViewWidget/InputWidget/inputmessegefield.h
        client/ChatViewWidget/InputWidget/inputmessagewidget.h
        client/ChatViewWidget/InputWidget/inputmessegefield.cpp
        client/ChatViewWidget/InputWidget/inputmessagewidget.cpp
)

find_package(Qt6 COMPONENTS Core Widgets Multimedia  REQUIRED)



set(APP_ICON_PATH ${CMAKE_SOURCE_DIR}/resource/Icon/AppIcon.rc)

add_custom_target(Resource)

add_custom_command(TARGET Resource PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_CURRENT_BINARY_DIR}/resource
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/resource
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resource
        ${CMAKE_CURRENT_BINARY_DIR}/resource)

set(APP_ICON_PATH ${CMAKE_SOURCE_DIR}/resources/Icon/AppIcon.rc)


add_executable(${PROJECT_NAME} ${Source}  ${APP_ICON_PATH})

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Core
        Qt6::Widgets
        Qt6::Multimedia
        Boost::asio
)
set(STYLE_FOLDER_PATH ${CMAKE_BINARY_DIR}/bin/Style)
set_target_properties(${PROJECT_NAME}  PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_custom_command(TARGET ${PROJECT_NAME}  PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory "${STYLE_FOLDER_PATH}"
        COMMENT "Creating assets directory"
)

add_custom_target(copy_styles ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/client/Style/Styles"
        "${STYLE_FOLDER_PATH}"
        COMMENT "Copying assets"
)

add_dependencies(${PROJECT_NAME} copy_styles)



