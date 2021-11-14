all: exe_arq

exe_arq: main.o
	g++ -o exe_arq main.o `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --libs --cflags octave`

main.o: main.cpp
	g++ -o main.o main.cpp -c `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --libs --cflags octave`