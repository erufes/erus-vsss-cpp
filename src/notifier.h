#ifndef NOTIFIER_H
#define NOTIFIER_H
#include "observer.h"
#include <list>
using namespace std;

class Notifier {
    list<Observer*> observadores;
    
    void registraObservador(Observer& o);
    void removeObservador(Observer& o);
    void notifica();
};
#endif