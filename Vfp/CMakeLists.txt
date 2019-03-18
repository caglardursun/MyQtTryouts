cmake_minimum_required(VERSION 3.0.0)

project(Vfp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Core Widgets Gui Network LinguistTools)

#add_compile_options(-std=c++11)

#add_subdirectory(View)
#add_subdirectory(Model)
#add_subdirectory(ViewMng) 

set(COMPANY "AIT Ltd Şti")


set(resource_files 
    "vfpresources.qrc")


# files ...
set(project_sources 
    "main.cpp" 
    "startup.cpp"
    "utils.cpp"
    "View/mainview.cpp"
    "View/setuptab.cpp"
    "Model/settings.cpp"
    "ViewMng/setupviewmanager.cpp"
    )

set(project_headers 
    "startup.h" 
    "utils.h" 
    "View/mainview.h" 
    "View/setuptab.h" 
    "Model/settings.h"
    "ViewMng/setupviewmanager.h"
    )

set(project_dialogs "View/mainview.ui" "View/setuptab.ui")
# end of files files ...

#CMAKE_AUTOMOC will handle it so I comment it 

#ui file compiled to ui_{ui_filename}.h so ...
#qt5_wrap_ui(project_header_wrap ${project_dialogs})
#inside of header file we have Q_OBJECT decleration so we need to wrap 
#qt5_wrap_cpp(project_source_moc ${project_headers})
#end of wrapping ...


add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs} 
                ${project_header_wrap}
                ${project_source_moc}  
                ${resource_files}              
                ${QM_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)

