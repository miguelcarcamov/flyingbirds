#
# Flying Birds
# by SmokeInBrain and DWladdimiroC

INC_DIRS = -Isrc

CFLAGS = -c -w

LDLIBS = -lglut -lGLU -lGL

main: build/main.o build/ave.o
	@ u++ build/*.o -o bin/FlyingBirds.run $(LDLIBS)
	@ echo "The compilation has been completed successfully"

build/main.o: src/main.cpp
	@ echo "src/main.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/main.cpp -o build/main.o

build/ave.o: src/eda/ave.cpp
	@ echo "src/eda/ave.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/eda/ave.cpp -o build/ave.o

clean:
	@ clear
	@ echo "Clear folder.."
	@ rm -rf build/*
	@ rm -rf bin/*

run:
	@ clear
	@ echo "Execute Flying Birds"
	@ ./bin/FlyingBirds.run

flying: clean main run

