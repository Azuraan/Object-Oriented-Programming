CPP=g++
CFLAGS=-Wall

executable: forum.o PrintTree.o Project_2.o
		$(CPP) $(CFLAGS) -o prog forum.o PrintTree.o Project_2.o
forum.o: forum.cpp
		$(CPP) $(CFLAGS) -c forum.cpp
PrintTree.o: PrintTree.cpp
		$(CPP) $(CFLAGS) -c PrintTree.cpp
Project_2.o: Project_2.cpp
		$(CPP) $(CFLAGS) -c Project_2.cpp
.PHONY: clean

clean:
	rm -f prog forum.o PrintTree.o Project_2.o
