
OCTAVE_INCLUDE=C:\Octave\Octave3.6.4_gcc4.6.2\include

all: test

clean:
    -rm test.o test

test: test.o
    mkoctfile --link-stand-alone -o test test.o

test.o: main.cpp
    g++ -c -I$(OCTAVE_INCLUDE) -I$(OCTAVE_INCLUDE)\octave-3.6.4 -o test.o main.cpp