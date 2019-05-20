#include "Parameter_Handler.h"

using namespace std;

Parameter_Handler::Parameter_Handler()
{

}
void Parameter_Handler::handler_sign_up(std::map<std::string, std::string>& _parameter, std::string &_email,
                                        std::string &_username, std::string &_password, int &_age, bool &_is_publisher)
{
    map<string,string>::iterator it;

    it = _parameter.find("email");
    _email = it->second;

    it = _parameter.find("username");
    _username = it->second;

    it = _parameter.find("password");
    _password = it->second;

    it = _parameter.find("age");
    _age = stoi(it->second);

    it = _parameter.find("publisher");
    _is_publisher = false;
    if(it != _parameter.end())
    {
        if(it->second == "true")
            _is_publisher = true;
    }


}

void Parameter_Handler::check_validate_username(Core *ccore, std::string _username)
{
    for(int i = 0 ; i<ccore->get_my_users().size() ; i++)
    {
        if(ccore->get_my_users()[i]->get_username() == _username)
        {
            throw Request();
        }
    }
}

void Parameter_Handler::handler_loging(std::map<std::string, std::string> &_parameter, std::string &_username,
                                       std::string &_password)
{
    map<string,string>::iterator it;

    it = _parameter.find("username");
    _username = it->second;

    it = _parameter.find("password");
    _password = it->second;
}

void Parameter_Handler::check_validate_user(Core *ccore, std::string &_username, std::string _password , User* _temp)
{
    for (int i = 0 ; i<ccore->get_my_users().size() ; i++)
    {
        if(ccore->get_my_users()[i]->get_username() == _username)
        {
            if(ccore->get_my_users()[i]->get_password() == _password)
            {
                _temp = ccore->get_my_users()[i];
            }
            else
                throw Request();
        }
        else
            throw Request();

    }
}
