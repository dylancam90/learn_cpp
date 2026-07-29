# For VS Code users

To set up debugging, press Ctrl+Shift+P and select “C/C++: Add Debug Configuration”, followed by “C/C++: g++ build and debug active file”.
This should create and open the launch.json configuration file. Change the “stopAtEntry” to true:
"stopAtEntry": true,

Also make sure in tasks.json "command" is using g++ instead of gcc

Then open main.cpp and start debugging by pressing F5 or by pressing Ctrl+Shift+P and selecting “Debug: Start Debugging and Stop on Entry”.
