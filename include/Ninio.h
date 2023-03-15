#ifndef NINIO
#define NINIO
#include "Objeto.h"
#include "Utils.h"

class Ninio {
    private:
        string nombre;
        int edad;
        string direccion;
        string telefono;
        Objeto* objeto_;
        list<Objeto*> prestadoA;
    public:
        set<std::string> ListarObjetosPrestados();
        Ninio(); //constructor
        ~Ninio(); //destructor
        //Getters / Setters
        string getnombre();
        void   setnombre(string);
        string getdireccion();
        void   setdireccion(string);
        string gettelefono();
        void   settelefono(string);
        int    getedad();
        void   setedad(int);
        void asignar_objeto(Objeto* objeto);
        void agregar_objeto(Objeto* objeto);
        Objeto* objeto() const;
};


#endif