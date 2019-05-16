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
        handel();
        cout<<"finish"<<endl;
    }
}

void Core::handel()
{
    if(right_now_order_type == POST)
    {
        if(right_now_order == "signup")
        {
            sign_up(right_now_parameter);
        }
        if(right_now_order == "login")
        {
            login(right_now_parameter);
        }
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
void Core::sign_up(std::map<std::string, std::string> _parameter)
{
    map<string,string>::iterator it;

    it = _parameter.find("email");
    string _email = it->second;

    it = _parameter.find("username");
    string _username = it->second;

    it = _parameter.find("password");
    string _password = it->second;

    it = _parameter.find("age");
    int _age = stoi(it->second);

    it = _parameter.find("publisher");
    bool _is_publisher = false;
    if(it != _parameter.end())
    {
        if(it->second == "true")
            _is_publisher = true;
    }

    User* temp;
    temp = add_user(_email,_username,_password,_age,_is_publisher);
    temp->set_ID(my_users.size()+1);
    my_users.push_back(temp);
    current_user = temp->get_my_type();
    right_now_user = temp;

}

void Core::login(std::map<std::string, std::string> _parameter)
{
    map<string,string>::iterator it;

    it = _parameter.find("username");
    string _username = it->second;

    it = _parameter.find("password");
    string _password = it->second;

    User* temp;

    for(int i = 0 ; i<my_users.size() ; i++)
    {
        if(my_users[i]->get_username() == _username)
        {
            temp = my_users[i];
            break;
        }
    }

    if(temp->get_password() == _password)
    {
        current_user = temp->get_my_type();
        right_now_user = temp;
    }

    ///else : handle wrong password
}

User* Core::add_user(std::string _email, std::string _username, std::string _password, int _age , bool is_publisher)
{
    if (is_publisher)
    {
        User* temp = (User * ) new Publisher(_email, _username, _password , _age);
        temp->set_type(PUBLISHER);
    }
    else
    {
        User* temp = (User * ) new Customer(_email, _username, _password , _age);
        temp->set_type(CUSTOMER);
    }
}
