#ifndef LIBRO
#define LIBRO
#include "Objeto.h"
#include <string>
using namespace std;

class Libro: public Objeto{
    private:
        string Autor;
        int CantPaginas;
    public:
        string toString();
        //Getters y Setters
        string getAutor();
        void setAutor(string Autor);
        string getCantPaginas();
        void setCantPaginas(int CantPaginas);
};



#endif