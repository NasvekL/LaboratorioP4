CC=g++

INC=include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
O=main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o

all: ejecutable

ejecutable: $(O)
	$(CC) $(O) -o ejecutable

main.o: main.cpp $(INC)
	$(CC) -c main.cpp
DtObjetoRoto.o: src/DtObjetoRoto.cpp $(INC)
	$(CC) -c src/DtObjetoRoto.cpp
JuegoMesa.o: src/JuegoMesa.cpp $(INC)
	$(CC) -c src/JuegoMesa.cpp
Libro.o: src/Libro.cpp $(INC)
	$(CC) -c src/Libro.cpp
Ninio.o: src/Ninio.cpp $(INC)
	$(CC) -c src/Ninio.cpp
Objeto.o: src/Objeto.cpp $(INC)
	$(CC) -c src/Objeto.cpp

clean:
	rm *.o ejecutable