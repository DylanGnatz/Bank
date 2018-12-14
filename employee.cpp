#include "employee.h"
#include <iostream>
#include "receipt.h"
#include <vector>
using namespace std;

Employee::Employee(string name, double salary) : Person(name) {
    if (name == "")
        throw (string) "Invalid name.";
    if (salary < 0)
        throw (string) "Invalid salary.";
    _salary = salary;
}

double Employee::getSalary() const {
    return _salary;
}

// Employee does monthly just by generating a Payment receipt in the
// amount of its salary.  Since it has no account, it can't deposit.

vector<Receipt> Employee::monthly() {
    vector <Receipt> receipts;
    receipts.push_back(Receipt(getID(), Payment, _salary));
    return receipts;
}

