# MyQtTryouts
* Echo Server : Simple TCP/IP socket programing tryouts on Qt 
* QtConsole : Simple console application tryouts on Qt 
* QtQuick : Qml application theme testing 
* QtCustomControl : Custom control development testing
    - [x] `DockLayout testing`
    - [x] `Custom widget implimentation`

* #### Vfp : Qt widget application which I try to figure out 
    - [ ] `How to implement an MVVM design in c++ and Qt`
    - [x] `How to json file parsing works in Qt libraries`
    - [x] `How to resource management works in Qt Application`
    - [x] `Theme and styling etc. testing`


# Requirements ...

* You should have latest version of cmake 
* VsCode will be a plus but cmake already handle the build environment generation
* If you want to use debug helper make sure qt5.natvis file should be defined in `launch.json` file like ..

```json
    "configurations": [        
        {
            "name": "(Windows) Launch",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/build/ProjectName.exe",
            "args": [],
            "stopAtEntry": false,            
            "cwd": "${workspaceFolder}",
            "symbolSearchPath": "${workspaceFolder}/build/",            
            "environment": [],
            "externalConsole": false,
            "visualizerFile": "${workspaceFolder}/../qt5.natvis"
        }
    ]

```

* The source file and folder should be updated wrt. cmake build output inside of the build folder compile_commands.json file 






