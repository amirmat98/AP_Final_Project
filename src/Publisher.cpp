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
    for(i = 0 ; i<my_published_films.size() ; i++)
    {
        if(my_published_films[i]->get_ID() == x)
            break;
    }
    my_published_films.erase(my_published_films.begin() + i);
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

vector<Film*> Publisher::sort_published_films()
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_published_films.size() ; i++)
    {
        Film* temper = my_published_films[i];
        for(int j = i ; j<my_published_films.size() ; j++)
        {
            if(temper->get_ID() > my_published_films[j]->get_ID())
                temper = my_published_films[j];
        }
        temp.push_back(temper);
    }
    return temp;
}

vector<Film*> Publisher::get_film()
{
    return my_published_films;
}

Film* Publisher::pointer_of_my_film(int _ID)
{
    for (int i = 0 ; i<my_published_films.size() ; i++)
    {
        if(my_published_films[i]->get_ID() == _ID)
            return my_published_films[i];
    }
}

void Publisher::print_my_film(std::string _name, int _min_rate, int _min_year , int _price , int _max_year, std::string _director)
{
    vector<Film*> sorted_my_published_films = this->sort_published_films();
    vector<Film*> temp;
    for(int i = 0 ; i<sorted_my_published_films.size() ; i++)
    {
        if( _name!="" && sorted_my_published_films[i]->get_name() != _name)
            continue;
        if (sorted_my_published_films[i]->get_rate() < _min_rate)
            continue;
        if(sorted_my_published_films[i]->get_year() < _min_year)
            continue;
        if(_price!=-1 && sorted_my_published_films[i]->get_price() != _price)
            continue;
        if(sorted_my_published_films[i]->get_year() > _max_year)
            continue;
        if(_director!="" && sorted_my_published_films[i]->get_director() != _director)
            continue;

        temp.push_back(sorted_my_published_films[i]);
    }

    cout<<"#. Film Id | Film Name | Film Length | Film price | Rate | Production Year | Film Director"<<endl;

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

    bool is_in_my_comment = false;
    for(int i = 0 ; i<temper->get_my_comments().size() ; i++)
    {
        if(temper->get_my_comments()[i].get_ID() == _comment_id)
            is_in_my_comment = true;
    }

    if(!is_in_my_comment)
        throw Find();

    Comment* temp;
    for(int i = 0 ; i<temper->get_my_comments().size() ; i++)
    {
        if(temper->get_my_comments()[i].get_ID() == _comment_id)
            temp = temper->pointer_to_comment(_comment_id);
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
    cout << "money is:" << money << endl;
    cout << "reserved is:" << reserved_money << endl;
    money += reserved_money;
}

void Publisher::send_published_film_message_for_followers()
{
    string temp_content = "register new film";
    for(int i = 0 ; i<my_followers.size() ; i++)
    {
        Message temp_message(this,my_followers[i],temp_content);
        my_followers[i]->add_message(temp_message);
    }
}

void Publisher::add_followers(User* add)
{
    my_followers.push_back(add);

}