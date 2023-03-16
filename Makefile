
all: output

output: main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o
	g++ main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o -o output

main.o: main.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c main.cpp
DtObjetoRoto.o: src/DtObjetoRoto.cpp
	g++ -c src/DtObjetoRoto.cpp
JuegoMesa.o: src/JuegoMesa.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c src/JuegoMesa.cpp
Libro.o: src/Libro.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c src/Libro.cpp
Ninio.o: src/Ninio.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c src/Ninio.cpp
Objeto.o: src/Objeto.cpp include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
	g++ -c src/Objeto.cpp
clean:
	rm *.o output