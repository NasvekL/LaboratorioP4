#ifndef NINIO
#define NINIO
#include <string>
using namespace std;

class Ninio {
    private:
        string nombre;
        int edad;
        string direccion;
        string telefono;
    public:
        string *ListarObjetosPrestados();
        //Getters / Setters
        string getnombre();
        void setnombre(string nombre);
        string getdireccion();
        void setdireccion(string direccion);
        string gettelefono();
        void settelefono(string telefono);
        string getedad();
        void setedad(int edad);
        
};


#endif