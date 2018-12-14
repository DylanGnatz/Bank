#include "id-entity.h"

//  This initializes the static variable
int IDEntity::_next_id = 1;

IDEntity::IDEntity() {
    _id = _next_id++;
}

int IDEntity::getID() const {
    return _id;
}
