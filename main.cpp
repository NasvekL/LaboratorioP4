#include "include/FactoryController.h"
//#include "include/DTs/DTRellenarPalabras.h"
//#include "include/DTs/DTTraduccion.h"



// Macros para definir los códigos de escape ANSI para colores
#define RESET    "\033[0m"
#define ROJO     "\033[31m"
#define VERDE    "\x1b[38;5;10m"
#define AMARILLO "\x1b[38;5;11m"
#define AZUL     "\x1b[38;5;45m"
bool seAgregaronLosDatos = false;

void ingresarPrevias();
void ingresarLecciones();
void inscribirUsuarios();
int seleccionEstudianteOProfesor();
DTEstudiante crearDTEstudiante();
DTProfesor crearDTProfesor();
DTCurso crearDTCurso();
DTLeccion crearDTLeccion(int &numLec);
DTLeccion crearDTLeccion2(int &numLec);
int entradaInt();
string entradaString();
bool quiereContinuar(string p);
void presionaParaContinuar();
void limpiarLog();
void imprimir(string texto);
void imprimir(string texto, string color);
list<string> separarString(const string& str, char delimiter);
void ingresarUsuarios();
void ingresarIdiomas();
void ingresarCursos();
void ingresarHabilitarCursos();
DTRellenarPalabras crearDTRellenarPalabras(int numLec);
DTTraduccion crearDTTraduccion(int numLec);
int seleccionTipoEjercicio();


//Desplegar menu por consola
int menuPrincipal(){
    system("clear");
    imprimir("Menu");
    imprimir("0. Salir");
    imprimir("1. Alta de usuario");
    imprimir("2. Consulta de usuario");
    imprimir("3. Alta idioma");
    imprimir("4. Consultar idiomas");
    imprimir("5. Alta de curso");
    imprimir("6. Agregar leccion");
    imprimir("7. Agregar ejercicio");
    imprimir("8. Habilitar curso");
    imprimir("9. Eliminar curso");
    imprimir("10. Consultar curso");
    imprimir("11. Inscribirse a curso");
    imprimir("12. Realizar ejercicio");
    imprimir("13. Consultar estadisticas");
    imprimir("14. Suscribirse a notificaciones");
    imprimir("15. Consulta de notificaciones");
    imprimir("16. Eliminar suscripciones");
    if (!seAgregaronLosDatos)
        imprimir("17. Agregar datos", VERDE);
    imprimir("Ingrese una opcion: ");
    int opcion = entradaInt();
    return opcion;
}
//HOLA


int main(){
    limpiarLog();
    cout.precision(0);
    /*
                    ------PARA UTILIZAR DENTRO DE CADA CASO------
                    copiar siempre la fabrica y luego el controlaror
                            que vayamos a usar.
    */
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();



    int opcion = 1;
    while(opcion != 0){
        opcion = menuPrincipal();
        switch (opcion){
            case 0:{
                imprimir("Saliendo...");
                break;
            }
            case 1:{
                //Alta usuario
                system("clear");
                contUsuario.deleteDataIngresado();//Abrimos paraguas por las dudas
                
                int seleccion = seleccionEstudianteOProfesor();
                system("clear");
                switch (seleccion){
                    case 1:{
                        DTEstudiante est = crearDTEstudiante();
                        contUsuario.setDatoEstudiante(est);
                        contUsuario.confirmarAltaUsuario();
                        imprimir("Estudiante creado", VERDE);
                        presionaParaContinuar();
                        break;
                    }
                    case 2:{
                        //
                        DTProfesor prof = crearDTProfesor();
                        contUsuario.setDatoProfesor(prof);
                        contUsuario.confirmarAltaUsuario();
                        imprimir("Profesor creado", VERDE);
                        presionaParaContinuar();
                        break;
                    }
                    default:{
                        imprimir("Opcion invalida", AMARILLO);
                        presionaParaContinuar();
                        break;
                    }
                }
                break;
            }
            case 2:{
                //Consulta de Usuario
                system("clear");
                list<string> listaUsuarios = contUsuario.consultarUsuario();
                std::list<string>::iterator it;
                for (it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
                    imprimir(*it);
                }
                imprimir("Ingrese el nick deseado", AMARILLO);
                string nick;
                nick = entradaString();
                if(contUsuario.getTipoUsuario(nick)=="estudiante"){
                    contUsuario.seleccionarUsuario(nick);
                    DTEstudiante dte = contUsuario.getDatoEstudiante();
                    imprimir("Nombre: " + dte.getNombre());
                    imprimir("Descripcion: "+ dte.getDescripcion());
                    imprimir("Pais: " + dte.getPais());
                    presionaParaContinuar();
                } 
                else{ 
                    contUsuario.seleccionarUsuario(nick);
                    DTProfesor dtp = contUsuario.getDatoProfesor();
                    imprimir("Nombre", AMARILLO + dtp.getNombre());
                    imprimir("Descripcion", AMARILLO + dtp.getDescripcion());
                    imprimir("Instituto", AMARILLO + dtp.getInstituto());
                    imprimir("Idiomas", AMARILLO);
                    set<string> idi = dtp.getIdiomas();
                    set<string>::iterator it;
                    for (it = idi.begin(); it != idi.end(); ++it) {
                        imprimir(*it);
                    }
                    presionaParaContinuar();
                }        
                break;
            }
            case 3:{
                //Alta idioma
                system("clear");
                imprimir("Ingrese el nombre idioma:");
                string idioma = entradaString();
                if(contCurso.confirmarAltaIdioma(idioma)==false)
                    imprimir("Ya existe el idioma", AMARILLO);
                else
                    imprimir("Idioma creado", VERDE);
                presionaParaContinuar();
                break;
            }
            case 4:{
                //Consultar idiomas
                system("clear");
                list<string> listaId = contUsuario.listarIdiomas();
                for(auto it = listaId.begin(); it != listaId.end(); ++it){
                    imprimir(*it);
                }
                presionaParaContinuar();
                break;
            }
            case 5:{
                //Alta de curso:
                system("clear");
                //Elijo el profesor
                list<string> profes = contCurso.listarProfe();
                for (auto it = profes.begin(); it != profes.end(); ++it) {
                        imprimir(*it);
                }
                imprimir("Ingrese el nickname del profesor que dictara el curso:", AMARILLO);
                string nick = entradaString();
                contCurso.seleccionarProfesor(nick);
                //Defino el resto de datos del curso
                DTCurso curso = crearDTCurso();
                //Guardo el curso en un DT auxiliar en el controlador
                contCurso.setDatoDeCurso(curso);
                set<Idioma*> idiomass = contCurso.listarIdiomasProfesor();
                for(auto it = idiomass.begin(); it != idiomass.end(); ++it){
                    imprimir((*it)->getNombreIdioma());
                }
                imprimir("Ingrese el idioma del curso: ", AMARILLO);
                string idioma = entradaString();
                contCurso.seleccionIdioma(idioma);
                imprimir("Agregar leccion S/N", AMARILLO);
                string opcion = entradaString();
                int numLec = 0;
                while((opcion == "S") || (opcion == "s")){
                    DTLeccion leccion = crearDTLeccion2(numLec);
                    contCurso.setDatosDeLeccion(leccion);
                    imprimir("Quiere agregar ejercicio S/N", AMARILLO);
                    string opcion2 = entradaString();
                    if((opcion2=="S") || (opcion2=="s")){
                        imprimir("Ingrese la cantidad de ejercicios que desea agregar:", AMARILLO);
                        int cantEjs = entradaInt();
                        leccion.setCantEj(cantEjs);   
                        for(int i = 1; i <= cantEjs; i++){
                        imprimir("Ingrese tipo de ejercicio", AMARILLO);
                        imprimir("Completar/Traduccion", AMARILLO);
                        string opcion3 = entradaString();
                        if(opcion3=="Completar" || opcion3=="completar"){
                            DTRellenarPalabras ejercicio = crearDTRellenarPalabras(numLec);
                            contCurso.agregarDatosRellenarPalabras(ejercicio);
                        }
                        else{
                            DTTraduccion ejercicio = crearDTTraduccion(numLec);
                            contCurso.agregarDatosTraduccion(ejercicio);
                        }                            
                            
                        }
                    }
                    
                    if(!quiereContinuar("Agregar otra leccion"))
                        opcion = "N";
                }
                if(contCurso.altaCurso())
                    imprimir("Curso creado", VERDE);
                else
                    imprimir("Curso no creado", ROJO); 
                presionaParaContinuar();
                break;
            }
            case 6:{
                //Agregar leccion
                system("clear");
                imprimir("Cursos no habilitados disponibles:", AMARILLO);;
                list<string> cursosNH = contCurso.listarCursosNoHabilitados(); 
                int a=1;
                for(auto it = cursosNH.begin(); it != cursosNH.end(); ++it){
                    imprimir(to_string(a)+" "+*it);
                    a++;
                }
                imprimir("Escribe el nombre del Curso:" , AMARILLO);
                string cursoSeleccionado = entradaString();
                int numLec = contCurso.getNumeroDeLeccion(cursoSeleccionado);
                DTLeccion leccion = crearDTLeccion(numLec);
                contCurso.setDatosDeLeccion(leccion);
                contCurso.setDatoDeLeccion(leccion);
                //LOGICA PARA AGREGAR EJERCICIOS
                int ejsPorAgregar = leccion.getCantidadDeEjercicios();
                for(int i = 1; i <= ejsPorAgregar; i++){
                    int seleccion = seleccionTipoEjercicio();
                    switch(seleccion){
                        case 1:{
                            DTTraduccion tradu = crearDTTraduccion(numLec);
                            contCurso.agregarDatosTraduccion(tradu);
                            break;
                        }
                        case 2:{
                            DTRellenarPalabras rellpab = crearDTRellenarPalabras(numLec);
                            contCurso.agregarDatosRellenarPalabras(rellpab);
                            break;
                        }
                    }
                }
                contCurso.altaLeccion(cursoSeleccionado);
                imprimir("Leccion creada", VERDE);
                presionaParaContinuar();
                break;
            }
            case 7:{
                //Agregar ejercicio
                system("clear");
                //interfazCurso->agregarEjercicio();
                imprimir ( "Cursos no habilitados disponibles:", AMARILLO );
                contCurso.listarCursosNoHabilitados();
                list<string> cursosNH = contCurso.listarCursosNoHabilitados(); 
                int a=1;
                for(auto it = cursosNH.begin(); it != cursosNH.end(); ++it){
                    imprimir(to_string(a)+" "+*it);
                }
                imprimir("Elija un curso:", AMARILLO);
                string cursoSelec = entradaString();
                Curso* cur = contCurso.getCurso(cursoSelec);
                imprimir("Lecciones del curso:", AMARILLO);
                list<Leccion*> lecciones = cur->getLecciones();

                if (!lecciones.empty()) {
                    int i = 1;
                    for (const auto& leccion : lecciones) {
                        imprimir(to_string(i) + ". " + leccion->getTema()); 
                        i++;
                    }

                    imprimir("Elija una opcion de lección(nro):", AMARILLO);
                    int lecSelec = entradaInt();    
                    Leccion* leccionSeleccionada = nullptr; 
                    for (const auto& leccion : lecciones) {
                        if (leccion->getNumero() == lecSelec) {
                            leccionSeleccionada = leccion;
                            break;
                        }
                    }

                    if (leccionSeleccionada != nullptr) {
                        imprimir("Ingrese el tipo de ejercicio (Completar o Traduccion):", AMARILLO);
                        string tipo = entradaString();
                        if ((tipo == "completar") || (tipo == "Completar")) {
                            DTRellenarPalabras rell = crearDTRellenarPalabras(lecSelec);
                            contCurso.setDatosEjercicioCompletarPalabras(rell);
                        }else if ((tipo == "traduccion") || (tipo == "Traduccion")){                            
                            DTTraduccion tradu = crearDTTraduccion(lecSelec);
                            contCurso.setDatosEjercicioTraduccion(tradu);
                        } else {
                            imprimir("Tipo de ejercicio no válido", ROJO);
                            
                        }
                        
                        contCurso.altaEjercicio(leccionSeleccionada);
                        imprimir("Ejercicio creado", VERDE);
                        
                    }

                }
            else imprimir("No hay lecciones en el curso", ROJO);
            presionaParaContinuar();
                break;
            }
            case 8:{
                //Habilitar curso
                system("clear");
                list<string> listaC = contCurso.listarCursosNoHabilitados();
                int a=1;
                for(auto it = listaC.begin(); it != listaC.end(); ++it){
                    imprimir(to_string(a) + " " + *it);
                    a++;
                }
                imprimir("Escriba el nombre del curso que desea habilitar:");
                string curso = entradaString();
                bool habilito = contCurso.habilitarCurso(curso);
                if(habilito){
                imprimir("Curso habilitado", VERDE);
                }
                else{
                    imprimir("Curso no contiene todas las lecciones con al menos un ejercicio", ROJO);
                }
                presionaParaContinuar();
                break;
            }
            case 9:{
                //Eliminar curso
                system("clear");
                set<string> cursos = contCurso.listarNombresDeCursos();
                int a=1;
                for(auto it = cursos.begin(); it != cursos.end(); ++it){
                    imprimir(to_string(a) + " " + *it);
                    a++;
                }
                imprimir("Escriba el nombre del curso que desea eliminar:");
                string curso = entradaString();
                contCurso.eliminarCurso(curso);
                imprimir("Curso eliminado", VERDE);
                presionaParaContinuar();
                break;
            }
            case 10:{
                //Consultar curso
                system("clear");
                imprimir("Cursos Disponibles:");
                set<string> nombreCursos = contCurso.listarNombresDeCursos();
                for(auto it = nombreCursos.begin(); it != nombreCursos.end(); it++){
                    imprimir(*it);
                }
                imprimir("Seleccionar curso:");
                string cursoSeleccionado = entradaString();
                list<string> infoCurso = contCurso.verCurso(cursoSeleccionado);

                for (auto iterador = infoCurso.begin(); iterador != infoCurso.end(); iterador++){
                    imprimir(*iterador);
                }
                presionaParaContinuar();
                break;
            }
            case 11:{
                //Inscribir estudiante a curso
                system("clear");
                imprimir("Ingrese nickname de estudiante:");
                string nick = entradaString();
                if(!contUsuario.existeUsuario(nick)){
                    imprimir("El usuario " + nick + " no existe", ROJO);
                    presionaParaContinuar();
                    break;
                }
                try{
                    if(contUsuario.getTipoUsuario(nick)=="estudiante"){
                        contUsuario.seleccionarUsuario(nick);
                        list<tuple<string, int, int>> cursosDisp = contCurso.cursosDisponibles(nick);
                        if(cursosDisp.empty()){
                            imprimir("No existen cursos a los que " + nick + " pueda inscribirse.", AMARILLO);
                            presionaParaContinuar();
                            break;
                        }else{
                            imprimir("Cursos disponibles para " + nick + ":");
                            for (auto it = cursosDisp.begin(); it != cursosDisp.end(); ++it) {
                                imprimir(get<0>(*it) + ", Cantidad de lecciones: " + to_string(get<1>(*it)) + ", Cantidad de ejercicios: " + to_string(get<2>(*it)));
                            }
                            imprimir("Ingrese nombre de curso a inscribirse:");
                            string nombreCurso = entradaString();
                            try{
                                contCurso.inscribirEstudianteACurso(nombreCurso, nick, 21, 6,2023);
                                imprimir("Estudiante inscripto", VERDE);
                            }catch(invalid_argument& e){
                                imprimir("Error al inscribir estudiante:", ROJO);
                                imprimir(e.what(), ROJO);
                            }
                                presionaParaContinuar();
                        }
                    }else{
                        imprimir("El usuario " + nick + " no es un estudiante, por lo cual no puede inscribirse a ningun curso", AMARILLO);
                        presionaParaContinuar();
                    }
                }catch(invalid_argument& e){
                    imprimir("El usuario " + nick + " no existe", ROJO);
                    presionaParaContinuar();
                }
                
                break;
            }
            case 12:{
                //Realizar Ejercicio
                system("clear");
                imprimir("Ingrese nick de estudiante: ");
                string nick = entradaString();
                if(!contUsuario.existeUsuario(nick)){
                    imprimir("El usuario " + nick + " no existe", ROJO);
                    presionaParaContinuar();
                    break;
                }
                imprimir("Cursos:" , AMARILLO);
                set<string> cursosISA = contCurso.cursosInscriptoSinAprobar(nick);
                if(cursosISA.empty()){
                    imprimir("No hay ejercicios para realizar", AMARILLO);
                    presionaParaContinuar();
                    break;
                }
                auto it = cursosISA.begin();
                for(it; it != cursosISA.end(); it++){
                    string curso = (*it);
                    imprimir(curso);
                }
                imprimir("Ingrese curso:");
                string curso = entradaString();
                list<DTEjercicio> ejerciciosSinHacer = contCurso.seleccionarEjerciciosDeCurso(curso);
                if(ejerciciosSinHacer.empty()){
                    imprimir("No hay ejercicios para realizar", AMARILLO);
                    presionaParaContinuar();
                    break;
                }
                auto it2 = ejerciciosSinHacer.begin();
                for(it2; it2!=ejerciciosSinHacer.end(); it2++){
                    DTEjercicio ejercicio = (*it2);
                    imprimir(to_string(ejercicio.getIdEjercicio()));
                }
                imprimir("Ingrese ID del ejercicio: ");
                int id = entradaInt();
                Ejercicio* ejer = contCurso.getEjercicioPorIdDesdeMapa(id);
                contCurso.setEjercicioEnMemoria(ejer);
                string ej = ejer->mostrarEjercicio();
                imprimir(ej);
                string estudiante = nick;
                if(contCurso.getTipoEjercicio(id) == "completar"){
                    imprimir("Ingrese las palabras que faltan separado por coma");
                    string palabra = entradaString();
                    list<string> solucion = separarString(palabra,',');
                    if(contCurso.solucionCorrectaCompletarPalabras(solucion,estudiante,id)){
                        imprimir("Respuesta correcta", VERDE);
                    }else{
                        imprimir("Respuesta incorrecta", AMARILLO);
                    }
                    presionaParaContinuar();
                }
                else{
                    string solTraduccion;
                    imprimir("Ingrese la traduccion correcta");
                    solTraduccion = entradaString();
                    if(contCurso.solucionCorrectaTraduccion(solTraduccion,estudiante,id)){
                        imprimir("Respuesta correcta", VERDE);
                    }else{
                        imprimir("Respuesta incorrecta", AMARILLO);
                    }
                    presionaParaContinuar();
                }
            break;
            }
            case 13:{
                //Consultar estadisticas
                system("clear");
                imprimir("Ingrese una opcion de estadisticas:");
                imprimir("1. De estudiantes");
                imprimir("2. De profesores");
                imprimir("3. De cursos");
                int entrada = entradaInt();

                if (entrada == 1){
                    imprimir("ingrese el nick del estudiante");
                    list<DTEstudianteSC> estudiantes = contUsuario.listarEstudiantes();
                    for ( DTEstudianteSC& estudiante : estudiantes) {
                        imprimir( estudiante.getNickname());
                    }
                    string estu = entradaString();
                    DTEstadisticaEstudiante estadisticas = contUsuario.estadisticasEstudiante(estu);

                    imprimir("Estadisticas de "+ estu + ":" );
                    map<string, int> porcentajesCursos = estadisticas.getPorcentajesCursos();
                    for (const auto& estads : porcentajesCursos) {
                        imprimir("Curso: " + estads.first + ", Porcentaje: " + to_string(estads.second) + "%");
                    }
                }else if (entrada == 2) {
                    imprimir("Ingrese el nick del profesor");
                    list<string> profesores = contUsuario.listarProfe();
                    for (const string& profesor : profesores) {
                        imprimir(profesor);
                    }
                    string prof = entradaString();
                    DTEstadisticaProfesor estadisticas = contUsuario.estadisticasProfesor(prof);
                    imprimir("Estadisticas de "+ prof + ":" );
                    map<string, int> porcentajesCursos = estadisticas.getPromPorcetajesCursos();
                    for (auto it = porcentajesCursos.begin(); it != porcentajesCursos.end(); it++) {
                        int porcentaje = it->second;
                        string nom = it->first;
                        imprimir("Curso: " + nom + ", Porcentaje: " + to_string(porcentaje) + "%");
                    }
                } else {
                    imprimir("Ingrese el nombre del curso");
                    set<string> cursos = contCurso.listarNombresDeCursos();
                    for (const string& curso : cursos){
                        imprimir(curso);
                    }
                    string cur = entradaString();

                    DTEstadisticaCurso estadisticas = contCurso.estadisticasCurso(cur);
                    imprimir("Estadisticas de "+ cur + ":" );
                    int porcentaje = estadisticas.getpromedioCurso();
                    imprimir("Porcentaje:" + to_string(porcentaje) + "%");


                }
                presionaParaContinuar();
                break;
            }
            case 14:{
                //Suscribirse a notificaciones
                system("clear");
                list<string> listaU = contUsuario.listarUsuarios();
                int a=1;
                for(auto it = listaU.begin(); it != listaU.end(); ++it){
                    imprimir(to_string(a) +" "+ *it);
                    a++;
                }
                imprimir("Escriba el nickname del usuario que desea suscribirse:");
                string nick = entradaString();
                set<string> subs = contCurso.consultarSuscripciones(nick);
                int b=1;
                for(auto it = subs.begin(); it != subs.end(); ++it){
                    imprimir(to_string(b) +" "+ *it);
                    b++;
                }
                set<string> idiomas;
                imprimir("Escriba el nombre del idioma al que desea suscribirse:");
                string idioma = entradaString();
                idiomas.insert(idioma);
                while(quiereContinuar("agregar otro idioma")){
                    imprimir("Ingresar otro idioma:");
                    string idioma = entradaString();
                    idiomas.insert(idioma);
                }
                contCurso.suscribirUsuario(idiomas,nick);
                imprimir("Usuario suscrito", VERDE);
                presionaParaContinuar();
                break;
            }
            case 15:{
                //Consulta de notificaciones
                system("clear");
                imprimir("Ingrese nick de usuario:");
                string nick = entradaString();
                if(!contUsuario.existeUsuario(nick)){
                    imprimir("El usuario no existe", ROJO);
                    presionaParaContinuar();
                    break;
                }
                else{
                list<DTNotificacion> notis = contUsuario.consultarNotificaciones(nick);
                if(notis.size() == 0){
                    imprimir("No hay notificaciones", ROJO);
                    presionaParaContinuar();
                    break;
                }
                for(auto it = notis.begin(); it != notis.end(); ++it){
                    DTNotificacion noti = *it;
                    imprimir(noti.getCurso());
                    imprimir(noti.getIdioma()->getNombreIdioma());
                }
                presionaParaContinuar();
                }
                contUsuario.eliminarNotificaciones(nick);
                break;
            }
            case 16:{
                //Eliminar suscripciones
                system("clear");
                list<string> nicksUsuarios = contCurso.listarNicks();
                for (auto it = nicksUsuarios.begin(); it != nicksUsuarios.end(); it++){
                    imprimir(*it);
                }
                imprimir("Ingrese el nick del usuario que desea eliminar una/s suscripcion/es: ");
                string nick = entradaString();
                contCurso.setNickUsuario(nick);

                list<string> idiomasSuscrito = contCurso.listarIdiomasSuscrito(nick);
                if (idiomasSuscrito.size() == 0){
                    imprimir("El usuario no esta suscrito a ningun idioma", ROJO);
                    presionaParaContinuar();
                    break;
                }
                for (auto iterador = idiomasSuscrito.begin(); iterador != idiomasSuscrito.end(); iterador++){
                    imprimir(*iterador);
                }
                imprimir("Ingrese el nombre del idioma al cual desea eliminar su suscripcion: ");
                set<string> suscAEliminar;
                suscAEliminar.insert(entradaString());
                while (quiereContinuar("Eliminar otra suscripcion")){
                    imprimir("Ingrese otro idioma:");
                    suscAEliminar.insert(entradaString());
                }

                contCurso.eliminarSuscripciones(suscAEliminar);
                imprimir("Suscripciones eliminadas", VERDE);
                presionaParaContinuar();

                    
                break;
            }
            case 17:{
                if(!seAgregaronLosDatos){
                    system("clear");
                    ingresarIdiomas();
                    imprimir("Datos de prueba agregados (idiomas).", VERDE);
                    ingresarUsuarios();
                    imprimir("Datos de prueba agregados (usuarios).", VERDE);
                    ingresarCursos();
                    imprimir("Datos de prueba agregados (cursos).", VERDE);
                    ingresarLecciones();
                    imprimir("Datos de prueba agregados (lecciones y ejercicios)", VERDE);
                    ingresarPrevias();
                    imprimir("Datos de prueba agregados (previas)", VERDE);
                    ingresarHabilitarCursos();
                    imprimir("Datos de prueba agregados (cursos habilitados)", VERDE);
                    inscribirUsuarios();
                    imprimir("Datos de prueba agregados (usuarios inscritos y ejercicios completados de cada usuario)", VERDE);
                    seAgregaronLosDatos = true;
                }else{
                    imprimir("Los datos ya fueron agregados", AMARILLO);
                }
                presionaParaContinuar();
                break;
            }
            default:{
                imprimir("Opcion invalida", AMARILLO);
                presionaParaContinuar();
                break;
            }
        }
        contCurso.limpiarDatos();
    }

    return 0;
}
int seleccionEstudianteOProfesor(){
    imprimir("1. Ingresar Estudiante");
    imprimir("2. Ingresar Profesor");
    int opcion = entradaInt();
    return opcion;
};

int seleccionTipoEjercicio(){
    imprimir("1. Ingresar ejercicio de traduccion");
    imprimir("2. Ingresar ejercicio de rellenar palabras");
    return entradaInt();
}

DTEstudiante crearDTEstudiante() {
    factoryController& fabrica = factoryController::getInstancia();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();

    imprimir("Ingrese nickname de estudiante:");
    string nick = entradaString();

    while (contUsuario.existeUsuario(nick)) {
        imprimir("El nickname ya está en uso, ingrese otro:", AMARILLO);
        nick = entradaString();
    }

    imprimir("Ingrese nombre de estudiante:");
    string nombre = entradaString();
    imprimir("Ingrese contrasenia de estudiante:");
    string contrasenia = entradaString();
    imprimir("Ingrese descripcion de estudiante:");
    string descripcion = entradaString();
    imprimir("Ingrese pais de estudiante:");
    string pais = entradaString();
    imprimir("Ingrese dia de nacimiento de estudiante:");
    int dia = entradaInt();
    imprimir("Ingrese mes de nacimiento de estudiante:");
    int mes = entradaInt();
    imprimir("Ingrese anio de nacimiento de estudiante:");
    int anio = entradaInt();
    DTFecha fecha = DTFecha(dia, mes, anio);
    DTEstudiante est = DTEstudiante(nick, contrasenia, nombre, descripcion, pais, fecha);
    return est;
}

DTProfesor crearDTProfesor(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();

    imprimir("Ingrese nickname de profesor:");
    string nick = entradaString();

    while (contUsuario.existeUsuario(nick)) {
        imprimir("El nickname ya está en uso, ingrese otro:", AMARILLO);
        nick = entradaString();
    }

    imprimir("Ingrese nombre de profesor:");
    string nombre = entradaString();
    imprimir("Ingrese contrasenia de profesor:");
    string contrasenia = entradaString();
    imprimir("Ingrese descripcion de profesor:");
    string descripcion = entradaString();
    imprimir("Ingrese instituto de profesor:");
    string instituto = entradaString();
    bool seguir = true;
    imprimir("Idiomas disponibles:");
    list<string> listita = contCurso.listarIdiomas();
    for(auto it = listita.begin(); it != listita.end(); ++it){
        imprimir(*it);
    }
    imprimir("Ingrese un idioma en el que se especializa:");
    string idiom = entradaString();
    set<string> setIdi;
    setIdi.insert(idiom);
    imprimir("Desea agregar mas idiomas?(S/N)");
    string masIdiomas = entradaString();
    while (masIdiomas == "S" || masIdiomas == "s") {
        imprimir("Ingrese otro idioma:");
        idiom = entradaString();
        setIdi.insert(idiom);
        imprimir("Quiere agregar mas idiomas?(S/N)");
        masIdiomas = entradaString();
    }

    DTProfesor prof = DTProfesor(nick, contrasenia, nombre, descripcion, instituto, setIdi);
    return prof;
}

DTCurso crearDTCurso(){
        factoryController& fabrica = factoryController::getInstancia();
        IControladorCurso& contCurso = fabrica.getIControladorCurso();
        imprimir("Ingrese nombre del curso:");
        string nombre = entradaString();

        imprimir("Ingrese descripcion del curso:");
        string descripcion = entradaString();

        imprimir("Elija nivel de dificultad del curso:");
        imprimir("1 = Principiante");
        imprimir("2 = Medio");
        imprimir("3 = Avanzado");
        int dificultadEntrada = entradaInt();
        nivelDeDificultad dificultad;
        switch(dificultadEntrada){
            case 1:
                dificultad = PRINCIPIANTE;
                break;
            case 2:
                dificultad = MEDIO;
                break;
            case 3:
                dificultad = AVANZADO;
                break;
            default:
                imprimir("Opcion invalida", AMARILLO);
                presionaParaContinuar();
                break;
        }
        imprimir("Quiere agregar previas al curso? (S/N)");
        string tienePrevias = entradaString();
        set<string>* previas = new set<string>();
        if(tienePrevias == "S" || tienePrevias == "s"){
            set<string> curs = contCurso.listarNombresDeCursos();
            int i = 1;
            for(auto it = curs.begin(); it != curs.end(); ++it){
                imprimir(to_string(i) +" "+ *it);
                i++;
            }
            bool seguir = true;
            while(seguir){
                imprimir("Ingrese nombre de previas del curso:");
                string pre = entradaString();
                map<string, Curso*> p = contCurso.getCursos();
                auto it = p.find(pre);
                if (it != p.end()) {
                    previas->insert(pre);
                } else {
                    imprimir("Curso no encontrado", ROJO);
                }
                seguir = quiereContinuar("Agregar otra previa");
            }
        }
        DTCurso c = DTCurso(nombre,false,dificultad,descripcion, *previas);
        return c;
    }    

DTLeccion crearDTLeccion(int &numLec){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    imprimir("Ingrese el tema de la Leccion:");
    string tema = entradaString();
    imprimir("Ingrese el objetivo de la Leccion:");
    string objetivo = entradaString();
    imprimir("Ingrese la cantidad de ejercicios que desea agregar:");
    int cantEjs = entradaInt();
    numLec++;
    DTLeccion lec = DTLeccion(numLec, cantEjs, objetivo, tema);
    return lec;
}

DTLeccion crearDTLeccion2(int &numLec){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    imprimir("Ingrese el tema de la Leccion:");
    string tema = entradaString();
    imprimir("Ingrese el objetivo de la Leccion:");
    string objetivo = entradaString();
    numLec++;
    DTLeccion lec = DTLeccion(numLec, 0, objetivo, tema);
    return lec;
}
list<string> separarString(const string& str, char delimiter) {
    list<string> palabras;
    stringstream ss(str);
    string unionDePal;

    while (getline(ss, unionDePal, delimiter)) {
        palabras.push_back(unionDePal);
    }

    return palabras;
}
DTRellenarPalabras crearDTRellenarPalabras(int numLec){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    
    imprimir("Ingrese la descripción ", AMARILLO);
    string descripcion = entradaString();            
    string tipo = "completar";   
    imprimir("Ingrese la frase (utilice --- para los espacios a completar)", AMARILLO);
    string frase = entradaString();                            
    imprimir("Ingrese las soluciones separadas por comas", AMARILLO);
    string solSinSep = entradaString();
    list<string> soluciones = separarString(solSinSep, ',');   
    int id = contCurso.getIdEjercicio() +1;
    contCurso.setIdEjercicio(id);
    DTRellenarPalabras ejer =  DTRellenarPalabras(descripcion, frase, id, soluciones,tipo,numLec);
    return ejer;
}

DTTraduccion crearDTTraduccion(int numLec){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    
    imprimir("Ingrese la descripción ", AMARILLO);
    string descripcion = entradaString();            
    string tipo = "traduccion";                             
    imprimir("Ingrese la frase", AMARILLO);
    string fraseATraducir = entradaString();
    imprimir("Ingrese la traducción", AMARILLO);
    string traduccion = entradaString();
    int id = contCurso.getIdEjercicio() +1;
    contCurso.setIdEjercicio(id);
    DTTraduccion ejer = DTTraduccion(descripcion, fraseATraducir, id, traduccion,tipo,numLec);
    return ejer;
}

bool quiereContinuar(string p){
    imprimir("1: " + p);
    imprimir("2: Continuar");
    int seguir = entradaInt();
    if (seguir == 1){
        return true;
    }
    else return false;
}


void presionaParaContinuar(){
    cout << "Presiona enter para continuar...";
    cin.ignore();
    cin.get();
    cout << endl;
}

void limpiarLog(){
    ofstream log("log.txt");
    if (log.is_open()){
        log << "";
        log.close();
    }else{
        imprimir("Error: No se pudo abrir log.txt", ROJO);
        presionaParaContinuar();
    }
}

void escribirEnLog(string linea){
    ofstream log("log.txt", ofstream::app);
    if (log.is_open()){
        if(linea[0] == 'U')//si es entrada del usuario, dejar linea arriba libre
            log << endl;
        log << linea;
        log << endl;
        if(linea[0] == 'U')//si es entrada del usuario, dejar linea abajo libre
            log << endl;
        log.close();
    }else{
        imprimir("Error: No se pudo abrir log.txt", ROJO);
        presionaParaContinuar();
    }
}

void imprimir(string texto){
    cout << texto << endl;
    escribirEnLog("S: " + texto);
}

void imprimir(string texto, string color){
    cout << color << texto << RESET << endl;
    escribirEnLog("S: " + texto);
}

//verificar que entrada sea un int
int entradaInt(){
    int entrada = -1;
    while(entrada < 0){
        try{
            string entradita;
            cout << AZUL;
            cin >> entradita;
            cout << RESET;
            entrada = stoi(entradita);
        }catch(...){
            cout << AMARILLO << "La entrada debe ser un entero positivo." << endl << RESET;
            cout << "Ingrese un entero positivo: " << endl;
        }
    }
    escribirEnLog("U: " + to_string(entrada));
    return entrada;
}
string entradaString(){
    bool alfanumerico = false;
    string entrada;
    cout << AZUL;
    getline(cin >> ws, entrada);
    cout << RESET;
    while(entrada == ""){
        cout << AMARILLO << "La entrada no puede ser vacia." << RESET << endl;
        cout << "Ingrese nuevamente:" << endl;
        getline(cin >> ws, entrada);
    }
    escribirEnLog("U: " + entrada);
    return entrada;
}

//DATOS PRUEBA

void ingresarIdiomas(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    contCurso.limpiarDatos();
    contCurso.confirmarAltaIdioma("Ingles");
    contCurso.limpiarDatos();
    contCurso.confirmarAltaIdioma("Aleman");
    contCurso.limpiarDatos();
    contCurso.confirmarAltaIdioma("Portugues");
    contCurso.limpiarDatos();
}

void ingresarUsuarios(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();
    
    //ESTUDIANTES
    contUsuario.setDatoEstudiante(DTEstudiante("jpidiom","asdfg123","Juan Perez","Soy un apasionado del aprendizaje de idiomas","Argentina",DTFecha(15,7,1995)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("marsilva","qwer456","Maria Silva","Como amante de los idiomas disfruto explorando nuevas formas de interactuar","Ecuador",DTFecha(28,2,1998)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("pero12","789werty","Pedro Rodriguez","Soy un entusiasta del aprendizaje de idiomas","Peru",DTFecha(10,11,1994)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("laugu","c1v2b3m4","Laura Gutierrez","Estoy fascinada por la forma en que las palabras pueden unir a las personas","Chile",DTFecha(22,4,1997)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("carlo22","tyuipz147","Carlos Lopez","Emocionado por adquirir fluidez en diferentes lenguas","Uruguay",DTFecha(3,9,1996)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("anator","1qsxc36","Ana Torres","Disfruto de la belleza de las diferentes estructuras y sonidos","Argentina",DTFecha(12,1,1999)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("luher24","t7h8y5u6","Lucia Hernandez","Emocionada en la riqueza cultural que cada idioma ofrece","Colombia",DTFecha(25,6,1993)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("dagon","1w2e3r4t5","David Gonzalez","Aprender nuevas lenguas y sumergirme en diferentes culturas","Uruguay",DTFecha(8,12,1997)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("carmor","6yu7i8m9","Carmen Morales","El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas","Chile",DTFecha(17,3,1995)));
    contUsuario.confirmarAltaUsuario();

    contUsuario.setDatoEstudiante(DTEstudiante("jose24","qwj789p","Jose Fernandez","Disfruto del proceso de descubrir nuevas formas de comunicarme","Bolivia",DTFecha(2,8,1998)));
    contUsuario.confirmarAltaUsuario();

    //PROFESORES
    set<string> i1; i1.insert("Ingles"); i1.insert("Portugues");
    contUsuario.setDatoProfesor(DTProfesor("langMaster","P4s512","Marta Grecia", "Soy una profesora apasionada por los idiomas","Instituto de Idiomas Moderno", i1));
    contUsuario.confirmarAltaUsuario();

    set<string> i2; i2.insert("Ingles"); i2.insert("Portugues"); i2.insert("Aleman");
    contUsuario.setDatoProfesor(DTProfesor("linguaPro","Pess23","Carlos Petro","Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas","Centro Global", i2));
    contUsuario.confirmarAltaUsuario();

    set<string> i3; i3.insert("Ingles"); i3.insert("Aleman");
    contUsuario.setDatoProfesor(DTProfesor("talkExpert","Secret1","Laura Perez","Soy una profesora entusiasta del aprendizaje de idiomas","Instituto de Idiomas Vanguardia", i3));
    contUsuario.confirmarAltaUsuario();

    set<string> i4; i4.insert("Portugues");
    contUsuario.setDatoProfesor(DTProfesor("lingoSensei","Secure2","Franco Lopez","Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos","Centro de Idiomas", i4));
    contUsuario.confirmarAltaUsuario();

    set<string> i5; i5.insert("Ingles");
    contUsuario.setDatoProfesor(DTProfesor("wordMaestro","Passw0","Ana Morales","Soy una profesora comprometida en desarrollo de habilidades idiomaticas","Instituto de Idiomas Progreso", i5));
    contUsuario.confirmarAltaUsuario();
    }

void ingresarCursos(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    contCurso.limpiarDatos();
    // Curso 1: Ingles para principiantes
    contCurso.seleccionarProfesor("langMaster");
    contCurso.seleccionIdioma("Ingles");
    set<string> previas1;
    DTCurso c1 = DTCurso("Ingles para principiantes", true, PRINCIPIANTE, "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", previas1);
    contCurso.setDatoDeCurso(c1);
    contCurso.altaCurso();
contCurso.limpiarDatos();
    // Curso 2: Curso de ingles basico
    contCurso.seleccionarProfesor("langMaster");
    contCurso.seleccionIdioma("Ingles");
    set<string> previas2;
    DTCurso c2 = DTCurso("Curso de ingles basico", false, PRINCIPIANTE, "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", previas2);
    contCurso.setDatoDeCurso(c2);
    contCurso.altaCurso();
contCurso.limpiarDatos();
    // Curso 3: Ingles intermedio: mejora tu nivel
    contCurso.seleccionarProfesor("linguaPro");
    contCurso.seleccionIdioma("Ingles");
    set<string> previas3;   
    DTCurso c3 = DTCurso("Ingles intermedio: mejora tu nivel", true, MEDIO, "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", previas3);
    contCurso.setDatoDeCurso(c3);
    contCurso.altaCurso();
contCurso.limpiarDatos();
    // Curso 4: Curso avanzado de ingles
    contCurso.seleccionarProfesor("linguaPro");
    contCurso.seleccionIdioma("Ingles");
    set<string> previas4;
    DTCurso c4 = DTCurso("Curso avanzado de ingles", true, AVANZADO, "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", previas4);
    contCurso.setDatoDeCurso(c4);
    contCurso.altaCurso();
contCurso.limpiarDatos();
    // Curso 5: Portugues intermedio
    contCurso.seleccionarProfesor("linguaPro");
    contCurso.seleccionIdioma("Portugues");
    set<string> previas5;
    DTCurso c5 = DTCurso("Portugues intermedio", true, MEDIO, "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", previas5);
    contCurso.setDatoDeCurso(c5);
    contCurso.altaCurso();
contCurso.limpiarDatos();
    // Curso 6: Portugues avanzado
    contCurso.seleccionarProfesor("lingoSensei");
    contCurso.seleccionIdioma("Portugues");
    set<string> previas6;
    DTCurso c6 = DTCurso("Portugues avanzado", false, AVANZADO, "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", previas6);
    contCurso.setDatoDeCurso(c6);
    contCurso.altaCurso();
    contCurso.limpiarDatos();
}

void inscribirUsuarios(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();
    contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("jpidiom");
    contCurso.inscribirEstudianteACurso("Ingles para principiantes","jpidiom",1,1,2022);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("jpidiom");
    contCurso.inscribirEstudianteACurso("Ingles intermedio: mejora tu nivel","jpidiom",12,6,2022);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("jpidiom");
    contCurso.inscribirEstudianteACurso("Curso avanzado de ingles","jpidiom",2,3,2023);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("marsilva");
    contCurso.inscribirEstudianteACurso("Ingles para principiantes","marsilva",2,1,2022);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("pero12");
    contCurso.inscribirEstudianteACurso("Ingles para principiantes","pero12",2,1,2022);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("laugu");
    contCurso.inscribirEstudianteACurso("Ingles para principiantes","laugu",3,1,2023);
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("laugu");
    contCurso.inscribirEstudianteACurso("Portugues intermedio","laugu",3,1,2023);  
contCurso.limpiarDatos();
    contUsuario.seleccionarUsuario("carlo22");
    contCurso.inscribirEstudianteACurso("Portugues intermedio","carlo22",5,1,2023);          
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("jpidiom");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer = contCurso.getEjercicioPorIdDesdeMapa(1);
    contCurso.setEjercicioEnMemoria(ejer);
    contCurso.solucionCorrectaTraduccion("Nice to meet you","jpidiom",1);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("jpidiom");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer1 = contCurso.getEjercicioPorIdDesdeMapa(2);
    contCurso.setEjercicioEnMemoria(ejer1);
    contCurso.solucionCorrectaCompletarPalabras({"allow", "myself"},"jpidiom",2);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("jpidiom");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer2 = contCurso.getEjercicioPorIdDesdeMapa(3);
    contCurso.setEjercicioEnMemoria(ejer2);
    contCurso.solucionCorrectaTraduccion("Tengo dos hermanos y tres hermanas","jpidiom",3);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("jpidiom");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer3 = contCurso.getEjercicioPorIdDesdeMapa(4);
    contCurso.setEjercicioEnMemoria(ejer3);
    contCurso.solucionCorrectaCompletarPalabras({"some"},"jpidiom",4);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("jpidiom");
    contCurso.seleccionarEjerciciosDeCurso("Ingles intermedio: mejora tu nivel");
    Ejercicio* ejer4 = contCurso.getEjercicioPorIdDesdeMapa(6);
    contCurso.setEjercicioEnMemoria(ejer4);
    contCurso.solucionCorrectaCompletarPalabras({"have", "past"},"jpidiom",6);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("marsilva");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer5 = contCurso.getEjercicioPorIdDesdeMapa(1);
    contCurso.setEjercicioEnMemoria(ejer5);
    contCurso.solucionCorrectaTraduccion("Nice to meet you","marsilva",1);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("marsilva");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer6 = contCurso.getEjercicioPorIdDesdeMapa(2);
    contCurso.setEjercicioEnMemoria(ejer6);
    contCurso.solucionCorrectaCompletarPalabras({"allow", "myself"},"marsilva",2);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("pero12");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer7 = contCurso.getEjercicioPorIdDesdeMapa(1);
    contCurso.setEjercicioEnMemoria(ejer7);
    contCurso.solucionCorrectaTraduccion("Nice to meet you","pero12",1);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("pero12");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer8 = contCurso.getEjercicioPorIdDesdeMapa(2);
    contCurso.setEjercicioEnMemoria(ejer8);
    contCurso.solucionCorrectaCompletarPalabras({"allow", "myself"},"pero12",2);
contCurso.limpiarDatos();
    contCurso.cursosInscriptoSinAprobar("pero12");
    contCurso.seleccionarEjerciciosDeCurso("Ingles para principiantes");
    Ejercicio* ejer9 = contCurso.getEjercicioPorIdDesdeMapa(4);
    contCurso.setEjercicioEnMemoria(ejer9);
    contCurso.solucionCorrectaCompletarPalabras({"some"},"pero12",4);       contCurso.limpiarDatos();                         
}

void ingresarLecciones(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    /*
    Ref;Nombre;Descripcion;Dificultad;Profesor;Idioma;Habilitado
    C1;Ingles para principiantes;Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.;Principiante;U11;I1;Si
    C2;Curso de ingles basico;Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.;Principiante;U11;I1;No
    C3;Ingles intermedio: mejora tu nivel;Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.;Medio;U12;I1;Si
    C4;Curso avanzado de ingles;Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.;Avanzado;U12;I1;Si
    C5;Portugues intermedio;Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.;Medio;U12;I3;Si
    C6;Portugues avanzado;Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.;Avanzado;U14;I3;No

    Ref; Curso; Tema; Objetivo
    L1;C1;Saludos y Presentaciones; Aprender a saludar y despedirse
    L2;C1;Artículos y Plurales; Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos
    L3;C2;Actividades Cotidianas; Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos
    L4;C2;Presente Simple; Aprender el uso del presente simple
    L5;C3;Conversaciones cotidianas;Aprender a hacer preguntas y respuestas en situaciones comunes
    L6;C4;Uso de modales avanzados;Explorar el uso de los modales complejos
    L7;C5;Lectura y comprension de textos; Analizar el contenido, vocabulario y estructuras gramaticales utilizadas
    
    Ref; Leccion; Tipo; Descripcion; Problema; Solucion
    E1;L1;T;Presentaciones;Mucho gusto en conocerte;Nice to meet you
    E2;L1;R;Presentaciones formales;Please --- me to introduce ---;allow, myself
    E3;L2;T;Plurales regulares;I have two brothers and three sisters;Tengo dos hermanos y tres hermanas
    E4;L2;R;Sustantivos contables en plural;Can I have --- water, please?;some
    E5;L3;R;Actividades diarias;Wake ---;up
    E6;L5;R;Consultas de la hora;Q: Do you --- the time?, A: Yes, it is half --- 4;have, past
    E7;L6;T;Dar consejos o expresar obligacion; You should visit that museum;Deberias visitar ese museo
    E8;L7;T;Imperativo;Fale comigo;Habla conmigo
    
    
    */
    contCurso.limpiarDatos();
    //L1
    DTLeccion leccion = DTLeccion(1, 2, "Aprender a saludar y despedirse", "Saludos y Presentaciones");
    contCurso.setDatoDeLeccion(leccion);
    DTTraduccion tradu = DTTraduccion("Presentaciones", "Mucho gusto en conocerte", 1, "Nice to meet you", "traduccion", 1);
    contCurso.agregarDatosTraduccion(tradu);
    DTRellenarPalabras rellpab = DTRellenarPalabras("Presentaciones formales", "Please --- me to introduce ---", 2, {"allow", "myself"}, "completar", 1);
    contCurso.agregarDatosRellenarPalabras(rellpab);
    contCurso.altaLeccion("Ingles para principiantes");
contCurso.limpiarDatos();
    //L2
    leccion = DTLeccion(2, 2, "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", "Artículos y Plurales");
    contCurso.setDatoDeLeccion(leccion);
    tradu = DTTraduccion("Plurales regulares", "I have two brothers and three sisters", 3, "Tengo dos hermanos y tres hermanas", "traduccion", 2);
    contCurso.agregarDatosTraduccion(tradu);
    rellpab = DTRellenarPalabras("Sustantivos contables en plural", "Can I have --- water, please?", 4, {"some"}, "completar", 2);
    contCurso.agregarDatosRellenarPalabras(rellpab);
    contCurso.altaLeccion("Ingles para principiantes");
contCurso.limpiarDatos();
    //L3
    leccion = DTLeccion(1, 1, "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos", "Actividades Cotidianas");
    contCurso.setDatoDeLeccion(leccion);
    rellpab = DTRellenarPalabras("Actividades diarias", "Wake ---", 5, {"up"}, "completar", 1);
    contCurso.agregarDatosRellenarPalabras(rellpab);
    contCurso.altaLeccion("Curso de ingles basico");
contCurso.limpiarDatos();
    //L4
    leccion = DTLeccion(2, 0, "Aprender el uso del presente simple", "Presente Simple");
    contCurso.setDatoDeLeccion(leccion);
    contCurso.altaLeccion("Curso de ingles basico");
contCurso.limpiarDatos();
    //L5
    leccion = DTLeccion(1, 1, "Aprender a hacer preguntas y respuestas en situaciones comunes", "Conversaciones cotidianas");
    contCurso.setDatoDeLeccion(leccion);
    rellpab = DTRellenarPalabras("Consultas de la hora", "Q: Do you --- the time?, A: Yes, it is half --- 4", 6, {"have", "past"}, "completar", 1);
    contCurso.agregarDatosRellenarPalabras(rellpab);
    contCurso.altaLeccion("Ingles intermedio: mejora tu nivel");
contCurso.limpiarDatos();
    //L6
    leccion = DTLeccion(1, 1, "Explorar el uso de los modales complejos", "Uso de modales avanzados");
    contCurso.setDatoDeLeccion(leccion);
    tradu = DTTraduccion("Dar consejos o expresar obligacion", "You should visit that museum", 7, "Deberias visitar ese museo", "traduccion", 1);
    contCurso.agregarDatosTraduccion(tradu);
    contCurso.altaLeccion("Curso avanzado de ingles");
contCurso.limpiarDatos();
    //L7
    leccion = DTLeccion(1, 1, "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas", "Lectura y comprension de textos");
    contCurso.setDatoDeLeccion(leccion);
    tradu = DTTraduccion("Imperativo", "Fale comigo", 8, "Habla conmigo", "traduccion", 1);
    contCurso.agregarDatosTraduccion(tradu);
    contCurso.altaLeccion("Portugues intermedio");
    contCurso.limpiarDatos();


    contCurso.setIdEjercicio(8);

    /*Origen;Previa
    C3;C1
    C4;C1
    C4;C3
    C6;C5*/
}

void ingresarHabilitarCursos(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();

    contCurso.habilitarCurso("Ingles para principiantes");
    contCurso.habilitarCurso("Ingles intermedio: mejora tu nivel");
    contCurso.habilitarCurso("Curso avanzado de ingles");
    contCurso.habilitarCurso("Portugues intermedio");
}
void ingresarPrevias(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    /*
    C1;Ingles para principiantes
    C2;Curso de ingles basico
    C3;Ingles intermedio: mejora tu nivel
    C4;Curso avanzado de ingles
    C5;Portugues intermedio
    C6;Portugues avanzado
    Origen;Previa
    C3;C1
    C4;C1
    C4;C3
    C6;C5*/

    contCurso.agregarPrevia("Ingles intermedio: mejora tu nivel", "Ingles para principiantes");contCurso.limpiarDatos();
    contCurso.agregarPrevia("Curso avanzado de ingles", "Ingles para principiantes");contCurso.limpiarDatos();
    contCurso.agregarPrevia("Curso avanzado de ingles", "Ingles intermedio: mejora tu nivel");contCurso.limpiarDatos();
    contCurso.agregarPrevia("Portugues avanzado", "Portugues intermedio");contCurso.limpiarDatos();
    
}