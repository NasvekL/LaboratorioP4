#ifndef IOBSERVER
#define IOBSERVER


class IObserver{
    public:
        virtual void notificar(DTNotificacion noti) = 0;
};


#endif