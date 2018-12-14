#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "person.h"
#include "id-entity.h"
#include "receipt.h"
#include <vector>
using namespace std;

// virtual is required to support the "diamond" multiple inheritance

class Employee : virtual public Person {
private:
    double _salary;
public:
    Employee(string, double);
    double getSalary() const;
    vector<Receipt> monthly();
};

#endif /* EMPLOYEE_H_ */
