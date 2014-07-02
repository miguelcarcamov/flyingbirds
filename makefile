LDLIBS = -lglut -lGLU -lGL 
all:
	@u++ -o salida.out main.cpp ave.cpp $(LDLIBS)
run:
	@u++ -o salida.out main.cpp ave.cpp $(LDLIBS)
	./salida.out