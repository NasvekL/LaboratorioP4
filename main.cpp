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
bool esAlfanumerico(string entrada);
string entradaString();

//Desplegar menu por consola
int menuPrincipal(){
    system("clear");
    cout << "Menu" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Consulta de usuario" << endl;
    cout << "3. Alta idioma" << endl;
    cout << "4. Consultar idiomas" << endl;
    cout << "5. Alta de curso" << endl;
    cout << "6. Agregar leccion" << endl;
    cout << "7. Agregar ejercicio" << endl;
    cout << "8. Habilitar curso" << endl;
    cout << "9. Eliminar curso" << endl;
    cout << "10. Consultar curso" << endl;
    cout << "11. Inscribirse a curso" << endl;
    cout << "12. Realizar ejercicio" << endl;
    cout << "13. Consultar estadisticas" << endl;
    cout << "14. Suscribirse a notificaciones" << endl;
    cout << "15. Consulta de notificaciones" << endl;
    cout << "16. Eliminar suscripciones" << endl;
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;
    return opcion;
}
//HOLA


int main(){
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
    int opcion = 1;
while(opcion != 0){
    opcion = menuPrincipal();
    switch (opcion){
        case 0:{
            cout << "chau bo" << endl;
            break;
        }
        case 1:{
            int seleccion = seleccionEstudianteOProfesor();
            switch (seleccion){
                case 1:{
                    factoryController& Fabrica = factoryController::getInstancia();
                    IControladorUsuario& ContUsuario = Fabrica.getIControladorUsuario();
                    DTEstudiante est = crearDTEstudiante();
                    ContUsuario.guardarDatosEstudiante(est);
                    cout << VERDE << "Estudiante creado" << RESET << endl;
                    esperar(3);
                    break;
                }
                case 2:{
                    DTProfesor prof = crearDTProfesor();
                    // TO DO: realizar acciones para el profesor
                    break;
                }
            }
            break;
        }

            case 2:{
                //Consulta de usuario
                //interfazUsuario->consultaUsuario();
                break;
            }
            case 3:{
                cout<<'Ingrese idioma:'<< endl;
                string idioma;
                cin>> idioma;
                factoryController& Fabrica = factoryController::getInstancia();
                IControladorCurso& ContCurso = Fabrica.getIControladorCurso();
                if(ContCurso.confirmarAltaIdioma(idioma)==false)
                cout << ROJO << "Ya existe Idioma" << RESET << endl;
                esperar(1.5);
                break;
            }
            case 4:{
                //Consultar idiomas
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
                break;
            }
            case 11:{
                //Inscribirse a curso
                //interfazCurso->inscribirseACurso();
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
                cout << ROJO << "Opcion invalida" << RESET << endl;
                esperar(1.5);
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
    cout << "1. Ingresar Estudiante" << endl;
    cout << "2. Ingresar Profesor" << endl;
    int opcion;
    cin >> opcion;
    return opcion;
};

DTEstudiante crearDTEstudiante(){
    cout << "Ingrese nickname de estudiante:" << endl;
    string nick;
    cin >> nick;
    cout << "Ingrese nombre de estudiante:" << endl;
    string nombre;
    cin >> nombre;
    cout << "Ingrese contrasenia de estudiante:" << endl;
    string contrasenia;
    cin >> contrasenia;
    cout << "Ingrese descripcion de estudiante:" << endl;
    string descripcion;
    cin >> descripcion;
    cout << "Ingrese pais de estudiante:" << endl;
    string pais;
    cin >> pais;
    cout << "Ingrese dia de nacimiento de estudiante" << endl;
    int dia;
    cin >> dia;
    cout << "Ingrese mes de nacimiento de estudiante" << endl;
    int mes;
    cin >> mes;
    cout << "Ingrese anio de nacimiento de estudiante" << endl;
    int anio;
    cin >> anio;
    DTFecha fecha = DTFecha(dia,mes,anio);
    DTEstudiante est = DTEstudiante(nick, contrasenia, nombre, descripcion, pais, fecha);
    return est;
};

DTProfesor crearDTProfesor(){
    cout << "Ingrese nickname de profesor:" << endl;
    string nick;
    cin >> nick;
    cout << "Ingrese nombre de profesor:" << endl;
    string nombre;
    cin >> nombre;
    cout << "Ingrese contrasenia de profesor:" << endl;
    string contrasenia;
    cin >> contrasenia;
    cout << "Ingrese descripcion de profesor:" << endl;
    string descripcion;
    cin >> descripcion;
    cout << "Ingrese instituto de profesor:" << endl;
    string instituto;
    cin >> instituto;
}

//verificar que entrada sea un int
int entradaInt(){
    int entrada = -1;
    while(entrada < 0){
        try{
            cin >> entrada;
        }catch(...){
            cout << endl << AMARILLO << "La entrada debe ser un entero positivo." << RESET << endl;
            cout << "Ingrese un entero: ";
        }
    }
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
        cout << endl << AMARILLO << "La entrada debe ser alfanumerica." << RESET << endl;
        cout << "Ingrese nuevamente: ";
        cin >> entrada;
    }
    return entrada;
}


