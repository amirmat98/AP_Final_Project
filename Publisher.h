#ifndef PHASE_1_PUBLISHER_H
#define PHASE_1_PUBLISHER_H

#include "Header.h"
#include "Customer.h"

class Publisher : public Customer
{
public:
    Publisher(std::string , std::string , std::string , int);
};


#endif //PHASE_1_PUBLISHER_H
