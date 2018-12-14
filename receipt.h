#ifndef RECEIPT_H_
#define RECEIPT_H_
#include <string>
using namespace std;

enum TransactionType { Deposit=0, Withdrawal, Payment, Fee };

class Receipt {
private:
    int _accountID;
    TransactionType _transactionType;
    double _amount;
public:
    Receipt(double, TransactionType, double);
    int getAccountID() const;
    TransactionType getTransactionType() const;
    double getAmount() const;
};

// Receipt overloads the << operator.  Notice this
// definition is outside the class declaration.

ostream &operator<< (ostream&, const Receipt&);
#endif /* RECEIPT_H_ */
