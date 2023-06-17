CC=g++ -g
CC-=g++ -g -c
BIN_DIR = build

INC=include/Clases/Curso.h include/Clases/Ejercicio.h include/Clases/Estudiante.h include/Clases/Idioma.h include/DTs/DTFecha.h include/Clases/Inscripcion.h include/Utils.h include/Clases/Leccion.h include/Clases/Profesor.h include/Clases/Progreso.h include/Clases/RellenarPalabras.h include/Clases/Traduccion.h include/Clases/Usuario.h include/Controladores/ControladorCurso.h include/Controladores/ControladorUsuario.h include/DTs/DTCurso.h include/DTs/DTEjercicio.h include/DTs/DTEstadisticaCurso.h include/DTs/DTEstadisticaEstudiante.h include/DTs/DTEstadisticaProfesor.h include/DTs/DTEstudiante.h include/DTs/DTEstudianteSC.h include/DTs/DTTraduccion.h include/DTs/DTRellenarPalabras.h include/DTs/DTLeccion.h include/DTs/DTNotificacion.h include/DTs/DTProfesor.h include/DTs/DTProfesorSC.h include/Interfaces/IControladorCurso.h include/Interfaces/IControladorUsuario.h include/Utils.h include/FactoryController.h include/Interfaces/IObserver.h
O= $(BIN_DIR)/main.o $(BIN_DIR)/DTRellenarPalabras.o $(BIN_DIR)/DTTraduccion.o $(BIN_DIR)/IControladorCurso.o $(BIN_DIR)/IControladorUsuario.o $(BIN_DIR)/IObserver.o $(BIN_DIR)/Curso.o $(BIN_DIR)/Ejercicio.o $(BIN_DIR)/Estudiante.o $(BIN_DIR)/Idioma.o $(BIN_DIR)/Inscripcion.o $(BIN_DIR)/Leccion.o $(BIN_DIR)/Profesor.o $(BIN_DIR)/Progreso.o $(BIN_DIR)/RellenarPalabras.o $(BIN_DIR)/Traduccion.o $(BIN_DIR)/Usuario.o $(BIN_DIR)/ControladorCurso.o $(BIN_DIR)/ControladorUsuario.o $(BIN_DIR)/DTCurso.o $(BIN_DIR)/DTEjercicio.o $(BIN_DIR)/DTEstadisticaCurso.o $(BIN_DIR)/DTEstadisticaEstudiante.o $(BIN_DIR)/DTEstadisticaProfesor.o $(BIN_DIR)/DTEstudiante.o $(BIN_DIR)/DTEstudianteSC.o $(BIN_DIR)/DTLeccion.o $(BIN_DIR)/DTNotificacion.o $(BIN_DIR)/DTProfesor.o $(BIN_DIR)/DTFecha.o $(BIN_DIR)/DTProfesorSC.o $(BIN_DIR)/FactoryController.o


all: create_bin_dir $(BIN_DIR)/ejecutable

$(BIN_DIR)/ejecutable: $(O)
	$(CC) $(O) -o $(BIN_DIR)/ejecutable

$(BIN_DIR)/main.o: main.cpp $(INC)
	$(CC-) main.cpp -o $(BIN_DIR)/main.o

$(BIN_DIR)/Curso.o: src/Clases/Curso.cpp $(INC)
	$(CC-) src/Clases/Curso.cpp -o $(BIN_DIR)/Curso.o

$(BIN_DIR)/Ejercicio.o: src/Clases/Ejercicio.cpp $(INC)
	$(CC-) src/Clases/Ejercicio.cpp -o $(BIN_DIR)/Ejercicio.o

$(BIN_DIR)/Estudiante.o: src/Clases/Estudiante.cpp $(INC)
	$(CC-) src/Clases/Estudiante.cpp -o $(BIN_DIR)/Estudiante.o

$(BIN_DIR)/Usuario.o: src/Clases/Usuario.cpp $(INC)
	$(CC-) src/Clases/Usuario.cpp -o $(BIN_DIR)/Usuario.o
$(BIN_DIR)/Idioma.o: src/Clases/Idioma.cpp $(INC)
	$(CC-) src/Clases/Idioma.cpp -o $(BIN_DIR)/Idioma.o

$(BIN_DIR)/Inscripcion.o: src/Clases/Inscripcion.cpp $(INC)
	$(CC-) src/Clases/Inscripcion.cpp -o $(BIN_DIR)/Inscripcion.o

$(BIN_DIR)/Leccion.o: src/Clases/Leccion.cpp $(INC)
	$(CC-) src/Clases/Leccion.cpp -o $(BIN_DIR)/Leccion.o

$(BIN_DIR)/Profesor.o: src/Clases/Profesor.cpp $(INC)
	$(CC-) src/Clases/Profesor.cpp -o $(BIN_DIR)/Profesor.o

$(BIN_DIR)/Progreso.o: src/Clases/Progreso.cpp $(INC)
	$(CC-) src/Clases/Progreso.cpp -o $(BIN_DIR)/Progreso.o

$(BIN_DIR)/RellenarPalabras.o: src/Clases/RellenarPalabras.cpp $(INC)
	$(CC-) src/Clases/RellenarPalabras.cpp -o $(BIN_DIR)/RellenarPalabras.o

$(BIN_DIR)/Traduccion.o: src/Clases/Traduccion.cpp $(INC)
	$(CC-) src/Clases/Traduccion.cpp -o $(BIN_DIR)/Traduccion.o


	$(CC-) src/Clases/Usuario.cpp -o $(BIN_DIR)/Usuario.o

$(BIN_DIR)/ControladorCurso.o: src/Controladores/ControladorCurso.cpp $(INC)
	$(CC-) src/Controladores/ControladorCurso.cpp -o $(BIN_DIR)/ControladorCurso.o

$(BIN_DIR)/ControladorUsuario.o: src/Controladores/ControladorUsuario.cpp $(INC)
	$(CC-) src/Controladores/ControladorUsuario.cpp -o $(BIN_DIR)/ControladorUsuario.o

$(BIN_DIR)/DTCurso.o: src/DTs/DTCurso.cpp $(INC)
	$(CC-) src/DTs/DTCurso.cpp -o $(BIN_DIR)/DTCurso.o

$(BIN_DIR)/DTEjercicio.o: src/DTs/DTEjercicio.cpp $(INC)
	$(CC-) src/DTs/DTEjercicio.cpp -o $(BIN_DIR)/DTEjercicio.o

$(BIN_DIR)/DTEstadisticaCurso.o: src/DTs/DTEstadisticaCurso.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaCurso.cpp -o $(BIN_DIR)/DTEstadisticaCurso.o

$(BIN_DIR)/DTEstadisticaEstudiante.o: src/DTs/DTEstadisticaEstudiante.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaEstudiante.cpp -o $(BIN_DIR)/DTEstadisticaEstudiante.o

$(BIN_DIR)/DTEstadisticaProfesor.o: src/DTs/DTEstadisticaProfesor.cpp $(INC)
	$(CC-) src/DTs/DTEstadisticaProfesor.cpp -o $(BIN_DIR)/DTEstadisticaProfesor.o

$(BIN_DIR)/DTEstudiante.o: src/DTs/DTEstudiante.cpp $(INC)
	$(CC-) src/DTs/DTEstudiante.cpp -o $(BIN_DIR)/DTEstudiante.o

$(BIN_DIR)/DTEstudianteSC.o: src/DTs/DTEstudianteSC.cpp $(INC)
	$(CC-) src/DTs/DTEstudianteSC.cpp -o $(BIN_DIR)/DTEstudianteSC.o

$(BIN_DIR)/DTLeccion.o: src/DTs/DTLeccion.cpp $(INC)
	$(CC-) src/DTs/DTLeccion.cpp -o $(BIN_DIR)/DTLeccion.o

$(BIN_DIR)/DTNotificacion.o: src/DTs/DTNotificacion.cpp $(INC)
	$(CC-) src/DTs/DTNotificacion.cpp -o $(BIN_DIR)/DTNotificacion.o

$(BIN_DIR)/DTProfesor.o: src/DTs/DTProfesor.cpp $(INC)
	$(CC-) src/DTs/DTProfesor.cpp -o $(BIN_DIR)/DTProfesor.o

$(BIN_DIR)/DTProfesorSC.o: src/DTs/DTProfesorSC.cpp $(INC)
	$(CC-) src/DTs/DTProfesorSC.cpp -o $(BIN_DIR)/DTProfesorSC.o

$(BIN_DIR)/FactoryController.o: src/FactoryController.cpp $(INC)
	$(CC-) src/FactoryController.cpp -o $(BIN_DIR)/FactoryController.o

$(BIN_DIR)/DTFecha.o: src/DTs/DTFecha.cpp $(INC)
	$(CC-) src/DTs/DTFecha.cpp -o $(BIN_DIR)/DTFecha.o

$(BIN_DIR)/IControladorCurso.o: src/Interfaces/IControladorCurso.cpp $(INC)
	$(CC-) src/Interfaces/IControladorCurso.cpp -o $(BIN_DIR)/IControladorCurso.o

$(BIN_DIR)/IControladorUsuario.o: src/Interfaces/IControladorUsuario.cpp $(INC)
	$(CC-) src/Interfaces/IControladorUsuario.cpp -o $(BIN_DIR)/IControladorUsuario.o

$(BIN_DIR)/IObserver.o: src/Interfaces/IObserver.cpp $(INC)
	$(CC-) src/Interfaces/IObserver.cpp -o $(BIN_DIR)/IObserver.o

$(BIN_DIR)/DTTraduccion.o: src/DTs/DTTraduccion.cpp $(INC)
	$(CC-) src/DTs/DTTraduccion.cpp -o $(BIN_DIR)/DTTraduccion.o

$(BIN_DIR)/DTRellenarPalabras.o: src/DTs/DTRellenarPalabras.cpp $(INC)
	$(CC-) src/DTs/DTRellenarPalabras.cpp -o $(BIN_DIR)/DTRellenarPalabras.o

create_bin_dir:
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(BIN_DIR)