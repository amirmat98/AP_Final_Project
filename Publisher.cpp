#include "Publisher.h"

using namespace std;

Publisher::Publisher(std::string _email, std::string _username, std::string _password ,int _age)
    :User(_email , _username , _password , _age)
{
}

void Publisher::add_in_my_films(Film* x)
{
    my_published_films.push_back(x);
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

vector<User*> Publisher::get_followers()
{
    return my_followers;
}

vector<User*> Publisher::sort_followers()
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
    for(int i = 0 ; i<my_published_films.size() ; i++)
    {
        if( _name!="" && my_published_films[i]->get_name() != _name)
            continue;
        if (my_published_films[i]->get_rate() < _min_rate)
            continue;
        if(my_published_films[i]->get_year() < _max_year)
            continue;
        if(_price!=-1 && my_published_films[i]->get_price() != _price)
            continue;
        if(my_published_films[i]->get_year() > _max_year)
            continue;
        if(_director!="" && my_published_films[i]->get_director() != _director)
            continue;

        temp.push_back(my_published_films[i]);
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

void Publisher::reply_to_comment(int _film_id, int _comment_id, std::string _content)
{
    Film* temper;
    for(int i = 0 ; i<my_published_films.size() ; i++)
    {
        if(my_published_films[i]->get_ID() == _film_id)
            temper = my_published_films[i];
    }

    Comment* temp;
    for(int i = 0 ; i<temper->get_my_comments().size() ; i++)
    {
        if(temper->get_my_comments()[i].get_ID() == _comment_id)
            temp = &temper->get_my_comments()[i];
    }

    temp->add_reply(_content);
}

void Publisher::delete_comment(int _film_id, int _comment_id)
{
    Film* temp;
    for(int i = 0 ; i<my_published_films.size() ; i++)
    {
        if(my_published_films[i]->get_ID() == _film_id)
            temp = my_published_films[i];
    }

    temp->delete_a_comment(_comment_id);
}

void Publisher::set_money(int _amount)
{
    reserved_money += _amount;
}

void Publisher::display_money()
{
    money += reserved_money;
}