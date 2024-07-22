#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"
#include <vector>

using namespace std;

class Subject {
    private:
    vector<Observer*> observers; // holds pointers to objects that are observing the subject for changes. 
    public:
    void notifyObserver(); // call update method on each item in vector. Subject informs all  observers about changes or updates.
    void attach(Observer *o); // add observer to the vector observers
    void detach(Observer *o); // remove observer from the vector observers
    virtual ~Subject() = default;
};

#endif
