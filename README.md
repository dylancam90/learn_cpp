# Reference

https://www.learncpp.com/

## VS Code Extensions Used

C/C++ by Microsoft
Clang-Format (A tool that allows developers to format code using the LLVM Clang-Format engine directly inside Visual Studio Code)
CMake by twxs (language support and syntax highlighting for CMakeLists.txt and .cmake files.)
CMake tools (provides a seamless, full-featured workflow for configuring, building, and debugging CMake-based C and C++ projects)

//---------------------------------------------------------------------------------------------------------------------------------------------------

# PROCESS FOR BUILDING AND RUNNING THROUGH VS CODE (THIS ISSUBJECT TO CHANGE BECAUSE OF THE WAY I HAVE THE PROJECT)

## Press:

Ctrl + Shift + P

## Then type into the search bar:

Tasks: Configure Task

## Then select:

CMake: Build

In the .vscode folder at the top of the project is where the tasks.json file will generate

## Not sure yet but chatGPT is telling me to replace everything with this:

This may change

```
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Build Project",
            "type": "shell",
            "command": "g++",
            "args": [
                "main.cpp",
                "hello.cpp",
                "-o",
                "program"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

## When its generated you press this is build

Ctrl + Shift + B
