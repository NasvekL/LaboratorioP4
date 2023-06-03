CC=g++
CC-=g++ -c

INC=include/Curso.h include/Ejercicio.h include/Estudiante.h include/Idioma.h include/Inscripcion.h include/Utils.h include/Leccion.h include/Profesor.h include/Progreso.h include/RellenarPalabras.h include/Traduccion.h include/Usuario.h include/ControladorCurso.h include/ControladorUsuario.h include/DTCurso.h include/DTEjercicio.h include/DTEstadisticaCurso.h include/DTEstadisticaEstudiante.h include/DTEstadisticaProfesor.h include/DTEstudiante.h include/DTEstudianteSC.h include/DTFECHA.h include/DTLeccion.h include/DTNotificacion.h include/DTProfesor.h include/DTProfesorSC.h include/IControladorCurso.h include/IControladorUsuario.h include/FactoryController.h include/IObserver.h 
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
DTEjercicio.o: src/DTEjercicio.cpp $(INC)
	$(CC-) src/DTEjercicio.cpp
DTEstadisticaCurso.o: src/DTEstadisticaCurso.cpp $(INC)
	$(CC-) src/DTEstadisticaCurso.cpp
DTEstadisticaEstudiante.o: src/DTEstadisticaEstudiante.cpp $(INC)
	$(CC-) src/DTEstadisticaEstudiante.cpp\
DTEstadisticaProfesor.o: src/DTEstadisticaProfesor.cpp $(INC)
	$(CC-) src/DTEstadisticaProfesor.cpp
DTEstudiante.o: src/DTEstudiante.cpp $(INC)
	$(CC-) src/DTEstudiante.cpp
DTEstudianteSC.o: src/DTEstudianteSC.cpp $(INC)
	$(CC-) src/DTEstudianteSC.cpp
DTLeccion.o: src/DTLeccion.cpp $(INC)
	$(CC-) src/DTLeccion.cpp
DTNotificacion.o: src/DTNotificacion.cpp $(INC)
	$(CC-) src/DTNotificacion.cpp
DTProfesor.o: src/DTProfesor.cpp $(INC)
	$(CC-) src/DTProfesor.cpp
DTProfesorSC.o: src/DTProfesorSC.cpp $(INC)
	$(CC-) src/DTProfesorSC.cpp
IControladorCurso.o: src/IControladorCurso.cpp $(INC)
	$(CC-) src/IControladorCurso.cpp
IControladorUsuario.o: src/IControladorUsuario.cpp $(INC)
	$(CC-) src/IControladorUsuario.cpp
FactoryController.o: src/FactoryController.cpp $(INC)
	$(CC-) src/FactoryController.cpp
IObserver.o: src/IObserver.cpp $(INC)
	$(CC-) src/IObserver.cpp
clean:
	rm *.o ejecutable