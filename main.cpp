#include <iostream>
#include <vector>
#include "employee.h"
#include "customer.h"
#include "customer-employee.h"
#include "bank.h"
#include "receipt.h"
using namespace std;

int main() {

    Bank b;

    /*  Add three employees, one of each kind */
    int empid = b.addEmployee("Employee", 10.0);
    int custid = b.addCustomer("Customer");
    int ceid = b.addCustomerEmployee("Customer Employee", 30.0);

    cout << "Employee has ID " << empid << " and salary $10.00" << endl;
    cout << "Customer has ID " << custid << " and checking account ID " << b.getCheckingAccount(custid)->getID() << endl;
    cout << "Customer/Employee has ID " << ceid
         << " and checking account ID " << b.getCheckingAccount(ceid)->getID()
         << " and salary $30.00 " << endl;

    /* Make a deposit so the Customer checking account has a balance prior to monthly processing */
    /*  Display the receipt                                                                      */

    cout << endl << "Depositing $100.00 in customer account " << endl;
    CheckingAccount* ce = b.getCheckingAccount(custid);
    Receipt r = *(ce->deposit(100.0));
    cout << "Deposit receipt: " << r << endl;

    cout << endl << "Prior to monthly processing:" << endl;
    cout << "  Customer balance is " << b.getCheckingAccount(custid)->getBalance() << endl;
    cout << "  Customer/Employee balance is  " << b.getCheckingAccount(ceid)->getBalance() << endl;

    vector<Receipt> vr = b.monthly();
    cout << endl << "Receipts from Monthly Processing:" << endl;
    for (auto iter = vr.begin(); iter < vr.end(); iter++) {
        cout << "  " << (*iter) << endl;
    }

    cout << endl << "After monthly processing:" << endl;
    cout << "  Customer balance is " << b.getCheckingAccount(custid)->getBalance() << endl;
    cout << "  Customer/Employee balance is  " << b.getCheckingAccount(ceid)->getBalance() << endl;

}
