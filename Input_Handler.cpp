#include "Input_Handler.h"

using namespace std;

Input_Handler::Input_Handler(Core* ccore)
{
    my_core = ccore;
    //initialize();

}

/*void Input_Handler::initialize()
{
    map_order_type["PUT"] = PUT;
    map_order_type["POST"] = POST;
    map_order_type["GET"] = GET;
    map_order_type["DELETE"] = DELETE;
}*/

void Input_Handler::run()
{
    string right_now_input = get_input();
    process(right_now_input);
    if(!check_validate_order(my_core->right_now_order))
        throw Find();
}

string Input_Handler::get_input()
{
    string temp;
    getline(cin,temp);
    return temp;
}

void Input_Handler::process(std::string& right_now_input)
{
    remove_space(right_now_input);
    cout<<right_now_input<<endl;
    set_order_type(right_now_input);
    set_order(right_now_input);
    if(my_core->right_now_order == "notifications")
        make_word(right_now_input);
    make_word(right_now_input);
    set_parameter(right_now_input);
}
void Input_Handler::remove_space(std::string& right_now_input)
{
    bool first_space = false;
    //bool end_space = false;
    //bool middle_space = false;
    bool space = false;

    for(string::iterator it = right_now_input.begin() ; it != right_now_input.end() ; it++)
    {
        if(*it == SPACE && !first_space)
        {
            right_now_input.erase(it--);
        }

        else if (*it != SPACE && !first_space)
        {
            first_space = true;
        }

        if(*it == SPACE && first_space)
        {
            if(!space)
                space = true;
            else
            {
                right_now_input.erase(it--);
            }
        }
        else if (*it != SPACE && first_space && space)
        {
            space = false;
        }
    }

}

void Input_Handler::set_order_type(string& right_now_input)
{
    string temp = make_word(right_now_input);
    if(!check_validate_order_type(temp))
        throw Request();
    my_core->set_right_now_order_type(temp);
}

void Input_Handler::set_order(string& right_now_input)
{
    string temp = make_word(right_now_input);
    my_core->set_right_now_order(temp);
}

void Input_Handler::set_parameter(string& right_now_input)
{
    map<string,string> temp_parameter;
    bool turn = false; // 0 = false , 1 = true //
    string key, para;
    while (right_now_input.size()>0)
    {

        if (!turn)
        {
            key = make_word(right_now_input);
            turn = true;
        }
        if(turn)
        {
            para = make_word(right_now_input);
            //make_parameter(para);
            turn = false;
        }


        temp_parameter.insert(pair<string,string> (key , para));
    }

    my_core->set_right_now_parameter(temp_parameter);

}

string Input_Handler::make_word(std::string &x)
{
    string temp;
    for(string::iterator it = x.begin() ; it != x.end() ; it++)
    {
        if(*it != SPACE)
        {
            temp += *it;
            x.erase(it--);
        }

        else if (*it == SPACE)
        {
            x.erase(it--);
            break;
        }
    }
    return temp;
}

void Input_Handler::make_parameter(std::string &x)
{
    string temp = make_word(x);
    temp.erase(temp.begin());
    temp.erase(temp.end() - 1);
    x = temp;
}

bool Input_Handler::check_validate_order(std::string _right_now_order)
{
    for (int i = 0 ; i<SIZE_OF_VALIDATE_ORDER ; i++)
    {
        if(_right_now_order == validate_order[i])
            return true;
    }
    return false;
}

bool Input_Handler::check_validate_order_type(string x)
{
    if(x != "POST")
        return true;
    if(x != "PUT")
        return true;
    if(x != "DELETE")
        return true;
    if(x != "GET")
        return true;

    return false;

}