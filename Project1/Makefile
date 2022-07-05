CPP=g++
CFLAGS=-Wall

executable: forum.o Project_1.o
		$(CPP) $(CFLAGS) -o prog forum.o Project_1.o
forum.o: forum.cpp
		$(CPP) $(CFLAGS) -c forum.cpp
Project_1.o: Project_1.cpp
		$(CPP) $(CFLAGS) -c Project_1.cpp
.PHONY: clean

clean:
	rm -f prog forum.o Project_1.o
