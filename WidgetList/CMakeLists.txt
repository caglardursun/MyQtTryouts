cmake_minimum_required(VERSION 3.0.0)

project(MiracleColorBox VERSION 0.1 LANGUAGES CXX)
set(COMPANY "AIT Ltd Şti")


find_package(Qt5 REQUIRED Core Widgets Gui)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(Src)

file(GLOB project_sources "Src/*.cpp")
file(GLOB project_headers "Src/*.h")
file(GLOB project_dialogs "Src/*.ui")


add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs}      
                ${resource_files}      
                ${qm_files}                                   
                )

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)