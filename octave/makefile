LIB = include 

all: exe_arq

exe_arq: main.o
	g++ -o exe_arq main.o `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --cflags --libs opencv4`

main.o: main.cpp
	g++ -o main.o main.cpp -c `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --cflags --libs opencv4` -l /usr/include/octave-5.2.0/octave/mex.h