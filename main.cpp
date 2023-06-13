//hay que incluir la interfaz? o el controlador directo? en caso de que sea el controlador directo, la interfaz nunca se usa pa nada
//pq la interfaz es abstracta, eentonces nunca se llega a crear una instancia creo...
#include "include/Interfaces/IControladorCurso.h"
#include "include/Interfaces/IControladorUsuario.h"
#include "include/Controladores/ControladorCurso.h"
#include "include/Controladores/ControladorUsuario.h"
#include "include/FactoryController.h"



// Macros para definir los códigos de escape ANSI para colores
#define RESET    "\033[0m"
#define ROJO     "\033[31m"
#define VERDE    "\033[32m"
#define AMARILLO "\033[33m"

int seleccionEstudianteOProfesor();
DTEstudiante crearDTEstudiante();
DTProfesor crearDTProfesor();
void esperar(double time);
int entradaInt();
string entradaString();
bool quiereContinuar();
void presionaParaContinuar();
void limpiarLog();
void imprimir(string texto);
void imprimir(string texto, string color);


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

            case 2:{
                    IControladorUsuario& contUsuario = fabrica.getIControladorUsuario();
                    contUsuario.consultarUsuario();
                    cout << "Ingrese el nick deseado" << endl;
                        string nick;
                        cin >> nick;
                        contUsuario.seleccionarUsuario(nick);
                        /*auto it = users->find(nick);
                        if (it != users->end()) {
                            Usuario& usuario = it->second;
                            cout << "Nombre: " << usuario.getNombre() << endl;
                            cout << "Descripción: " << usuario.getDescripcion() << endl;
                        */

                            //falta seguir, como veo si es un profe o un estudiante?
                            //solo faltan los get dependiendo si es estu o profe
                        //}
                    break;
            }
            case 3:{
                    imprimir("Ingrese idioma:");
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
                    contCurso.listarIdiomas();
                    //interfazCurso->consultarIdiomas();
                    break;
            }
            case 5:{
                    //Alta de curso
                    //interfazCurso->altaCurso();
                    break;
            }
            case 6:{
                    //Agregar leccion
                    //interfazCurso->agregarLeccion();
                break;
            }
            case 7:{
                //Agregar ejercicio
                //interfazCurso->agregarEjercicio();
                break;
            }
            case 8:{
                //Habilitar curso
                //interfazCurso->habilitarCurso();
                break;
            }
            case 9:{
                //Eliminar curso
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
                imprimir("Ingrese nickname de estudiante:");
                string nick = entradaString();
                contUsuario.seleccionarUsuario(nick);
                //verificar si el usuario es un estudiante
                //en caso de que si:
                    imprimir("Cursos disponibles para : " + nick);
                    //CursosDisponibles(nick) :setString
                    //for each curso in CursosDisponibles
                        //imprimir(nombreCurso);
                    imprimir("Ingrese nombre de curso:");
                    string nombreCurso = entradaString();
                    //inscribirEstudiante (nombrecurso)
                //en caso de que no
                    //imprimir("El usuario no es un estudiante, por lo cual no puede inscribirse a ningun curso");
                break;
            }
            case 12:{
                //Realizar ejercicio
                //interfazCurso->realizarEjercicio();
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
            default:{
                imprimir("Opcion invalida", AMARILLO);
                presionaParaContinuar();
                break;
            }
        }
    }

    return 0;
}

void esperar(double time){
this_thread::sleep_for(chrono::duration<double>(time));
}

int seleccionEstudianteOProfesor(){
    imprimir("1. Ingresar Estudiante");
    imprimir("2. Ingresar Profesor");
    int opcion = entradaInt();
    return opcion;
};

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
        seguir = quiereContinuar();
    }

    DTProfesor prof = DTProfesor(nick, contrasenia, nombre, descripcion, instituto, setIdi);
    return prof;
}

bool quiereContinuar(){
    imprimir("1: Agregar otro idioma");
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