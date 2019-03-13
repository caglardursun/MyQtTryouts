cmake_minimum_required(VERSION 3.0.0)

project(EchoServer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED Core Widgets Gui Network LinguistTools)

#translation creation
#qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} turkish.ts)
#end of translation

# files ...
set(project_sources 
    "main.cpp" 
    "mainwindow.cpp")

set(project_headers "mainwindow.h")
set(project_dialogs "mainwindow.ui")
# end of files files ...

#ui file compiled to ui_{ui_filename}.h so ...
qt5_wrap_ui(project_header_wrap ${project_dialogs})
#inside of header file we have Q_OBJECT decleration so we need to wrap 
qt5_wrap_cpp(project_source_moc ${project_headers})
#end of wrapping ...

add_executable(${PROJECT_NAME} 
                ${project_sources} 
                ${project_headers} 
                ${project_dialogs} 
                ${project_header_wrap}
                ${project_source_moc}
                ${QM_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)
