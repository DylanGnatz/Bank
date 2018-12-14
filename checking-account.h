#ifndef CHECKING_ACCOUNT_H_
#define CHECKING_ACCOUNT_H_
#include "id-entity.h"
#include "receipt.h"
#include <vector>
using namespace std;

class CheckingAccount : public IDEntity {
private:
    static constexpr double SERVICE_CHARGE = 1.0;
    double _balance;
public:
    CheckingAccount();
    double getBalance() const;
    Receipt* deposit(double);
    Receipt* withdraw(double);
    vector<Receipt> monthly();
};

#endif /* CHECKING_ACCOUNT_H_ */
