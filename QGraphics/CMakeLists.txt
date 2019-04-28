cmake_minimum_required(VERSION 3.0.0)

project(QGraphicsEfffect VERSION 0.1 LANGUAGES CXX)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Core Widgets Gui)


file(GLOB project_sources "Src/*.cpp")
file(GLOB project_headers "Src/*.h")
file(GLOB project_dialogs "Src/*.ui")

include_directories(Src)
#set(resource_files "Src/resource.qrc")



add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs}      
                ${resource_files}                      
                )


target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)