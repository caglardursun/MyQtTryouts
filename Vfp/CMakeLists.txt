cmake_minimum_required(VERSION 3.0.0)

project(Vfp VERSION 0.1 LANGUAGES CXX)
set(COMPANY "AIT Ltd Şti")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 REQUIRED Core Widgets Gui Network LinguistTools)

#add_compile_options(-std=c++11)

#add_subdirectory(View)
#add_subdirectory(Model)
#add_subdirectory(ViewMng) 




#resource files ...
set(resource_files 
    "vfpresources.qrc")

include_directories("View")
include_directories("Model")
include_directories("ViewMng")


#source files ...
set(project_sources 
    "main.cpp" 
    "startup.cpp"
    "utils.cpp"
    "View/mainview.cpp"
    "View/setuptab.cpp"
    "Model/settings.cpp"
    "Model/provider.cpp"
    "Model/instsocket.cpp"
    "Model/instrument.cpp" 
    "ViewMng/setupviewmanager.cpp"
    )

    
#header files ...
set(project_headers 
    "startup.h" 
    "utils.h" 
    "View/mainview.h" 
    "View/setuptab.h" 
    "Model/settings.h"
    "Model/provider.h"
    "Model/instrument.h" 
    "Model/instsocket.h"
    "ViewMng/setupviewmanager.h"
    )

set(project_dialogs 
    # "View/controltab.ui"
    "View/mainview.ui" 
    "View/setuptab.ui")
    
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

