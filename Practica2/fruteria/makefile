all : bin/fruteria

bin/fruteria : obj/main.o obj/funciones.o
	@echo Creando el ejecutable bin/fruteria...
	g++ -o bin/fruteria obj/main.o obj/funciones.o

obj/main.o : src/main.cpp include/funciones.h
	@echo Creando el modulo objeto obj/main.o...
	g++ -c -I./include -o obj/main.o src/main.cpp

obj/funciones.o : src/funciones.cpp include/funciones.h include/structs.h 
	@echo Creando el modulo objeto obj/funciones.o...
	g++ -c -I./include -o obj/funciones.o src/funciones.cpp -std=c++11

clean :
	@echo Borrando los ficheros .o del directorio obj...
	rm obj/*.o


