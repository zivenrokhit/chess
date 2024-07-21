#include "subject.h"

void Subject::notifyObserver(){
    for(auto it: observers){
        it->notify();
    }
}

void Subject::attach(Observer *o){
    observers.emplace_back(o);
}

void Subject::detach(Observer *o){
    for(auto it = observers.begin(); it != observers.end(); ++it){
        if(*it == o){
            observers.erase(it);
            break;
        }
    }
}
