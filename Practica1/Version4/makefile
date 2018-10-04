all : bin/central

bin/central : obj/central.o lib/libformas.a
	@echo Creando el ejecutable bin/central...
	g++ -o bin/central obj/main.o -L./lib -lformas

obj/central.o : src/central.cpp include/circulo.h
	@echo Creando el modulo objeto obj/central.o...
	g++ -c -I./include -o obj/main.o src/central.cpp

obj/circulo.o : src/circulo.cpp include/circulo.h include/punto.h 
	@echo Creando el modulo objeto obj/circulo.o...
	g++ -c -I./include -o obj/circulo.o src/circulo.cpp -std=c++11

obj/punto.o : src/punto.cpp include/punto.h 
	@echo Creando el modulo objeto obj/punto.o...
	g++ -c -I./include -o obj/punto.o src/punto.cpp -std=c++11

lib/libformas.a : obj/circulo.o obj/punto.o
	@echo Creando la biblioteca lib/libformas.a...
	ar rvs lib/libformas.a obj/circulo.o obj/punto.o

clean :
	@echo Borrando los ficheros .o del directorio obj...
	rm obj/*.o lib/lib*.a


