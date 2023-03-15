#ifndef NINIO
#define NINIO
#include <set>
#include <string>
#include "Objeto.h"
using namespace std;

class Ninio {
    private:
        string nombre;
        int edad;
        string direccion;
        string telefono;
        Objeto *prestadoA;
    public:
        set<std::string> ListarObjetosPrestados();
        Ninio(); //constructor
        ~Ninio(); //destructor
        //Getters / Setters
        string getnombre();
        void setnombre(string);
        string getdireccion();
        void setdireccion(string);
        string gettelefono();
        void settelefono(string);
        int getedad();
        void setedad(int);

};


#endif