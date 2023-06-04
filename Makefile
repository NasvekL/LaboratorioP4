CC=g++
CC-=g++ -c

INC=include/Clases/Curso.h include/Clases/Ejercicio.h include/Clases/Estudiante.h include/Clases/Idioma.h include/Clases/Inscripcion.h include/Utils.h include/Clases/Leccion.h include/Clases/Profesor.h include/Clases/Progreso.h include/Clases/RellenarPalabras.h include/Clases/Traduccion.h include/Clases/Usuario.h include/Controlador/ControladorCurso.h include/Controlador/ControladorUsuario.h include/DTs/DTCurso.h include/DTs/DTEjercicio.h include/DTs/DTEstadisticaCurso.h include/DTs/DTEstadisticaEstudiante.h include/DTs/DTEstadisticaProfesor.h include/DTs/DTEstudiante.h include/DTs/DTEstudianteSC.h include/DTs/DTLeccion.h include/DTs/DTNotificacion.h include/DTs/DTProfesor.h include/DTs/DTProfesorSC.h include/Interfaces/IControladorCurso.h include/Interfaces/IControladorUsuario.h include/Utils.h include/Interfaces/FactoryController.h include/Interfaces/IObserver.h
O=main.o Curso.o Ejercicio.o Estudiante.o Idioma.o Inscripcion.o Leccion.o Profesor.o Progreso.o RellenarPalabras.o Traduccion.o Usuario.o ControladorCurso.o ControladorUsuario.o DTCurso.o DTEjercicio.o DTEstadisticaCurso.o DTEstadisticaEstudiante.o DTEstadisticaProfesor.o DTEstudiante.o DTEstudianteSC.o DTLeccion.o DTNotificacion.o DTProfesor.o DTProfesorSC.o IControladorCurso.o IControladorUsuario.o IObserver.o FactoryController.o 

all: ejecutable

ejecutable: $(O)
	$(CC) $(O) -o ejecutable

main.o: main.cpp $(INC)
	$(CC-) main.cpp
Curso.o: src/Clases/Curso.cpp $(INC)
	$(CC-) src/Clases/Curso.cpp
Ejercicio.o: src/Clases/Ejercicio.cpp $(INC)
	$(CC-) src/Clases/Ejercicio.cpp
Estudiante.o: src/Clases/Estudiante.cpp $(INC)
	$(CC-) src/Clases/Estudiante.cpp
Idioma.o: src/Clases/Idioma.cpp $(INC)
	$(CC-) src/Clases/Idioma.cpp
Inscripcion.o: src/Clases/Inscripcion.cpp $(INC)
	$(CC-) src/Clases/Inscripcion.cpp
Leccion.o: src/Clases/Leccion.cpp $(INC)
	$(CC-) src/Clases/Leccion.cpp
Profesor.o: src/Clases/Profesor.cpp $(INC)
	$(CC-) src/Clases/Profesor.cpp
Progreso.o: src/Clases/Progreso.cpp $(INC)
	$(CC-) src/Clases/Progreso.cpp
RellenarPalabras.o: src/Clases/RellenarPalabras.cpp $(INC)
	$(CC-) src/Clases/RellenarPalabras.cpp
Traduccion.o: src/Clases/Traduccion.cpp $(INC)
	$(CC-) src/Clases/Traduccion.cpp
Usuario.o: src/Clases/Usuario.cpp $(INC)
	$(CC-) src/Clases/Usuario.cpp
ControladorCurso.o: src/Controladores/ControladorCurso.cpp $(INC)
	$(CC-) src/Controladores/ControladorCurso.cpp
ControladorUsuario.o: src/Controladores/ControladorUsuario.cpp $(INC)
	$(CC-) src/Controladores/ControladorUsuario.cpp
DTCurso.o: src/DTs/DTCurso.cpp $(INC)
	$(CC-) src/DTs/DTCurso.cpp
DTEjercicio.o: src/DTs/DTEjercicio.cpp $(INC)
	$(CC-) src/DTs/DTEjercicio.cpp
DTEstadisticaCurso.o: src/DTs/DTEstadisticaCurso.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaCurso.cpp
DTEstadisticaEstudiante.o: src/DTs/DTEstadisticaEstudiante.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaEstudiante.cpp\
DTEstadisticaProfesor.o: src/DTs/DTEstadisticaProfesor.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaProfesor.cpp
DTEstudiante.o: src/DTs/DTEstudiante.cpp $(INC)
	$(CC-) src/DTs/DTEstudiante.cpp
DTEstudianteSC.o: src/DTs/DTEstudianteSC.cpp $(INC)
	$(CC-) src/DTs/DTEstudianteSC.cpp
DTLeccion.o: src/DTs/DTLeccion.cpp $(INC)
	$(CC-) src/DTs/DTLeccion.cpp
DTNotificacion.o: src/DTs/DTNotificacion.cpp $(INC)
	$(CC-) src/DTs/DTNotificacion.cpp
DTProfesor.o: src/DTs/DTProfesor.cpp $(INC)
	$(CC-) src/DTs/DTProfesor.cpp
DTProfesorSC.o: src/DTs/DTProfesorSC.cpp $(INC)
	$(CC-) src/DTs/DTProfesorSC.cpp
IControladorCurso.o: src/Interfaces/IControladorCurso.cpp $(INC)
	$(CC-) src/Interfaces/IControladorCurso.cpp
IControladorUsuario.o: src/Interfaces/IControladorUsuario.cpp $(INC)
	$(CC-) src/Interfaces/IControladorUsuario.cpp
FactoryController.o: src/Interfaces/FactoryController.cpp $(INC)
	$(CC-) src/Interfaces/FactoryController.cpp
IObserver.o: src/Interfaces/IObserver.cpp $(INC)
	$(CC-) src/Interfaces/IObserver.cpp
clean:
	rm *.o ejecutable