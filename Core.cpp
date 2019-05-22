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
        param = new Parameter_Handler();
        handel();
        cout<<"-----"<<endl;
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
        if(right_now_order == "films")
        {
            try
            {
                add_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }

        }
        if(right_now_order == "followers")
        {
            add_following(right_now_parameter);
        }

        if(right_now_order == "money")
        {
            try
            {
                receive_money_from_core();
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }
        }
        if(right_now_order == "replies")
        {
            try
            {
                add_reply_to_comment(right_now_parameter);
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }
        }
    }
    else if(right_now_order_type == PUT)
    {
        if(right_now_order == "films")
        {
            try
            {
                modify_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }

        }
    }
    else if (right_now_order_type == DELETE)
    {
        if(right_now_order == "films")
        {
            delete_film(right_now_parameter);
        }
        if(right_now_order == "comments")
        {
            try
            {
                deleting_comment(right_now_parameter);
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }
        }
    }
    else if (right_now_order_type == GET)
    {
        if(right_now_order == "followers")
        {
            try
            {
                get_followers();
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }
        }
        if(right_now_order == "published")
        {
            try
            {
                get_published_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cerr<<ex.what()<<endl;
            }
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
    try
    {
        string _email, _username, _password;
        int _age;
        bool _is_publisher = false;
        param->handler_sign_up(_parameter, _email, _username, _password, _age, _is_publisher);
        param->check_validate_username(this,_username);
        User *temp;
        temp = add_user(_email, _username, _password, _age, _is_publisher);
        number_of_users++;
        temp->set_ID(number_of_users);
        my_users.push_back(temp);
        current_user = temp->get_my_type();
        right_now_user = temp;
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cerr<<ex.what()<<endl;
    }

}

void Core::login(std::map<std::string, std::string> _parameter)
{
    try
    {
        string _username, _password;
        param->handler_loging(_parameter, _username, _password);
        User *temp;
        param->check_validate_user(this, _username, _password, temp);
        current_user = temp->get_my_type();
        right_now_user = temp;
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cerr<<ex.what()<<endl;
    }

}

void Core::add_film(std::map<std::string, std::string> _parameter)
{

    if(right_now_user->get_my_type() != PUBLISHER)
        throw Permission();

    string _name , _summary , _director ;
    int _year , _length , _price ;
    param->handler_add_film(_parameter , _name , _year , _length , _price , _summary , _director);
    Film* temp = new Film(_name , _year , _length , _price , _summary , _director);
    number_of_films++;
    temp->set_ID(number_of_films);
    temp->set_publisher(right_now_user);
    right_now_user->add_in_my_films(temp);
    my_films.push_back(right_now_user->pointer_of_my_film(temp->get_ID()));
    Publisher* temp_publisher = dynamic_cast<Publisher*>(right_now_user);
    temp_publisher->send_published_film_message_for_followers();
    print_successfuly_message();

}

void Core::modify_film(std::map<std::string, std::string> _parameter)
{

    map<string,string>::iterator it;
    it = _parameter.find("film_id");
    //Film* temp = right_now_user->pointer_of_my_film(stoi(it->second));
    Film* temp = pointer_of_my_film(stoi(it->second));
    if(temp->get_publisher() != right_now_user)
        throw Permission();

    param->handler_modify_film(_parameter,temp);

    print_successfuly_message();
}

void Core::delete_film(std::map<std::string, std::string> _parameter)
{
    try
    {
        int _film_id;
        param->handler_delete_film(_parameter, _film_id);
        param->check_validate_film_for_delete(this, _film_id);
        right_now_user->delete_in_my_films(_film_id);
        my_films.erase(my_films.begin() + _film_id - 1);
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cerr<<ex.what()<<endl;
    }

}

User* Core::add_user(std::string _email, std::string _username, std::string _password, int _age , bool is_publisher)
{
    if (is_publisher)
    {
        User* temp = new Publisher(_email , _username , _password , _age);
        temp ->set_type(PUBLISHER);
        /*User* temp = (User * ) new Publisher(_email, _username, _password , _age);
        temp->set_type(PUBLISHER);*/
    }
    else
    {
        User* temp = new User(_email , _username , _password , _age);
        temp->set_type(CUSTOMER);
    }
}

void Core::get_followers()
{
    if(right_now_user->get_my_type() != PUBLISHER)
        throw Permission();

    Publisher* temp_user = dynamic_cast <Publisher*> (right_now_user);
    vector<User*> temp = temp_user->sort_followers();

    cout<<"List of Followers"<<endl;
    cout<<"#"<<"."<<" "<<"User Id"<<" | "<<"User Username"<<" | "<<"User Email"<<endl;

    for(int i = 0 ; i<temp_user->get_followers().size() ; i++)
    {
        cout<<i+1;
        cout<<".";
        cout<<" ";
        temp[i]->print();
        cout<<endl;
    }
}

void Core::get_published_film(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() != PUBLISHER)
        throw Permission();
    string _name , _director;
    float _min_rate;
    int _min_year , _price , _max_year ;
    param->handler_print_published_film(_parameter , _name , _min_rate , _min_year , _price , _max_year , _director);
    right_now_user->print_my_film(_name , _min_rate , _min_year , _price , _max_year , _director);
    //print_successfuly_message();

}

void Core::add_reply_to_comment(std::map<std::string, std::string> _parameter)
{
    try
    {
        if(right_now_user->get_my_type() != PUBLISHER)
            throw Permission();
        int _film_id, _comment_id;
        string _content;
        param->handler_add_reply(this, _parameter, _film_id, _comment_id, _content);
        Publisher* temp_user = dynamic_cast<Publisher*>(right_now_user);
        temp_user->reply_to_comment(_film_id,_comment_id,_content);
        string message_content;
        param->handler_content_of_message_for_reply(message_content);
        User * temp_receiver =  my_films[_film_id]->get_my_comments()[_comment_id].get_sender();
        Message temp_message(right_now_user , temp_receiver , message_content);
        my_films[_film_id]->get_my_comments()[_comment_id].get_sender()->add_message(temp_message);
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cerr<<ex.what()<<endl;
    }


}

void Core::deleting_comment(std::map<std::string, std::string> _parameter)
{
    try
    {
        if(right_now_user->get_my_type() != PUBLISHER)
            throw Permission();
        int _film_id, _comment_id;
        param->handler_delete_comment(this, _parameter ,_film_id, _comment_id);
        Publisher* temp_user = dynamic_cast<Publisher*> (right_now_user);
        temp_user->delete_comment(_film_id,_comment_id);
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cerr<<ex.what()<<endl;
    }
}

void Core::add_following(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();

    map<string,string>::iterator it;
    it = _parameter.find("user_id");
    User* temp;
    for(int i = 0 ; i<my_users.size() ; i++)
    {
        if(my_users[i]->get_ID() == stoi(it->second))
            temp = my_users[i];
    }
    right_now_user->add_following(temp);

    Publisher* temp_publisher = dynamic_cast<Publisher*>(temp);
    temp_publisher->add_followers(right_now_user);
    print_successfuly_message();
}

void Core::get_search_films(std::map<std::string, std::string> _parameter)
{
    map<string,string>::iterator it;

    it = _parameter.find("name");
    string _name = "";
    if(it != _parameter.end())
        _name = it->second;

    it = _parameter.find("min_rate");
    int _min_rate = 0 ;
    if(it != _parameter.end())
        _min_rate = stoi(it->second);

    it = _parameter.find("min_year");
    int _min_year = 0;
    if(it != _parameter.end())
        _min_year = stoi(it->second);

    it = _parameter.find("price");
    int _price = -1;
    if(it != _parameter.end())
        _price = stoi(it->second);

    it = _parameter.find("max_year");
    int _max_year = 100000;
    if(it != _parameter.end())
        _max_year = stoi(it->second);

    it = _parameter.find("director");
    string _director = "";
    if(it != _parameter.end())
        _director = it->second;

    search_in_film(_name,_min_rate,_min_year,_price,_max_year,_director);
}

void Core::search_in_film(std::string _name, int _min_rate, int _min_year, int _price, int _max_year,
                       std::string _director)
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if( _name!="" && my_films[i]->get_name() != _name)
            continue;
        if (my_films[i]->get_rate() < _min_rate)
            continue;
        if(my_films[i]->get_year() < _max_year)
            continue;
        if(_price!=-1 && my_films[i]->get_price() != _price)
            continue;
        if(my_films[i]->get_year() > _max_year)
            continue;
        if(_director!="" && my_films[i]->get_director() != _director)
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

void Core::add_score(std::map<std::string, std::string> _parameter)
{
    map<string,string>::iterator it;

    int _film_id;
    it = _parameter.find("film_id");
    _film_id = stoi(it->second);

    float _score;
    it = _parameter.find("score");
    _score = stof(it->second);

    right_now_user->add_score_to_a_film(_film_id,_score);



}

void Core::add_money_to_account(float _amount)
{
    account_money += _amount;
}

std::vector<User*> Core::get_my_users()
{
    return my_users;
}

Film* Core::pointer_of_my_film(int _ID)
{
    for (int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _ID)
            return my_films[i];
    }

}

std::vector<Film*> Core::get_my_films()
{
    return my_films;
}

void Core::receive_money_from_core()
{
    if(right_now_user->get_my_type() != PUBLISHER)
        throw Permission();

    Publisher* temp = dynamic_cast<Publisher*> (right_now_user);
    temp->display_money();
    print_successfuly_message();
}