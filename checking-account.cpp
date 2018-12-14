#include "checking-account.h"

CheckingAccount::CheckingAccount() {
    _balance = 0.0;
}
double CheckingAccount::getBalance() const {
    return _balance;
}

Receipt* CheckingAccount::deposit(double amount) {
    if (amount < 0)
        throw (string) "Invalid amount.";
    _balance += amount;
    vector<Receipt> vr;
    return new Receipt(getID(), Deposit, amount);
}

Receipt* CheckingAccount::withdraw(double amount) {
    if (amount < 0)
        throw (string) "Invalid amount.";
    if (_balance < amount) {
        return nullptr;
    } else {
        _balance -= amount;
        return new Receipt(getID(), Withdrawal, amount);
    }
}

vector<Receipt> CheckingAccount::monthly() {
    if (_balance < SERVICE_CHARGE) {
        return vector<Receipt>();
    } else {
        Receipt* r = withdraw(SERVICE_CHARGE);
        vector<Receipt> vr;
        vr.push_back(*r);
        vr.push_back(*(new Receipt(getID(), Fee, SERVICE_CHARGE)));
        return vr;
    }
}
