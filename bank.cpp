#include <map>
#include <exception>
#include "bank.h"
#include "customer.h"
#include "employee.h"
#include "customer-employee.h"
#include "checking-account.h"
#include <iostream>
using namespace std;

Bank::Bank() {}

CheckingAccount* Bank::getCheckingAccount(int id) {
    if (_checkingAccounts.find(id) == _checkingAccounts.end())
        throw (string) "Checking account not found.";
    return _checkingAccounts.at(id);

}

//  Construct and add a Customer, return their ID
int Bank::addCustomer(string name) {
    Customer* c = new Customer(name);
    _people.push_back(c);
    _checkingAccounts[c->getID()] = &c->getCheckingAccount();
    return c->getID();
}

// Construct and add an Employee, return their ID
int Bank::addEmployee(string name, double salary) {
    Employee* e = new Employee(name, salary);
    _people.push_back(e);
    return e->getID();
}

// Construct and add a CustomerEmployee, return their ID
int Bank::addCustomerEmployee(string name, double salary) {
    CustomerEmployee* ce = new CustomerEmployee(name, salary);
    _people.push_back(ce);
    _checkingAccounts[ce->getID()] = &ce->getCheckingAccount();
    return ce->getID();
}

/*
 * THIS IS THE PAYOFF -- Bank does monthly processing just by
 * calling the monthly() method on all its Customers, Employees, and
 * CustomerEmployees.  Notice that these are all subclasses of Person,
 * so they need to implement their monthly() methods differently, and
 * this method needs to be declared virtual so polymorphism will work.
 */

vector<Receipt> Bank::monthly() {
    vector<Receipt> vr;  // Accumulate receipts from all the Persons
    for (auto person =_people.begin(); person < _people.end(); person++) {
        vector<Receipt> vr2 = (*person)->monthly();
        vr.insert(vr.end(), vr2.begin(), vr2.end());  // This is vector concatenate
    }
    return vr;
}
