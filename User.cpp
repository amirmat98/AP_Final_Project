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

string User::get_email()
{
    return email;
}

int User::get_ID()
{
    return ID;
}

void User::add_in_my_films(Film* x)
{
    my_films.push_back(x);
}

void User::set_in_my_films(Film &x)
{
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == x.get_ID())
        {
            my_films[i] = &x;
        }
    }
}

void User::delete_in_my_films(int x)
{
    int i = 0;
    for(i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == x)
            break;
    }
    my_films.erase(my_films.begin() + i);
}

vector<Film*> User::get_film()
{
    return my_films;
}

Film* User::pointer_of_my_film(int _ID)
{
    for (int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _ID)
            return my_films[i];
    }
}

vector<User*> User::get_followers()
{
    return my_followers;
}

void User::print()
{
        cout<<ID;
        cout<<" ";
        cout<<"|";
        cout<<" ";
        cout<<username;
        cout<<" ";
        cout<<"|";
        cout<<" ";
        cout<<email;
}

vector<User*> User::sort_followers()
{
    vector<User*> temp;
    for(int i = 0 ; i<my_followers.size() ; i++)
    {
        User* temper = my_followers[i];
        for(int j=0 ; j<my_followers.size(); j++)
        {
            if(temper->get_ID()>my_followers[j]->get_ID())
                temper = my_followers[j];
        }
        temp.push_back(temper);
    }
    return temp;
}