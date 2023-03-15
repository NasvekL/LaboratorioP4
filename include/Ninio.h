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
        list<Objeto*> objetos_;
    public:
        set<string> ListarObjetosPrestados();
        Ninio(string nom,int edad,string dir,string tel); //constructor
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
        void agregar_objeto(Objeto* objeto);
        list<Objeto*>& objetos() ;
};


#endif