cmake_minimum_required(VERSION 3.0.0)

project(MiracleLayout VERSION 0.1 LANGUAGES CXX)
set(COMPANY "AIT Ltd Şti")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)


find_package(Qt5 REQUIRED Core Widgets Gui LinguistTools)


#add directories to seee what's inside
#include_directories("View" "Model")

#I'm sick and tired to add these line everythime I try to add a class or 
#dialog file into the project. I'm too lazy 4 this



file(GLOB project_sources "*.cpp" 
                            "View/*.cpp" 
                            "Model/*.cpp"  
                            "ViewModel/*.cpp")
file(GLOB project_headers "*.h" 
                            "View/*.h" 
                            "Model/*.h" 
                            "ViewModel/*.h")

file(GLOB project_dialogs "View/*.ui")

set(resource_files "resource.qrc")

#source files ...
# set(project_sources "main.cpp" 
#                     "View/mainwindow.cpp"   
#                     "View/basewindow.cpp"                                                                                             
#                     "Model/provider.cpp"
#                     "Model/settings.cpp"
#                     "Model/logger.cpp"
#                     "ViewModel/mainviewmanager.cpp"
#                     "View/mainviewer.cpp"                   
#                     "startup.cpp"
#                     "utils.cpp")
#header files ...
# set(project_headers "View/mainwindow.h" 
#                     "View/basewindow.h"                                                       
#                     "Model/provider.h"                    
#                     "Model/settings.h"
#                     "Model/logger.h" 
#                     "ViewModel/mainviewmanager.h"                   
#                     "View/mainviewer.h"                   
#                     "startup.h"
#                     "utils.h")

# set(project_dialogs "View/mainwindow.ui" "View/mainviewer.ui")


#set output location
#set_source_files_properties(${QM_FILES} PROPERTIES OUTPUT_LOCATION "lang")

#add translation files

set(translation_files "languages/tr_TR.ts" "languages/en_US.ts")
#set(qm_files "languages/türkçe.qm" "languages/english.qm")

#languages kasörü oluştur
# file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/languages")
# qt5_create_translation(qm_files ${CMAKE_SOURCE_DIR} ${translation_files} PROPERTIES OUTPUT_LOCATION "${CMAKE_BINARY_DIR}/languages" )
#configure_file(${resource_files} ${CMAKE_BINARY_DIR} COPYONLY)

#if the pwd is not set copy might be usefull
qt5_create_translation(qm_files ${CMAKE_SOURCE_DIR} ${translation_files})


add_custom_target(translations DEPENDS ${qm_files})
#compiled language files will be on the same languages directory




#if the compiler is msvc
if(MSVC)
    message("*** Microsoft C Compiler running ***")    
else()
    message("*** You are working non microsoft compiler ***")
endif()



add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs}      
                ${resource_files}      
                ${qm_files}                                   
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

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)
