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
    return false;
    // Implementar la lógica para verificar si las respuestas son correctas
    // Comparar las respuestas con la lista de palabras esperadas
    // ...
}
bool RellenarPalabras::esCorrectoRellenarPal(set<string> respuestas) {
    bool resp = true;
    auto it = respuestas.begin();
    list<string> sol = getlista();
    auto it2 = sol.begin();
    while(resp && it!= respuestas.end() && it2 != sol.end()){
        if((*it) != (*it2)){
            return false;
        }

        it++;
        it2++;
    }
    if(it == respuestas.end() && it2 != sol.end()){
        resp = false;
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