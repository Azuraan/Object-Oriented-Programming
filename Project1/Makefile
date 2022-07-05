CPP=g++
CFLAGS=-Wall

executable: forum.o Ergasia1.o
		$(CPP) $(CFLAGS) -o prog forum.o Ergasia1.o
forum.o: forum.cpp
		$(CPP) $(CFLAGS) -c forum.cpp
Ergasia1.o: Ergasia1.cpp
		$(CPP) $(CFLAGS) -c Ergasia1.cpp
.PHONY: clean

clean:
	rm -f prog forum.o Ergasia1.o
