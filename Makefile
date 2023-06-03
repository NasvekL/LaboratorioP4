CC=g++
CC-=g++ -c

INC=include/JuegoMesa.h include/Ninio.h include/Objeto.h include/Libro.h include/DtObjetoRoto.h include/Utils.h
O=main.o DtObjetoRoto.o JuegoMesa.o Libro.o Ninio.o Objeto.o

all: ejecutable

ejecutable: $(O)
	$(CC) $(O) -o ejecutable

main.o: main.cpp $(INC)
	$(CC-) main.cpp
Curso.o: src/Curso.cpp $(INC)
	$(CC-) src/Curso.cpp
Ejercicio.o: src/Ejercicio.cpp $(INC)
	$(CC-) src/Ejercicio.cpp
Estudiante.o: src/Estudiante.cpp $(INC)
	$(CC-) src/Estudiante.cpp
Idioma.o: src/Idioma.cpp $(INC)
	$(CC-) src/Idioma.cpp
Inscripcion.o: src/Inscripcion.cpp $(INC)
	$(CC-) src/Inscripcion.cpp
Leccion.o: src/Leccion.cpp $(INC)
	$(CC-) src/Leccion.cpp
Profesor.o: src/Profesor.cpp $(INC)
	$(CC-) src/Profesor.cpp
Progreso.o: src/Progreso.cpp $(INC)
	$(CC-) src/Progreso.cpp
RellenarPalabras.o: src/RellenarPalabras.cpp $(INC)
	$(CC-) src/RellenarPalabras.cpp
Traduccion.o: src/Traduccion.cpp $(INC)
	$(CC-) src/Traduccion.cpp
Usuario.o: src/Usuario.cpp $(INC)
	$(CC-) src/Usuario.cpp
ControladorCurso.o: src/ControladorCurso.cpp $(INC)
	$(CC-) src/ControladorCurso.cpp
ControladorUsuario.o: src/ControladorUsuario.cpp $(INC)
	$(CC-) src/ControladorUsuario.cpp
DTCurso.o: src/DTCurso.cpp $(INC)
	$(CC-) src/DTCurso.cpp
clean:
	rm *.o ejecutable