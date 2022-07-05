CPP=g++
CFLAGS=-Wall

executable: forum.o PrintTree.o Askhsh2.o
		$(CPP) $(CFLAGS) -o prog forum.o PrintTree.o Askhsh2.o
forum.o: forum.cpp
		$(CPP) $(CFLAGS) -c forum.cpp
PrintTree.o: PrintTree.cpp
		$(CPP) $(CFLAGS) -c PrintTree.cpp
Askhsh2.o: Askhsh2.cpp
		$(CPP) $(CFLAGS) -c Askhsh2.cpp
.PHONY: clean

clean:
	rm -f prog forum.o PrintTree.o Askhsh2.o
