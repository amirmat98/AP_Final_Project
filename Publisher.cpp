#include "Publisher.h"

using namespace std;

Publisher::Publisher(std::string _email, std::string _username, std::string _password ,int _age)
    :User(_email , _username , _password , _age)
{
}

void Publisher::add_in_my_films(Film* x)
{
    my_films.push_back(x);
}

void Publisher::set_in_my_films(Film &x)
{
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == x.get_ID())
        {
            my_films[i] = &x;
        }
    }
}

void Publisher::delete_in_my_films(int x)
{
    int i = 0;
    for(i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == x)
            break;
    }
    my_films.erase(my_films.begin() + i);
}

vector<Film*> Publisher::get_film()
{
    return my_films;
}

Film* Publisher::pointer_of_my_film(int _ID)
{
    for (int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _ID)
            return my_films[i];
    }
}

void Publisher::print_my_film(std::string _name, int _min_rate, int _min_year , int _price , int _max_year, std::string _director)
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_name() == _name)
            continue;
        if (my_films[i]->get_rate() < _min_rate)
            continue;
        if(my_films[i]->get_year() < _max_year)
            continue;
        if(_price!=-1 && my_films[i]->get_price() != _price)
            continue;
        if(my_films[i]->get_year() > _max_year)
            continue;
        if(my_films[i]->get_director() != _director)
            continue;

        temp.push_back(my_films[i]);
    }

    for(int i = 0 ; i<temp.size() ; i++)
    {
        cout<<i+1;
        cout<<".";
        cout<<" ";
        temp[i]->print_film();
        cout<<endl;
    }
}
