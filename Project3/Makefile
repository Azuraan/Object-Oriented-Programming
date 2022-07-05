CPP=g++
CFLAGS=-Wall -std=c++11

executable: Plane.o Project_3.o
		$(CPP) $(CFLAGS) -o prog Plane.o Project_3.o
Plane.o: Plane.cpp
		$(CPP) $(CFLAGS) -c Plane.cpp
Project_3.o: Project_3.cpp
		$(CPP) $(CFLAGS) -c Project_3.cpp
.PHONY: clean

clean:
	rm -f prog Plane.o Project_3.o
