#ifndef PHASE_1_HEADER_H
#define PHASE_1_HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Error_Handler.h"
#include <iomanip>

enum order_type {PUT, POST, GET, DELETE};
/*static std::map<std::string, order_type> map_order_type;
void initialize()
{
    map_order_type["PUT"] = PUT;
    map_order_type["POST"] = POST;
    map_order_type["GET"] = GET;
    map_order_type["DELETE"] = DELETE;
}*/

enum user_type {PUBLISHER , CUSTOMER , GUEST};


#endif //PHASE_1_HEADER_H
