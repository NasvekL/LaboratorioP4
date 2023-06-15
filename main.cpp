//hay que incluir la interfaz? o el controlador directo? en caso de que sea el controlador directo, la interfaz nunca se usa pa nada
//pq la interfaz es abstracta, eentonces nunca se llega a crear una instancia creo...
#include "include/Interfaces/IControladorCurso.h"
#include "include/Interfaces/IControladorUsuario.h"
#include "include/Controladores/ControladorCurso.h"
#include "include/Controladores/ControladorUsuario.h"
#include "include/FactoryController.h"
//#include "include/DTs/DTRellenarPalabras.h"
//#include "include/DTs/DTTraduccion.h"



// Macros para definir los códigos de escape ANSI para colores
#define RESET    "\033[0m"
#define ROJO     "\033[31m"
#define VERDE    "\033[32m"
#define AMARILLO "\033[33m"

int seleccionEstudianteOProfesor();
DTEstudiante crearDTEstudiante();
DTProfesor crearDTProfesor();
DTCurso crearDTCurso();
DTLeccion crearDTLeccion(int &numLec);
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
    imprimir("17. Agregar datos", VERDE);
    imprimir("Ingrese una opcion: ");
    int opcion = entradaInt();
    return opcion;
}
//HOLA


int main(){
    limpiarLog();
    //Tiene alguna clase de sentido la interfaz? En teoria es para que si el dia de mañana
    //se quiere agregar o cambiar el controlador, no haya que cambiar nada en el main
    //pero en el main se esta trabajando de forma directa con el controlador porque
    //la interfaz es abstracta, entonces no se puede crear una instancia de la interfaz
    //Ergo utilidadInterfaz = 0?
    //La gracia es que cambias el controlador y no la interfaz, no tiene que ver lo que toques en el main
    
    /*
                    ------PARA UTILIZAR DENTRO DE CADA CASO------
    factoryController& Fabrica = factoryController::getInstancia();
    IControladorCurso& ContCurso = Fabrica.getIControladorCurso();
    IControladorUsuario& ContUsuario = Fabrica.getIControladorUsuario();
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
                imprimir("chau bo");
                break;
            }
            case 1:{
                int seleccion = seleccionEstudianteOProfesor();
                switch (seleccion){
                    case 1:{
                        DTEstudiante est = crearDTEstudiante();
                        contUsuario.setDatoEstudiante(est);
                        contUsuario.confirmarAltaUsuario();
                        imprimir("Estudiante creado", VERDE); //no habria que hacer un if aca para ver si crearlo dependiendo si el nick ya existe? Si
                        presionaParaContinuar();
                        break;
                    }
                    case 2:{
                        DTProfesor prof = crearDTProfesor();
                        contUsuario.setDatoProfesor(prof);
                        contUsuario.confirmarAltaUsuario();
                        imprimir("Profesor creado", VERDE);
                        presionaParaContinuar();
                        // TO DO: realizar acciones para el profesor
                        break;
                    }
                }
                break;
            }

            case 2:{//Consulta de Usuario
                    list<string> listaUsuarios = contUsuario.consultarUsuario();
                    std::list<string>::iterator it;
                    for (it = listaUsuarios.begin(); it != listaUsuarios.end(); ++it) {
                        imprimir(*it);
                    }
                    cout << "Ingrese el nick deseado" << endl;
                    string nick;
                    nick = entradaString();
                    if(contUsuario.getTipoUsuario(nick)=="estudiante"){
                        contUsuario.seleccionarUsuario(nick);
                        DTEstudiante dte = contUsuario.getDatoEstudiante();
                        //imprimir("Nombre", AMARILLO);
                        imprimir("Nombre", AMARILLO + dte.getNombre());
                        //imprimir("Descripcion", AMARILLO);
                        imprimir("Descripcion", AMARILLO + dte.getDescripcion());
                        //imprimir("Pais", AMARILLO);
                        imprimir("Pais", AMARILLO + dte.getPais());
                        presionaParaContinuar();
                    } 
                    else{ 
                        contUsuario.seleccionarUsuario(nick);
                        DTProfesor dtp = contUsuario.getDatoProfesor();
                        //imprimir("Nombre", AMARILLO);
                        imprimir("Nombre", AMARILLO + dtp.getNombre());
                        //imprimir("Descripcion", AMARILLO);
                        imprimir("Descripcion", AMARILLO + dtp.getDescripcion());
                        //imprimir("Instituto", AMARILLO);
                        imprimir("Instituto", AMARILLO + dtp.getInstituto());
                        imprimir("Idiomas", AMARILLO);
                        set<string>* idi = dtp.getIdiomas();
                        set<string>::iterator it;
                        for (it = idi->begin(); it != idi->end(); ++it) {
                          imprimir(*it);
                        }
                        presionaParaContinuar();
                    }        
                    break;
            }
            case 3:{
                    //Alta idioma
                    imprimir("Ingrese idioma:", AMARILLO);
                    string idioma = entradaString();
                    if(contCurso.confirmarAltaIdioma(idioma)==false)
                        imprimir("Ya existe el idioma", ROJO);
                    else
                        imprimir("Idioma creado", VERDE);
                    presionaParaContinuar();
                    break;
            }
            case 4:{
                    //Consultar idiomas
                    contUsuario.listarIdiomas();
                    presionaParaContinuar();
                    break;
            }
            case 5:{
                    //Alta de curso:
                    //Elijo el profesor
                    list<string> profes = contCurso.listarProfe();
                    for (auto it = profes.begin(); it != profes.end(); ++it) {
                         imprimir(*it);
                    }
                    imprimir("Ingrese el nickname del profesor que dictara el curso:");
                    string nick = entradaString();
                    contCurso.seleccionarProfesor(nick);
                    //Defino el resto de datos del curso
                    DTCurso curso = crearDTCurso();
                    //Guardo el curso en un DT auxiliar en el controlador
                    contCurso.setDatosDeCurso(curso);

                    set<Idioma*> idiomass = contCurso.listarIdiomasProfesor();
                    for(auto it = idiomass.begin(); it != idiomass.end(); ++it){
                        imprimir((*it)->getNombreIdioma());
                    }
                    imprimir("Elija el idioma del curso: ");
                    string idioma = entradaString();
                    contCurso.seleccionIdioma(idioma);
                    imprimir("Agregar leccion S/N");
                    string opcion = entradaString();
                    int numLec = 0;
                    while(opcion == "S"){
                        DTLeccion leccion = crearDTLeccion(numLec);
                        contCurso.setDatosDeLeccion(leccion);
                        imprimir("Quiere agregar ejercicio S/N");
                        string opcion2 = entradaString();
                        while(opcion2=="S"){
                            imprimir("Ingrese tipo de ejercicio");
                            imprimir("Completar/Traduccion");
                            string opcion3 = entradaString();
                            if(opcion3=="Completar"){
                                DTRellenarPalabras ejercicio = crearDTRellenarPalabras(numLec);
                                contCurso.agregarDatosRellenarPalabras(ejercicio);
                            }
                            else{
                                DTTraduccion ejercicio = crearDTTraduccion(numLec);
                                contCurso.agregarDatosTraduccion(ejercicio);
                            }
                            if(!quiereContinuar("Agregar otro ejercicio"))
                                opcion2 = "N";
                        }
                        if(!quiereContinuar("Agregar otra leccion"))
                            opcion = "N";
                    }
                    contCurso.altaCurso();
                    break;
            }
            case 6:{
                //Agregar leccion
                imprimir("Cursos no habilitados disponibles:");;
                contCurso.listarCursosNoHabilitados(); 
                imprimir("Seleccionar Curso:");
                string cursoSeleccionado = entradaString();
                int numLec = contCurso.getNumeroDeLeccion(cursoSeleccionado);
                numLec++;
                DTLeccion leccion = crearDTLeccion(numLec);
                contCurso.setDatosDeLeccion(leccion);
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
                //interfazCurso->agregarEjercicio();
                imprimir ( "Cursos:", AMARILLO );
                contCurso.listarCursosNoHabilitados();
                
                imprimir("Elija un curso:", AMARILLO);
                string cursoSelec = entradaString();
                Curso cur = contCurso.getCurso(cursoSelec);

                imprimir("Lecciones del curso:", AMARILLO);
                list<Leccion*> lecciones = cur.getLecciones();

                if (!lecciones.empty()) {
                    int i = 1;
                    for (const auto& leccion : lecciones) {
                        imprimir(to_string(i) + ". " + leccion->getTema()); 
                        i++;
                    }

                    imprimir("Elija una lección:", AMARILLO);
                    int lecSelec = entradaInt();    
                    Leccion* leccionSeleccionada = nullptr; 
                    for (const auto& leccion : lecciones) {
                        if (leccion->getNumero() == lecSelec) {
                            leccionSeleccionada = leccion;
                            break;
                        }
                    }

                    if (leccionSeleccionada != nullptr) {
                        imprimir("Ingrese el tipo de ejercicio (completar o traduccion):, AMARILLO");
                        string tipo = entradaString();
                        if (tipo == "completar ") {
                            DTRellenarPalabras rell = crearDTRellenarPalabras();
                            contCurso.setDatosEjercicioCompletarPalabras(rell);
                        }else if (tipo == "traduccion") {                            
                            DTTraduccion tradu = crearDTTraduccion();
                            contCurso.setDatosEjercicioTraduccion(tradu);
                        } else {
                            imprimir("Tipo de ejercicio no válido", ROJO);
                        }
                        
                        contCurso.altaEjercicio(leccionSeleccionada);
                        imprimir("Ejercicio creado", VERDE);
                        presionaParaContinuar();
                    }

                }
*/
                break;
            }
            case 8:{
                contCurso.listarCursosNoHabilitados();
                string curso = entradaString();
                contCurso.habilitarCurso(curso);
                imprimir("Curso habilitado", VERDE);
                //Habilitar curso
                //interfazCurso->habilitarCurso();
                break;
            }
            case 9:{
                //Eliminar curso
               /* imprimir("Cursos disponibles:", AMARILLO);
                //contCurso.listarCursos();
                imprimir("Seleccione el curso que desea eliminar:");
                string cursoSeleccionado = entradaString();
*/

                //interfazCurso->eliminarCurso();
                break;
            }
            case 10:{
                //Consultar curso
                
                
                
                
                
                //interfazCurso->consultarCurso();

                /*factoryController& fabrica = factoryController::getInstancia();
                IControladorCurso& contCurso = fabrica.getIControladorCurso();
                contCurso.listarNombresDeCursos();
                cout << "Ingrese un curso" << endl;
                string curs;
                cin >> curs;*/


                break;
            }
            case 11:{
                ///FALTA QUE MUESTRE LA CANTIDAD DE LECCIONES Y EJERCICIOS DE CADA CURSO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                imprimir("Ingrese nickname de estudiante:");
                string nick = entradaString();
                if(contUsuario.getTipoUsuario(nick)=="estudiante"){
                    contUsuario.seleccionarUsuario(nick);
                    imprimir("Cursos disponibles para " + nick + ":");
                    list<string> cursosDisp = contCurso.cursosDisponibles(nick);
                    for (auto it = cursosDisp.begin(); it != cursosDisp.end(); ++it) {
                        imprimir(*it);
                    }
                    imprimir("Ingrese nombre de curso a inscribirse:");
                    string nombreCurso = entradaString();
                    contCurso.inscribirEstudianteACurso(nombreCurso, nick);
                    imprimir("Estudiante inscripto", VERDE);
                    presionaParaContinuar();
                }else{
                    imprimir("El usuario " + nick + " no es un estudiante, por lo cual no puede inscribirse a ningun curso", AMARILLO);
                    presionaParaContinuar();
                }
                break;
            }
            case 12:{
                imprimir("Ingrese nick de estudiante: ");
                string nick = entradaString();
                contCurso.cursosInscriptoSinAprobar(nick);
                break;
            }
            case 13:{
                //Consultar estadisticas
                //interfazCurso->consultarEstadisticas();
                break;
            }
            case 14:{
                //Suscribirse a notificaciones
                //interfazCurso->suscribirseANotificaciones();
                break;
            }
            case 15:{
                //Consulta de notificaciones
                //interfazCurso->consultaNotificaciones();
                break;
            }
            case 16:{
                //Eliminar suscripciones
                //interfazCurso->eliminarSuscripciones();
                break;
            }
            case 17:{
                ingresarUsuarios();
                imprimir("Usuarios creados", VERDE);
                break;
            }
            default:{
                imprimir("Opcion invalida", AMARILLO);
                presionaParaContinuar();
                break;
            }
        }
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
    contCurso.listarIdiomas();
    string idiom;
    set<string>* setIdi = new set<string>();
    imprimir("Ingrese el nombre del idioma en el que se especializa:");
    while (seguir) {
        idiom = entradaString();
        setIdi->insert(idiom);
        seguir = quiereContinuar("Agregar otro idioma");
    }

    DTProfesor prof = DTProfesor(nick, contrasenia, nombre, descripcion, instituto, setIdi);
    return prof;
}

DTCurso crearDTCurso(){
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
        set<string>* previas;
        if(tienePrevias == "S" || tienePrevias == "s"){
            bool seguir = true;
            while(seguir){
                imprimir("Ingrese nombre de previas del curso:");
                string pre = entradaString();
                factoryController& fabrica = factoryController::getInstancia();
                IControladorCurso& contCurso = fabrica.getIControladorCurso();
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


        DTCurso c = DTCurso(nombre,false,dificultad,descripcion, previas);
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
/*
DTEjercicio crearDTEjercicio(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    
    imprimir("Ingrese la descripción ");
    string descripcion = entradaString();            
    imprimir("Ingrese el tipo de ejercicio (completar o traduccion):");
    string tipo = entradaString(); 
    while (contCurso.getIdsEjercicio().find(id) != contCurso.getIdsEjercicio().end()) {
        imprimir("El ID ya existe. Por favor, ingrese otro");
        id = entradaInt();
    }             
    if (tipo == "completar palabras") {
        imprimir("Ingrese la frase (utilice --- para los espacios a completar)");
        string frase = entradaString();                            
        imprimir("Ingrese las soluciones separadas por comas");
        string solSinSep = entradaString();
        list<string> soluciones = separarString(solSinSep, ',');                                                      
        DTRellenarPalabras ejer =  DTRellenarPalabras( descripcion, frase, id, soluciones,tipo) ;     //el id me lo pasa? me aseguro que no exxista?
        contCurso.idsEjercicio.insert(id);
        return ejer;           

    else if (tipo == "traduccion") {
        imprimir("Ingrese la frase");
        string fraseATraducir = entradaString();
        imprimir("Ingrese la traducción");
        string traduccion = entradaString();
        DTTraduccion ejer = DTTraduccion( descripcion, fraseATraducir, id, traduccion,tipo);
        contCurso.getIdsEjercicio().insert(id);
        return ejer;

    } else {
        imprimir("Tipo de ejercicio no válido");
        DTEjercicio ejer = crearDTEjercicio();
        return ejer;
    }   
}*/
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
    DTRellenarPalabras ejer =  DTRellenarPalabras(descripcion, frase, id, soluciones,tipo,numLec);     //el id me lo pasa? me aseguro que no exxista?
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
    cout << endl << "Presiona cualquier tecla para continuar...";
    cin.ignore();
    cin.get();
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
            cin >> entradita;
            entrada = stoi(entradita);
        }catch(...){
            cout << AMARILLO << "La entrada debe ser un entero positivo." << RESET;
            cout << "Ingrese un entero positivo: ";
        }
    }
    escribirEnLog("U: " + to_string(entrada));
    return entrada;
}


//Funcion para verificar que el string no contenga simbolos, solo letras y numeros
bool esAlfanumerico(string entrada){
    for(int i = 0; i < entrada.length(); i++){
        if(!isalnum(entrada[i])){
            return false;
        }
    }
    return true;
}


string entradaString(){
    bool alfanumerico = false;
    string entrada;
    cin >> entrada;
    while(!esAlfanumerico(entrada)){
        cout << AMARILLO << "La entrada debe ser alfanumerica." << RESET;
        cout << "Ingrese nuevamente: ";
        cin >> entrada;
    }
    escribirEnLog("U: " + entrada);
    return entrada;
}

//DATOS PRUEBA

void ingresarIdiomas(){
    factoryController& fabrica = factoryController::getInstancia();
    IControladorCurso& contCurso = fabrica.getIControladorCurso();
    contCurso.confirmarAltaIdioma("Ingles");
    contCurso.confirmarAltaIdioma("Aleman");
    contCurso.confirmarAltaIdioma("Portugues");
}

void ingresarUsuarios(){
    ingresarIdiomas();
    factoryController& fabrica = factoryController::getInstancia();
    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();
    //ESTUDIANTES
    contUsuario.setDatoEstudiante(DTEstudiante("jpidiom","asdfg123","Juan Perez","Soy un apasionado del aprendizaje de idiomas","Argentina",DTFecha(15,7,1995)));
    contUsuario.confirmarAltaUsuario();
    contUsuario.setDatoEstudiante(DTEstudiante("marsilva","qwer456","Maria Silva","Como amante de los idiomas disfruto explorando nuevas formas de interactuar","Ecuador",DTFecha(28,2,1998)));
    contUsuario.confirmarAltaUsuario();
    contUsuario.setDatoEstudiante(DTEstudiante("pero12","789werty","Pedro Rodriguez","Soy un entuciaste del aprendizaje de idiomas","Peru",DTFecha(10,11,1994)));
    contUsuario.confirmarAltaUsuario();
    //Faltan mas...
    //PROFESORES
    set<string>* i1 = new set<string>; i1->insert("Ingles"); i1->insert("Portugues");
    contUsuario.setDatoProfesor(DTProfesor("langMaster","P4s512","Marta Grecia", "Soy una profesora apasionada por los idiomas","Instituto de Idiomas Moderno", i1));
    contUsuario.confirmarAltaUsuario(); delete i1;

    set<string>* i2 = new set<string>; i2->insert("Ingles"); i2->insert("Aleman"); i2->insert("Portugues");
    contUsuario.setDatoProfesor(DTProfesor("linguaPro","Pess23","Carlos Preto", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas","Centro Global", i2));
    contUsuario.confirmarAltaUsuario(); delete i2;

    set<string>* i3 = new set<string>; i3->insert("Aleman");
    contUsuario.setDatoProfesor(DTProfesor("talkExpert","Secret1","Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas","Instituto de Idiomas Vanguardia", i3));
    contUsuario.confirmarAltaUsuario(); delete i3;
}