#include "Core.h"

using namespace std;

Core::Core()
{
    //my_input_file = my_file;
    current_user = GUEST;
}

void Core::main()
{
    while (cin)
    {
        my_input_handler = new Input_Handler(this);
        my_input_handler->run();
    }
}

std::vector<std::string> Core::get_my_input_file()
{
    return my_input_file;
}

void Core::set_right_now_order_type(std::string temp)
{
    if(temp == "POST")
        right_now_order_type = POST;
    else if (temp == "PUT")
        right_now_order_type = PUT;
    else if (temp == "DELETE")
        right_now_order_type = DELETE;
    else if (temp == "GET")
        right_now_order_type = GET;
}

void Core::set_right_now_order(std::string temp)
{
    right_now_order = temp;
}

void Core::set_right_now_parameter(std::map<std::string, std::string> temp)
{
    right_now_parameter = temp;
}