# mekb
(WIP) Mechanical keyboard sound simulator for Windows
Simulate mechanical keyboard sound using PlaySound in C. Could also technically be turned into a keylogger if you translate keyCode and periodically append to disk. Maybe maybe?

Get MinGW or the equivalent to be able to compile in windows (cmd, WSL doesn't have access to the required windows.h header files):
compile: g++ -omekb main.cpp
run: mekb
