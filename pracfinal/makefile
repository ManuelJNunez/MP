all : bin/test2 bin/pruebaNube bin/pruebaConjunto2 bin/pruebaSimulador clean

bin/test2 : obj/miniwin.o obj/particula.o obj/main.o
	@echo Creando el ejecutable bin/test2...
	g++ -o bin/test2 $^ -pthread -lX11

bin/pruebaNube : obj/miniwin.o obj/particula.o obj/nubeparticulas.o obj/mainpnube.o
	@echo Creando el ejecutable bin/pruebaConjunto...
	g++ -o bin/pruebaNube $^ -pthread -lX11

bin/pruebaConjunto2 : obj/miniwin.o obj/particula.o obj/nubeparticulas.o obj/mainnube2.o
	@echo Creando el ejecutable bin/pruebaConjunto...
	g++ -o bin/pruebaConjunto2 $^ -pthread -lX11

bin/pruebaSimulador : obj/miniwin.o obj/particula.o obj/nubeparticulas.o obj/simulador.o obj/mainsim.o
	@echo Creando el ejecutable bin/pruebaSimulador...
	g++ -o bin/pruebaSimulador $^ -pthread -lX11

obj/main.o : src/main.cpp include/particula.h
	@echo Creando el modulo objeto obj/main.o...
	g++ -c -I./include -o obj/main.o src/main.cpp

obj/miniwin.o : src/miniwin.cpp include/miniwin.h 
	@echo Creando el modulo objeto obj/miniwin.o...
	g++ -c -I./include -o obj/miniwin.o src/miniwin.cpp

obj/particula.o : src/particula.cpp include/particula.h include/definiciones.h
	@echo Creando el modulo objeto obj/particula.o...
	g++ -c -I./include -o obj/particula.o src/particula.cpp

obj/nubeparticulas.o : src/nubeparticulas.cpp include/particula.h include/miniwin.h
	@echo Creando el modulo objeto obj/main.o...
	g++ -c -I./include -o obj/nubeparticulas.o src/nubeparticulas.cpp

obj/simulador.o : src/simulador.cpp include/simulador.h include/nubeparticulas.h include/definiciones.h
	g++ -c -I./include -o obj/simulador.o src/simulador.cpp

obj/mainpnube.o : src/mainpnube.cpp include/nubeparticulas.h include/definiciones.h
	g++ -c -I./include -o obj/mainpnube.o src/mainpnube.cpp

obj/mainnube2.o : src/mainnube2.cpp include/nubeparticulas.h include/definiciones.h
	g++ -c -I./include -o obj/mainnube2.o src/mainnube2.cpp

obj/mainsim.o : src/mainsim.cpp include/simulador.h
	g++ -c -I./include -o obj/mainsim.o src/mainsim.cpp

clean :
	@echo Borrando los ficheros .o del directorio obj...
	rm obj/*.o
