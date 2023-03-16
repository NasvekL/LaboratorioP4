# Definición de variables
CC = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
EXECUTABLE = programa

# Definición de dependencias
SOURCES = main.cpp DtObjetoRoto.cpp JuegoMesa.cpp Libro.cpp Ninio.cpp Objeto.cpp Utils.cpp
HEADERS = DtObjetoRoto.h JuegoMesa.h Libro.h Ninio.h Objeto.cpp.h Utils.h
OBJECTS = $(SOURCES:.cpp=.o)

# Reglas de compilación
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

# Regla de limpieza
clean:
	rm -rf *.o $(EXECUTABLE)

# Dependencias
main.o: main.cpp $(HEADERS)
DtObjetoRoto.o: DtObjetoRoto.cpp DtObjetoRoto.h
JuegoMesa.o: JuegoMesa.cpp JuegoMesa.h
Libro.o: Libro.cpp Libro.h
Ninio.o: Ninio.cpp Ninio.h
Objeto.o: Objeto.cpp Objeto.h
Utils.o: Utils.cpp Utils.h