#
# Flying Birds
# by SmokeInBrain and DWladdimiroC

INC_DIRS = -Isrc

CFLAGS = -c -w

LDLIBS = -lglut -lGLU -lGL

main: build/main.o build/Bird.o build/Graphics.o
	@ u++ build/*.o -o bin/FlyingBirds.run $(LDLIBS)
	@ echo "The compilation has been completed successfully"

build/main.o: src/main.cpp
	@ echo "src/main.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/main.cpp -o build/main.o

build/Bird.o: src/eda/Bird.cpp
	@ echo "src/eda/Bird.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/eda/Bird.cpp -o build/Bird.o

build/Graphics.o: src/graphics/Graphics.cpp
	@ echo "src/graphics/Graphics.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/graphics/Graphics.cpp -o build/Graphics.o

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

