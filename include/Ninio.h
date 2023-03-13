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
        Ninio(); //constructor
        ~Ninio(); //destructor
        //Getters / Setters
        string getnombre();
        void setnombre(string);
        string getdireccion();
        void setdireccion(string);
        string gettelefono();
        void settelefono(string);
        string getedad();
        void setedad(int);

};


#endif