output: main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o
	g++ main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o -o output

main.o: main.cpp
	g++ -c main.cpp
DtObjetoRoto.o: DtObjetoRoto.cpp
	g++ -c DtObjetoRoto.cpp
JuegoMesa.o: JuegoMesa.cpp
	g++ -c JuegoMesa.cpp
Libro.o: Libro.cpp
	g++ -c Libro.cpp
Ninio.o: Ninio.cpp
	g++ -c Ninio.cpp
Objeto.o: Objeto.cpp
	g++ -c Objeto.cpp
Utils.o: Utils.cpp
	g++ -c Utils.cpp
clean:
	rm *.o output