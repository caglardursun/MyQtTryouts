cmake_minimum_required(VERSION 3.0.0)

project(QtCustomControls VERSION 0.1 LANGUAGES CXX)
set(COMPANY "AIT Ltd Şti")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Core Widgets Gui Network LinguistTools)


#source files ...
set(project_sources "main.cpp" "View/mainwindow.cpp")
#header files ...
set(project_headers "View/mainwindow.h")

set(project_dialogs "View/mainwindow.ui")


add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs}                                               
                )

#PUBLIC : dependencies specify that not only does library A use library B internally, it also uses B in
#its interface. This means that A cannot be used without B, so anything that uses A will also have
#a direct dependency on B. 

#PRIVATE : dependencies specify that library A uses library B in its own internal implementation.
#Anything else that links to library A doesn’t need to know about B because it is an internal
#implementation detail of A.

#INTERFACE : Interface dependencies specify that in order to use library A, parts of library B must also be
#used. This differs from a public dependency in that library A doesn’t require B internally, it only
#uses B in its interface. An example of where this is useful is when working with library targets
#defined using the INTERFACE form of add_library(), such as when using a target to represent a
#header-only library’s dependencies

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)