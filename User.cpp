#include "User.h"

using namespace std;

User::User(std::string _email, std::string _username, std::string _password , int _age)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
}

/*User* User::add_user(std::string _email, std::string _username, std::string _password, int _age , bool is_publisher)
{
    if (is_publisher)
    {
        User* temp = (User * ) new Publisher(_email, _username, _password , _age);
        temp->my_type = PUBLISHER;
    }
    else
    {
        User* temp = (User * ) new Customer(_email, _username, _password , _age);
        temp->my_type = CUSTOMER;
    }
}*/

user_type User::get_my_type()
{
    return my_type;
}

void User::set_ID(int _id)
{
    ID = _id;
}

void User::set_type(user_type x)
{
    if(x ==PUBLISHER)
        my_type = PUBLISHER;
    if(x == CUSTOMER)
        my_type = CUSTOMER;
}

string User::get_username()
{
    return username;
}

string User::get_password()
{
    return password;
}