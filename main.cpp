#include "include/Utils.h"
#include "include/DtObjetoRoto.h"
#include "include/Ninio.h"
#include "include/Libro.h"
#include "include/JuegoMesa.h"


int main(){
        set<Objeto*> conjuntoObjetos;
        set<Ninio*> conjuntoNinios;



    //Parte a)   (sin salida por consola)
        Libro libro1("Beandon Sanderson", 688, "Nacidos de la bruma: El imperio final", 2022, roto);
        Libro libro2("Camila Sosa Villada", 240, "Las Malas", 2022, nuevo);
        Libro libro3("Gemma Merino", 32, "El cocodrilo al que no le gustaba el agua", 2016, roto);
    //Parte b)   (sin salida por consola)

        JuegoMesa j1(7, 10, "Juego Uno", 2022, roto);
        JuegoMesa j2(7, 4, "Mazo de Cartas", 2019, nuevo);
        JuegoMesa j3(2, 6, "Dados", 2020, roto);



    cout << "Parte c)" << endl;
    cout << libro1.toString();
    cout << libro2.toString();
    cout << libro3.toString();
    cout << j1.toString();
    cout << j2.toString();
    cout << j3.toString();

    cout << "Parte d)" << endl;
        Ninio n1("María Laura", 10, "Nueva Palmira 1521", "099298190");
        Ninio n2("Alex", 5, "Humberto Primo 1501",  "29094141");



    //INSERTO OBJETOS Y NINIOS EN LOS CONJUNTOS
        conjuntoObjetos.insert(&j1);
        conjuntoObjetos.insert(&j2);
        conjuntoObjetos.insert(&j3);
        conjuntoObjetos.insert(&libro1);
        conjuntoObjetos.insert(&libro2);
        conjuntoObjetos.insert(&libro3);
        conjuntoNinios.insert(&n1);
        conjuntoNinios.insert(&n2);
    cout << "Parte e)" << endl;
        n1.agregar_objeto(&j2);
        n1.agregar_objeto(&libro1);
        n1.agregar_objeto(&j3);
        n2.agregar_objeto(&j1);
        n2.agregar_objeto(&libro3);


    cout << "Parte f)" << endl;
    for(string s:n1.ListarObjetosPrestados()){
        cout << s + "\n";
    }
    for(string s:n2.ListarObjetosPrestados()){
        cout << s + "\n";
    }
    cout << "Parte g)" << endl;
        //Crear conjunto de objetos
        set<DtObjetoRoto*> conjuntoObjetosRotos;
        for(Objeto* o: conjuntoObjetos){
            if(o->getEstado() == roto){
                Ninio* n_prestado;
                string nombreNinio;
                string nombreObj = o->getNombre();
                if(o->getPrestadoA() != nullptr){
                    n_prestado = o->getPrestadoA();
                    nombreNinio = o->getPrestadoA()->getnombre();
                }
                else{
                    n_prestado = nullptr;
                    nombreNinio = "";
                }
                conjuntoObjetosRotos.insert(new DtObjetoRoto(nombreObj, n_prestado,nombreNinio));
                DtObjetoRoto f(nombreObj,n_prestado,nombreNinio);
                cout << f << endl;
            }
        }


    cout << "Parte h)" << endl;
        Ninio* n_prestado = j1.getPrestadoA();         //n_prestado tiene que ser un puntero?
        n_prestado->eliminar_Robjeto(&j1); 
        
        j1.~JuegoMesa();          
    set<DtObjetoRoto*> conjuntoObjetosRotos1;
    for(Objeto* o: conjuntoObjetos){
        if(o->getEstado() == roto){
            Ninio* n_prestado;
            string nombreNinio;
            string nombreObj = o->getNombre();
            if(o->getPrestadoA() != nullptr){
                n_prestado = o->getPrestadoA();
                nombreNinio = o->getPrestadoA()->getnombre();
            }
            else{
                n_prestado = nullptr;
                nombreNinio = "";
            }
            conjuntoObjetosRotos.insert(new DtObjetoRoto(nombreObj, n_prestado,nombreNinio));
            DtObjetoRoto f(nombreObj,n_prestado,nombreNinio);
            cout << f << endl;
        }
    }
    for(string s:n2.ListarObjetosPrestados()){
        cout << s + "\n";
    }


    return 0;
}