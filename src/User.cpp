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

User::User()
{

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
    if(x == GUEST)
        my_type = GUEST;
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

vector<Film*> User::get_buy_film()
{
    return my_films;
}

void User::add_buy_film(Film *temp)
{
    my_films.push_back(temp);
}

void User::print_purchased_film(std::string _name, int _min_year, int _max_year, std::string _director)
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if( _name!="" && my_films[i]->get_name() != _name)
            continue;
        if(my_films[i]->get_year() < _min_year)
            continue;
        if(my_films[i]->get_year() > _max_year)
            continue;
        if(_director!="" && my_films[i]->get_director() != _director)
            continue;
        //my_core->make_home_page_films(my_films[i]);
        temp.push_back(my_films[i]);
        profile_page_films.push_back(my_films[i]);
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

void User::print_my_film(std::string _name, int _min_rate, int _min_year, int _price, int _max_year,
                         std::string _director)
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if( _name!="" && my_films[i]->get_name() != _name)
            continue;
        if (my_films[i]->get_rate() < _min_rate)
            continue;
        if(my_films[i]->get_year() < _min_year)
            continue;
        if(_price!=-1 && my_films[i]->get_price() != _price)
            continue;
        if(my_films[i]->get_year() > _max_year)
            continue;
        if(_director!="" && my_films[i]->get_director() != _director)
            continue;

        temp.push_back(my_films[i]);
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
    this->send_following_message(add);
}

void User::add_comment(int _film_id, std::string _content)
{
    Comment temp (_content , this);

    Film* temper;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _film_id)
            temper = my_films[i];
    }
    temper->number_of_comments++;
    temp.set_ID(temper->number_of_comments);
    temper->add_to_my_comment(temp);
    string temp_content = "comment on your film " + temper->get_name() + " with id " + to_string(temper->get_ID());
    Message temp_message (this,temper->get_publisher(),temp_content);
    temper->get_publisher()->add_message(temp_message);
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
    temp->calculate_score();
}

void User::add_message(Message _temp)
{
    inbox.push_back(_temp);
}

void User::print_unread_message()
{
    cout<<"#"<<"."<<" "<<"Notification Message"<<endl;
    for(int i = 0 ; i<inbox.size() ;i++)
    {
        if(!inbox[inbox.size() -1 -i].get_state())
            continue;
        cout<<i+1;
        cout<<".";
        cout<<" ";
        inbox[inbox.size() -1 -i].print();
        cout<<endl;
    }
}

void User::print_read_message(int _limit)
{
    int indexer = 0;
    cout<<"#"<<"."<<" "<<"Notification Message"<<endl;
    for(int i = 0 ; i<inbox.size() ;i++)
    {
        if(indexer>_limit)
            break;
        if(inbox[inbox.size() -1 -i].get_state())
            continue;
        cout<<indexer+1;
        cout<<".";
        cout<<" ";
        inbox[inbox.size() -1 -i].print();
        cout<<endl;
        indexer++;
    }
}

void User::set_money(int _amount)
{
    cout<<"mon is:"<<money<<endl;
    cout << "amon is:" << _amount << endl;
    money -= _amount;
}

void User::send_following_message(User* _receiver)
{
    string temp_content = "follow you";
    Message temp_message(this , _receiver , temp_content);
    _receiver->add_message(temp_message);
}

void User::get_amount_of_money()
{
    cout<<int(money)<<endl;
}

int User::get_money()
{
    return int(money);
}

bool User::is_in_my_purchased(Film* x)
{
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(x == my_films[i])
            return true;
    }
    return false;
}