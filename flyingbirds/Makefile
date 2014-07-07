#
# Flying Birds
# by SmokeInBrain and DWladdimiroC

INC_DIRS = -Isrc

CFLAGS = -c -w

LDLIBS = -lglut -lGLU -lGL

main: build/main.o build/Bird.o build/getOptions.o build/Graphics.o build/Math.o build/Physics.o build/Random.o
	@ u++ build/*.o -o bin/FlyingBirds.run $(LDLIBS)
	@ echo "The compilation has been completed successfully"

build/main.o: src/main.cpp
	@ echo "src/main.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/main.cpp -o build/main.o

build/Bird.o: src/eda/Bird.cpp
	@ echo "src/eda/Bird.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/eda/Bird.cpp -o build/Bird.o

build/getOptions.o: src/getOptions/getOptions.cpp
	@ echo "src/getOptions/getOptions.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/getOptions/getOptions.cpp -o build/getOptions.o

build/Math.o: src/misc/Math.cpp
	@ echo "src/misc/Math.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/misc/Math.cpp -o build/Math.o

build/Physics.o: src/misc/Physics.cpp
	@ echo "src/misc/Physics.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/misc/Physics.cpp -o build/Physics.o

build/Random.o: src/misc/Random.cpp
	@ echo "src/misc/Random.cpp"
	@ u++ $(CFLAGS) $(INC_DIRS) src/misc/Random.cpp -o build/Random.o

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
	@ ./bin/FlyingBirds.run -N 100 -s 0.6 -c 0.2 -a 0.2

flying: clean main run

