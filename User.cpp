#include "User.h"

using namespace std;

User::User(std::string _email, std::string _username, std::string _password , int _age)
{
    email = _email;
    username = _username;
    password = _password;
    age = _age;
    money = 0;
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

void User::print_my_film(std::string _name, int _min_rate, int _min_year, int _price, int _max_year,
                         std::string _director)
{

}

Film* User::pointer_of_my_film(int _ID)
{
    for (int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _ID)
            return my_films[i];
    }
}

vector<User*> User::get_following()
{
    return my_following;
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

vector<User*> User::sort_following()
{
    vector<User*> temp;
    for(int i = 0 ; i<my_following.size() ; i++)
    {
        User* temper = my_following[i];
        for(int j=0 ; j<my_following.size(); j++)
        {
            if(temper->get_ID()>my_following[j]->get_ID())
                temper = my_following[j];
        }
        temp.push_back(temper);
    }
    return temp;
}


void User::add_following(User * add)
{
    my_following.push_back(add);
}

void User::add_comment(int _film_id, std::string _content)
{
    Comment temp(_content);

    Film* temper;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _film_id)
            temper = my_films[i];
    }

    temp.set_ID(temper->get_my_comments().size() + 1);
    temper->add_to_my_comment(temp);
}

void User::add_money(float _amount)
{
    money += _amount;
}

void User::add_score_to_a_film(int _film_id, float _score)
{
    Film* temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _film_id)
            temp = my_films[i];
    }
    temp->scores.push_back(_score);
}
