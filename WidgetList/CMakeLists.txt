cmake_minimum_required(VERSION 3.0.0)

project(ColorBox VERSION 0.1 LANGUAGES CXX)
set(COMPANY "Copyleft ")

add_subdirectory(Src)

# find_package(Qt5 REQUIRED Core Widgets Gui)

# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTORCC ON)



# file(GLOB project_sources "*.cpp")
# file(GLOB project_headers "*.h")
# file(GLOB project_dialogs "*.ui")


# add_executable(${PROJECT_NAME} 
#                 ${project_sources} 
#                 ${project_headers} 
#                 ${project_dialogs}      
#                 ${resource_files}      
#                 ${qm_files}                                   
#                 )

# target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui)