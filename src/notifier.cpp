#include "notifier.h"

void Notifier::registraObservador(Observer& o) {
    this->observadores.push_back(&o);
}

void Notifier::removeObservador(Observer& o) {
    this->observadores.remove(&o);
}

void Notifier::notifica(){
    for(auto it = observadores.begin(); it != observadores.end(); it++) {
        (*it)->notifica();
    }
}