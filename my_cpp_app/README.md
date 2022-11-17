# CMAKE
cmake -G "MinGW Makefiles" ..\source\ == to generate file with specific generator
# WINDOW
mingw32-make.exe
# LINUX
make
# Generic build
cmake --build .
# Build specific target explicity
cmake --build . --target logger

cmake --build . --target operations

cmake --build . --target HelloAppBinary
# Gather information about the system running Cmake
cmake --system-information info.txt
# Jenkins