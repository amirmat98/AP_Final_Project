#ifndef PHASE_1_CORE_H
#define PHASE_1_CORE_H

#include "Header.h"
#include "User.h"
#include "Input_Handler.h"

class Input_Handler;

class Core
{

public:
    Core();
    Input_Handler* my_input_handler;
    std::vector<std::string> get_my_input_file();
    void main();
    order_type right_now_order_type;
    void set_right_now_order_type(std::string);
    void set_right_now_order(std::string);
    void set_right_now_parameter(std::map<std::string,std::string>);
    std::string right_now_order;
    std::map< std::string , std::string > right_now_parameter;




private:
    std::vector<User*> my_users;
    std::vector<std::string> my_input_file;
    user_type current_user ;



};


#endif //PHASE_1_CORE_H
