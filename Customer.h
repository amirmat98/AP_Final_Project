#ifndef PHASE_1_CUSTOMER_H
#define PHASE_1_CUSTOMER_H

#include "Header.h"
#include "User.h"

class Customer : public User {
public:
    Customer(std::string , std::string , std::string , int);
};


#endif //PHASE_1_CUSTOMER_H
