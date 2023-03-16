output: main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o
	g++ main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o -o output

main.o: main.cpp JuegoMesa.h Ninio.h Objeto.h Libro.h DtObjetoRoto.h Utils.h
	g++ -c main.cpp
DtObjetoRoto.o: DtObjetoRoto.cpp
	g++ -c DtObjetoRoto.cpp
JuegoMesa.o: JuegoMesa.cpp Objeto.h
	g++ -c JuegoMesa.cpp
Libro.o: Libro.cpp Objeto.h Utils.h
	g++ -c Libro.cpp
Ninio.o: Ninio.cpp Objeto.h Utils.h
	g++ -c Ninio.cpp
Objeto.o: Objeto.cpp Utils.h Ninio.h
	g++ -c Objeto.cpp
Utils.o: Utils.cpp
	g++ -c Utils.cpp
clean:
	rm *.o output