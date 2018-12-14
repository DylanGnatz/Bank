#include "customer.h"
#include "checking-account.h"
#include "receipt.h"
#include <vector>
using namespace std;

// Note the constructor -- before the curly brackets it calls
// the superclass constructor to supply the name, and also initializes
// its member variable _checkingAccount using that class's 0-place constructor

Customer::Customer(string name) : Person(name), _checkingAccount() {
    if (name == "")
        throw (string) "Invalid name.";
}


CheckingAccount& Customer::getCheckingAccount() {
    return _checkingAccount;
};

vector<Receipt> Customer::monthly() {
    return _checkingAccount.monthly();
}

