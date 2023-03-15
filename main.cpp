#include "include/DtObjetoRoto.h"
#include "include/JuegoMesa.h"
#include "include/Ninio.h"
#include "include/Libro.h"
#include "include/Utils.h"


int main(){
    //Parte a)   (sin salida por consola)
    Libro libro1("Beandon Sanderson", 688, "Nacidos de la bruma: El imperio final", 2022, roto);
    Libro libro2("Camila Sosa Villada", 240, "Las Malas", 2022, nuevo);
    Libro libro3("Gemma Merino", 32, "El cocodrilo al que no le gustaba el agua", 2016, roto);
    //Parte b)   (sin salida por consola)

    JuegoMesa j1(7, 10, "Juego Uno", 2022, roto);
    JuegoMesa j2(7, 4, "Mazo de Cartas", 2019, nuevo);
    JuegoMesa j3(2, 6, "Dados", 2020, roto);



    cout << "Parte c)" << endl;



    cout << "Parte d)" << endl;
            Ninio n1("María Laura", 10, "Nueva Palmira 1521", "099298190");
            Ninio n2("Alex", 5, "Humberto Primo 1501",  "29094141");

    cout << "Parte e)" << endl;
    n1.agregar_objeto(&j1);
    n1.agregar_objeto(&libro1);
    n1.agregar_objeto(&j1);
    n2.agregar_objeto(&libro1);
    n2.agregar_objeto(&libro1);


    cout << "Parte f)" << endl;
    n1.ListarObjetosPrestados();
    n2.ListarObjetosPrestados();


    cout << "Parte g)" << endl;



    cout << "Parte h)" << endl;



    return 0;
}