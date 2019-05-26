#ifndef PHASE_1_INPUT_HANDLER_H
#define PHASE_1_INPUT_HANDLER_H

#include "Header.h"
#include "Core.h"

const char CONNECT = '?';
const char SPACE = ' ';
const char FIRST_QUILL = '<';
const char SECOND_QUILL = '>';
//static std::map<std::string, order_type> map_order_type;

class Core;

class Input_Handler
{
public:
    Core* my_core;
    Input_Handler(Core*);
    std::string get_input();
    void process(std::string&);
    void run();
    void remove_space(std::string&);
    void set_order_type(std::string&);
    void set_order(std::string&);
    void set_parameter(std::string&);


private:
    std::string make_word(std::string& x);
    void make_parameter(std::string& x);
    bool check_validate_order(std::string _right_now_order);
    bool check_validate_order_type(std::string _right_now_order_type);

};


#endif //PHASE_1_INPUT_HANDLER_H
