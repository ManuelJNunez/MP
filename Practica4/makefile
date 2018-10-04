all : bin/tsp clean

bin/tsp: obj/main.o obj/viajante.o
	@echo Creando el ejecutable bin/tsp...
	g++ -o bin/tsp obj/main.o obj/viajante.o

obj/main.o : src/main.cpp include/viajante.h
	@echo Creando el modulo objeto obj/main.o...
	g++ -c -I./include -o obj/main.o src/main.cpp

obj/viajante.o : src/viajante.cpp include/viajante.h 
	@echo Creando el modulo objeto obj/viajante.o...
	g++ -c -I./include -o obj/viajante.o src/viajante.cpp -std=c++11

clean :
	@echo Borrando los ficheros .o del directorio obj...
	rm obj/*.o
