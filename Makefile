CC=g++
CC-=g++ -c

INC=include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
O=main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o

all: ejecutable

ejecutable: $(O)
	$(CC) $(O) -o ejecutable

main.o: main.cpp $(INC)
	$(CC-) main.cpp
DtObjetoRoto.o: src/DtObjetoRoto.cpp $(INC)
	$(CC-) src/DtObjetoRoto.cpp
JuegoMesa.o: src/JuegoMesa.cpp $(INC)
	$(CC-) src/JuegoMesa.cpp
Libro.o: src/Libro.cpp $(INC)
	$(CC-) src/Libro.cpp
Ninio.o: src/Ninio.cpp $(INC)
	$(CC-) src/Ninio.cpp
Objeto.o: src/Objeto.cpp $(INC)
	$(CC-) src/Objeto.cpp

clean:
	rm *.o ejecutable