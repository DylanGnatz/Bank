#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <vector>
#include "person.h"
#include "checking-account.h"
#include "receipt.h"
using namespace std;

class Customer : virtual public Person {
private:
    CheckingAccount _checkingAccount;
public:
    Customer(string);
    CheckingAccount& getCheckingAccount();
    vector<Receipt> monthly();
};


#endif /* CUSTOMER_H_ */
