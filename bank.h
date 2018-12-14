#ifndef BANK_H_
#define BANK_H_
#include <map>
#include <vector>
#include "checking-account.h"
#include "person.h"
#include "receipt.h"

class Bank {
private:
    vector<Person*> _people;  // All the Customers, Employees, and CustomerEmployees
    map<int, CheckingAccount*> _checkingAccounts;  // Map from person ID
public:
    Bank();
    CheckingAccount* getCheckingAccount(int);
    vector<Receipt> monthly();
    int addCustomer(string);
    int addEmployee(string, double);
    int addCustomerEmployee(string, double);
};

#endif /* BANK_H_ */
