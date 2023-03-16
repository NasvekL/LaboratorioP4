
all: output

output: main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o
	g++ main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o Utils.o -o output

main.o: main.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c main.cpp
DtObjetoRoto.o: DtObjetoRoto.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c DtObjetoRoto.cpp
JuegoMesa.o: JuegoMesa.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c JuegoMesa.cpp
Libro.o: Libro.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c Libro.cpp
Ninio.o: Ninio.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c Ninio.cpp
Objeto.o: Objeto.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c Objeto.cpp
Utils.o: Utils.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c Utils.cpp
clean:
	rm *.o output