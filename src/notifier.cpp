#include "notifier.h"

void Notifier::registraObservador(Observer& o) {
    //this->observadores.insert(o);
    this->observadores.push_back(&o);
}

void Notifier::removeObservador(Observer& o) {
    this->observadores.remove(&o);
}