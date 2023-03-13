#include <string>
#include "Objeto.h"
using namespace std;

class Libro: public Objeto{
    private:
        string Autor;
        int CantPaginas;
    public:
        string toString();
};