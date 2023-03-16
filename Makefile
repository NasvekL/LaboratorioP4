# Definición de variables
CC = g++
CFLAGS = -c -Wall
LFLAGS = -Wall
EXECUTABLE = programa

# Definición de dependencias
SOURCES = main.cpp DtObjetoRoto.cpp JuegoMesa.cpp Libro.cpp Ninio.cpp Objeto.cpp Utils.cpp
HEADERS = DtObjetoRoto.h JuegoMesa.h Libro.cpp.h Ninio.h Objeto.cpp.h Utils.h
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
file1.o: file1.cpp file1.h
file2.o: file2.cpp file2.h
file3.o: file3.cpp file3.h
file4.o: file4.cpp file4.h
file5.o: file5.cpp file5.h