CPP=g++
CFLAGS=-Wall -std=c++11

executable: Plane.o Ergasia3.o
		$(CPP) $(CFLAGS) -o prog Plane.o Ergasia3.o
Plane.o: Plane.cpp
		$(CPP) $(CFLAGS) -c Plane.cpp
Ergasia3.o: Ergasia3.cpp
		$(CPP) $(CFLAGS) -c Ergasia3.cpp
.PHONY: clean

clean:
	rm -f prog Plane.o Ergasia3.o
