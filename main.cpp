#include "include/Utils.h"
#include "include/DtObjetoRoto.h"
#include "include/Ninio.h"
#include "include/Libro.h"
#include "include/JuegoMesa.h"


int main(){
    //Creacion de sets
        set<Objeto*> conjuntoObjetos;
        set<Ninio*> conjuntoNinios;
        set<DtObjetoRoto*> conjuntoObjetosRotos;

    cout << "\nParte a)" << endl;
        //Creacion de libros
        Libro libro1("Beandon Sanderson", 688, "Nacidos de la bruma: El imperio final", 2022, roto);
        Libro libro2("Camila Sosa Villada", 240, "Las Malas", 2022, nuevo);
        Libro libro3("Gemma Merino", 32, "El cocodrilo al que no le gustaba el agua", 2016, roto);
        //Libros insertados en conjunto de objetos
        conjuntoObjetos.insert(&libro1);
        conjuntoObjetos.insert(&libro2);
        conjuntoObjetos.insert(&libro3);
        cout << "Libros creados y agregados al conjunto de objetos" << endl;

    cout << "\nParte b)" << endl;
        //Creacion de juegos de mesa
        JuegoMesa j1(7, 10, "Juego Uno", 2022, roto);
        JuegoMesa j2(7, 4, "Mazo de Cartas", 2019, nuevo);
        JuegoMesa j3(2, 6, "Dados", 2020, roto);
        //Juegos de mesa insertados en conjunto de objetos
        conjuntoObjetos.insert(&j1);
        conjuntoObjetos.insert(&j2);
        conjuntoObjetos.insert(&j3);
        cout << "Juegos de mesa creados y agregados al conjunto de objetos" << endl;

    cout << "\nParte c)" << endl;
        cout << libro1.toString() << endl;
        cout << libro2.toString() << endl;
        cout << libro3.toString() << endl;
        cout << j1.toString() << endl;
        cout << j2.toString() << endl;
        cout << j3.toString() << endl;

    cout << "\nParte d)" << endl;
        Ninio n1("María Laura", 10, "Nueva Palmira 1521", "099298190");
        Ninio n2("Alex", 5, "Humberto Primo 1501",  "29094141");
        conjuntoNinios.insert(&n1);
        conjuntoNinios.insert(&n2);
        cout << "Ninios creados e insertados en el conjunto de ninios." << endl;

    cout << "\nParte e)" << endl;
        n1.agregar_objeto(&j2);
        cout << j2.getNombre() + " ha sido prestado a " + n1.getnombre()  << endl;
        n1.agregar_objeto(&libro1);
        cout << libro1.getNombre() + " ha sido prestado a " + n1.getnombre()  << endl;
        n1.agregar_objeto(&j3);
        cout << j3.getNombre() + " ha sido prestado a " + n1.getnombre()  << endl;
        n2.agregar_objeto(&j1);
        cout << j1.getNombre() + " ha sido prestado a " + n2.getnombre()  << endl;
        n2.agregar_objeto(&libro3);
        cout << libro3.getNombre() + " ha sido prestado a " + n2.getnombre()  << endl;

    cout << "\nParte f)";
        cout << "\nObjetos de "+n1.getnombre()+":" << endl;
        for(string s:n1.ListarObjetosPrestados()){
            cout << s + "\n";
        }
        cout << "\nObjetos de "+n2.getnombre()+":" << endl;
        for(string s:n2.ListarObjetosPrestados()){
            cout << s + "\n";
        }

    cout << "\nParte g)" << endl;
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


    cout << "\nParte h)" << endl;
        Ninio* n_prestado = j1.getPrestadoA();         //n_prestado tiene que ser un puntero?
        n_prestado->eliminar_Robjeto(&j1);
        
        j1.~JuegoMesa();          


        //HAY QUE HACERLO BIEN, TA RARO. NO HABRIA QUE CREAR UN NUEVO SET  DE OBJETOS ROTOS SINO MODIFICAR EL QUE YA ESTA CREADO ANTES


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