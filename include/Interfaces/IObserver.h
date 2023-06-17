#ifndef IOBSERVER
#define IOBSERVER
#include "../DTs/DTNotificacion.h"
class IObserver{
    public:
        virtual void notificar(DTNotificacion noti) = 0;
};


#endif