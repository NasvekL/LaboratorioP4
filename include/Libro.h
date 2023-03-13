#ifndef LIBRO
#define LIBRO
#include "Objeto.h"
#include "Utils.h"

class Libro: public Objeto{
    private:
        string Autor;
        int CantPaginas;
    public:
        string toString();
        //Getters y Setters
        string getAutor();
        void setAutor(string Autor);
        int getCantPaginas();
        void setCantPaginas(int CantPaginas);
        //Constructor y destructor
        ~Libro();
        Libro();
};



#endif