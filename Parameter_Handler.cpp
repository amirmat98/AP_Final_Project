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

void Parameter_Handler::check_validate_user(Core *ccore, std::string &_username, std::string _password , User*& _temp)
{
    for (int i = 0 ; i<ccore->get_my_users().size() ; i++)
    {
        if(ccore->get_my_users()[i]->get_username() == _username)
        {
            if(ccore->get_my_users()[i]->get_password() == _password)
            {
                _temp = ccore->get_my_users()[i];
                return;
            }
            else
                throw Request();
        }
    }
    throw Request();
}

void Parameter_Handler::handler_add_film(std::map<std::string, std::string> &_parameter, string &_name, int &_year,
                                         int &_length, int &_price, std::string &_summary, std::string &_director)
{
    map<string,string>::iterator it;

    it = _parameter.find("name");
    _name = it->second;

    it = _parameter.find("year");
    _year = stoi(it->second);

    it = _parameter.find("length");
    _length = stoi(it->second);

    it = _parameter.find("price");
    _price = stoi(it->second);

    it = _parameter.find("summary");
    _summary = it->second;

    it = _parameter.find("director");
    _director = it->second;
}

void Parameter_Handler::handler_modify_film(std::map<std::string, std::string> _parameter, Film*& _temp)
{
    map<string,string>::iterator it;
    it = _parameter.find("name");
    if(it != _parameter.end())
        _temp->set_name(it->second);

    it = _parameter.find("year");
    if(it != _parameter.end())
        _temp->set_year(stoi(it->second));

    it = _parameter.find("length");
    if(it != _parameter.end())
        _temp->set_length(stoi(it->second));

    it = _parameter.find("summary");
    if(it != _parameter.end())
        _temp->set_summary(it->second);

    it = _parameter.find("director");
    if(it != _parameter.end())
        _temp->set_director(it->second);
}

void Parameter_Handler::handler_delete_film(std::map<std::string, std::string> _parameter , int& _film_id)
{
    map<string,string>::iterator it;
    it = _parameter.find("film_id");
    _film_id = stoi(it->second);
}

void Parameter_Handler::check_validate_film_for_delete(Core *ccore, int _film_id)
{
    bool not_found = true;
    for(int i = 0 ; i<ccore->get_my_films().size() ; i++)
    {
        if(ccore->get_my_films()[i]->get_ID() == _film_id)
            not_found = false;
    }
    if(not_found)
        throw Find();

    for(int i = 0 ; i<ccore->get_my_films().size() ; i++)
    {
        if(ccore->get_my_films()[i]->get_ID() == _film_id)
        {
            if(ccore->get_my_films()[i]->get_publisher() != ccore->right_now_user)
                throw Permission();

        }
    }
}
