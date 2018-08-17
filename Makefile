

output : main.o Display.o
	g++ -std=c++11 main.o Display.o -o ouput -lSDL2 -lGLEW -lGL


main.o : main.cpp
	g++ -std=c++11 -c main.cpp

Display.o : Display.cpp Display.h
	g++ -std=c++11 -c Display.cpp 
