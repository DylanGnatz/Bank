#include "person.h"

Person::Person(string name): IDEntity() {
    _name = name;
}

string Person::getName() const {
    return _name;
}

