#include "receipt.h"
#include <iostream>
using namespace std;

Receipt::Receipt(double id, TransactionType tt, double amt) {
    _accountID = id;
    _transactionType = tt;
    _amount = amt;
}

int Receipt::getAccountID() const {
    return _accountID;
}
TransactionType Receipt::getTransactionType() const {
    return _transactionType;
}

double Receipt::getAmount() const {
    return _amount;
}

string ttstring(TransactionType t) {
    string ttstrings[] = {"Deposit", "Withdrawal", "Payment", "Fee"};
    return ttstrings[t];
}

ostream &operator<< (ostream &o, const Receipt &r) {
    o.precision(2);
    o << "{Receipt: Acct# " << r.getAccountID() <<
      ", Type: " << ttstring(r.getTransactionType()) <<
      ", Amount: $" << fixed << r.getAmount() <<
      "}";
    return o;
}

