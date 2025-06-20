cmake_minimum_required(VERSION 3.5)

project(engineering_calculator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)    # Для MOC (сигналы/слоты)
set(CMAKE_AUTOUIC ON)    # Для UIC (.ui → заголовки)
set(CMAKE_AUTORCC ON)    # Для RCC (.qrc → ресурсы)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Gui Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets)

file(GLOB HEADERS "src/*.h")
file(GLOB SOURCES "src/*.cpp")
file(GLOB FORMS "src/*.ui")
file(GLOB RESOURCES "src/*.qrc")

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${FORMS}
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
)

if(UNIX AND NOT APPLE AND NOT ANDROID)
    install(TARGETS ${PROJECT_NAME} DESTINATION /opt/${PROJECT_NAME}/bin)
endif()
