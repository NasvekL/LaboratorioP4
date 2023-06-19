#include "../../include/Clases/RellenarPalabras.h"

RellenarPalabras::RellenarPalabras(list<string> listaDePalabras, int idEjercicio, string descripcion, string letra, Leccion* Lec) {
    this->listaDePalabras = listaDePalabras;
    this->setIdEjercicio(idEjercicio);
    this->setDescripcion(descripcion);
    this->setLetra(letra);
    this->setLeccion(Lec);
    // Constructor de la clase RellenarPalabras
}

list<string> RellenarPalabras::getlista() {
    return listaDePalabras;
}
bool RellenarPalabras::esCorrectoTraduccion(string respuestas) {
    cout << "Falta implementar escorrectotraduccion en rellenarpalabras, siempre devuelve false" << endl;
    return false;
}
bool RellenarPalabras::esCorrectoRellenarPal(list<string> respuestas) {

    bool resp = true;
    auto it = respuestas.begin();
    auto it2 = listaDePalabras.begin();
    if(respuestas.size()!= listaDePalabras.size())
        return false;
    while(it!= respuestas.end() && it2 != listaDePalabras.end()){
        if((*it) != (*it2)){
            return false;
        }
        it++;
        it2++;
    }
    return resp;
}

void RellenarPalabras::aumentarProgreso(string estudiante) {
    // Implementar la lógica para aumentar el progreso del estudiante
    // según la resolución de este ejercicio de rellenar palabras
    // ...
}

RellenarPalabras::~RellenarPalabras() {
    // Destructor de la clase RellenarPalabras
    // Realizar cualquier limpieza de memoria u otras tareas necesarias
    // ...
}