all : bin/practica3

bin/practica3 : obj/main.o lib/libpractica3.a
	@echo Creando el ejecutable bin/practica3...
	g++ -o bin/practica3 obj/main.o -L./lib -lpractica3

obj/main.o : src/main.cpp include/descifra.h include/tiraLed.h
	@echo Creando el modulo objeto obj/main.o...
	g++ -c -I./include -o obj/main.o src/main.cpp

obj/descifra.o : src/descifra.cpp include/descifra.h 
	@echo Creando el modulo objeto obj/descifra.o...
	g++ -c -I./include -o obj/descifra.o src/descifra.cpp

obj/tiraLed.o : src/tiraLed.cpp include/tiraLed.h 
	@echo Creando el modulo objeto obj/tiraLed.o...
	g++ -c -I./include -o obj/tiraLed.o src/tiraLed.cpp

lib/libpractica3.a : obj/tiraLed.o obj/descifra.o
	@echo Creando la biblioteca lib/libpractica3.a...
	ar rvs lib/libpractica3.a obj/tiraLed.o obj/descifra.o

clean :
	@echo Borrando los ficheros .o del directorio obj...
	rm obj/*.o lib/lib*.a
