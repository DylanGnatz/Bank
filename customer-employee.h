#ifndef CUSTOMER_EMPLOYEE_H_
#define CUSTOMER_EMPLOYEE_H_
#include "customer.h"
#include "employee.h"
#include <string>
using namespace std;

class CustomerEmployee : public Customer, public Employee {
public:
    CustomerEmployee(string, double);
    vector<Receipt> monthly();
};

#endif /* CUSTOMER_EMPLOYEE_H_ */
