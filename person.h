#ifndef PERSON_H_
#define PERSON_H_
#include <string>
#include <vector>
#include "id-entity.h"
#include "receipt.h"

using namespace std;

// Note monthly() is declared "pure virtual" so its subclasses
// Employee, Customer, and CustomerEmployee need to implement it,
// and the compiler is forced to dispatch on the proper subclass at
// run time.  It's what enables us to call monthly() on a vector of Persons
// where each element of the vector is actually a subclass.

class Person : public IDEntity {
private:
    string _name;
protected:
    Person(string);
public:
    string getName() const;
    virtual vector<Receipt> monthly() = 0;
};

#endif /* PERSON_H_ */
