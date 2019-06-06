#include "Core.h"

using namespace std;

Core::Core()
{
    //my_input_file = my_file;
    current_user = GUEST;
    right_now_user = new User();
    right_now_user->set_type(GUEST);
    my_graph = new Film_Graph();
    make_admin();
    param = new Parameter_Handler();
}

void Core::main()
{
    while (cin)
    {
        cout<<"while"<<endl;
        my_input_handler = new Input_Handler(this);
        //my_input_handler->run();
        try
        {
            my_input_handler->run();
        }
        catch (exception& ex)
        {
            cout<<ex.what()<<endl;
        }
        handel();
        my_graph->update(this);
        cout<<"-----"<<endl;
    }
    cout<<endl;
}

void Core::handel()
{
    if(right_now_order_type == POST)
    {
        if(right_now_order == "signup")
        {
            try
            {
                sign_up(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }
        }
        if(right_now_order == "login")
        {
            try
            {
                login(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }
        }
        if(right_now_order == "logout")
        {
            try
            {
                logout();
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "films")
        {
            try
            {
                add_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "put_films")
        {
            try
            {
                modify_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "delete_films")
        {
            delete_film(right_now_parameter);
        }
        if(right_now_order == "followers")
        {
            try
            {
                add_following(right_now_parameter);
            }

            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }

        if(right_now_order == "delete_comments")
        {
            try
            {
                deleting_comment(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }
        }

        if(right_now_order == "money")
        {
            try
            {

                if(right_now_user->get_my_type() == PUBLISHER)
                    receive_money_from_core();
                adding_money(right_now_parameter);

            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
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
                cout<<ex.what()<<endl;
            }
        }
        if(right_now_order == "buy")
        {
            try
            {
                buying_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "rate")
        {
            try
            {
                add_score(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "comments")
        {
            try
            {
                comment_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
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
                cout<<ex.what()<<endl;
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
                cout<<ex.what()<<endl;
            }
        }
        if(right_now_order == "films")
        {
            try
            {
                get_search_films(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }
        }
        if(right_now_order == "purchased")
        {
            try
            {
                purchased_film(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "notifications")
        {
            try
            {
                notifications(right_now_parameter);
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
            }

        }
        if(right_now_order == "money")
        {
            try
            {
                get_money_of_user();
            }
            catch (exception& ex)
            {
                cout<<ex.what()<<endl;
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
    /*else if (temp == "PUT")
        right_now_order_type = PUT;*/
    /*else if (temp == "DELETE")
        right_now_order_type = DELETE;*/
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
        if(right_now_user->get_my_type() != GUEST)
            throw BadRequest();
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
        cout<<ex.what()<<endl;
    }

}

void Core::login(std::map<std::string, std::string> _parameter)
{
    try
    {
        if(right_now_user->get_my_type() != GUEST)
            throw BadRequest();
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
        cout<<ex.what()<<endl;
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
    my_graph->update(this);
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
        cout<<ex.what()<<endl;
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

void Core::purchased_film(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    string _name , _director;
    int _min_year , _max_year ;
    param->handler_purchased_film(_parameter,_name,_min_year,_max_year,_director);
    right_now_user->print_purchased_film(_name,_min_year,_max_year,_director);

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
        Film* temp_film = pointer_of_my_film(_film_id);
        Comment* temper_comment = temp_film->pointer_to_comment(_comment_id);
        User * temp_receiver =  temper_comment->get_sender();
        Message temp_message(right_now_user , temp_receiver , message_content);
        temp_receiver->add_message(temp_message);
        print_successfuly_message();
    }
    catch (exception& ex)
    {
        cout<<ex.what()<<endl;
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
        cout<<ex.what()<<endl;
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
    my_graph->update(this);
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();

    map<string,string>::iterator it = _parameter.find("film_id");

    if(it == _parameter.end())
    {
        string _name, _director;
        float _min_rate;
        int _min_year, _price, _max_year;
        param->handler_search_film(this, _parameter, _name, _min_rate, _min_year, _price, _max_year, _director);
        cout<<"max year filterd is:"<<_max_year<<endl;
        search_in_film(_name, _min_rate, _min_year, _price, _max_year, _director);
    }
    if(it != _parameter.end())
    {
        bool is_in_film = false;
        for(int i = 0 ; i<my_films.size() ; i++)
        {
            if(my_films[i]->get_ID() == stoi(it->second))
                is_in_film = true;
        }
        if(!is_in_film)
            throw Find();

        Film* temp_film;
        for(int i = 0 ; i<my_films.size() ; i++)
        {
            if(my_films[i]->get_ID() == stoi(it->second))
                temp_film = my_films[i];
        }

        temp_film->print_detailed_film();
        cout<<endl;
        temp_film->print_all_comment();
        cout<<endl;
        print_recommendation_films(temp_film);
    }
}

bool Core::check_be_in_buy_film(int _film_id)
{
    for(int i = 0 ; i<right_now_user->get_film().size() ; i++)
    {
        if(right_now_user->get_film()[i]->get_ID() == _film_id)
            return true;
    }
    return false;
}

void Core::print_recommendation_films(Film* non_in_there)
{
    cout<<"Recommendation Film"<<endl;

    vector<Film*> temp_films;
    my_graph->recommendation_film_from_graph(non_in_there,temp_films);

    cout<<"#. Film Id | Film Name | Film Length | Film Director"<<endl;

    int index = 0;
    for(int i = 0 ; i<temp_films.size() ; i++)
    {
        if(index>=4)
            break;
        if(check_be_in_buy_film(temp_films[i]->get_ID()))
            continue;
        if(temp_films[i] == non_in_there)
            continue;
        index++;
        cout<<index;
        cout<<".";
        cout<<" ";
        temp_films[i]->print_recom_film();
        cout<<endl;
    }

}

vector<Film*> Core::sort_rated_film()
{
    vector<Film*> temp;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        Film* temper = my_films[i];
        for(int j = i ; j < my_films.size() ; j++)
        {
            if(my_films[j]->get_rate() > temper->get_rate())
            {
                temper = my_films[j];
            }
        }
        temp.push_back(temper);
    }
    return temp;
}

void Core::search_in_film(std::string _name, int _min_rate, int _min_year, int _price, int _max_year,
                       std::string _director)
{
    home_page_films.clear();
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
        cout<<"it's over"<<endl;
        make_home_page_films(my_films[i]);
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

void Core::buying_film(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    int _film_id;
    param->handler_buying_film(this , _parameter , _film_id);
    Film* temp_buying_film;
    for(int i = 0 ; i<my_films.size() ; i++)
    {
        if(my_films[i]->get_ID() == _film_id)
            temp_buying_film = my_films[i];
    }
    Money_Handler* my_money_handler = new Money_Handler(this, temp_buying_film);
    my_money_handler->run();
    temp_buying_film->add_buyer(right_now_user);
    right_now_user->add_buy_film(temp_buying_film);
    string temp_content = "buy your film "+temp_buying_film->get_name()+ " with id " + to_string(temp_buying_film->get_ID());
    Message temp_message(right_now_user,temp_buying_film->get_publisher(), temp_content);
    temp_buying_film->get_publisher()->add_message(temp_message);
    print_successfuly_message();
}

void Core::add_score(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    int _film_id;
    float _score;

    param->handler_rating_film(this , _parameter , _film_id , _score);
    Film* temp_film = pointer_of_my_film(_film_id);
    string temp_content = "rate your film " + temp_film->get_name() + " with id " + to_string(temp_film->get_ID());
    Message temp_message(right_now_user,temp_film->get_publisher(),temp_content);
    temp_film->get_publisher()->add_message(temp_message);
    right_now_user->add_score_to_a_film(_film_id,_score);
    print_successfuly_message();


}

void Core::comment_film(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    int _film_id;
    string _content;
    param->handler_comment_film(this , _parameter , _film_id , _content);
    right_now_user->add_comment(_film_id,_content);
    print_successfuly_message();
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
    //print_successfuly_message();
}

void Core::adding_money(std::map<std::string, std::string> _parameter)
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    map<string,string>::iterator it;
    float _amount = 0;
    it = _parameter.find("amount");
    if(it != _parameter.end())
        _amount = stof(it->second);
    right_now_user->add_money(_amount);
    print_successfuly_message();
}

void Core::notifications(std::map<std::string, std::string> _parameter)
{
    map<string,string>::iterator it;
    it = _parameter.find("limit");

    if(it == _parameter.end())
    {
        right_now_user->print_unread_message();
    }
    if(it != _parameter.end())
    {
        right_now_user->print_read_message(stoi(it->second));
    }
}

void Core::logout()
{
    if(right_now_user->get_my_type() == GUEST)
        throw BadRequest();

    right_now_user = new User();
    right_now_user->set_type(GUEST);
    print_successfuly_message();


}

void Core::get_money_of_user()
{
    if(right_now_user->get_my_type() == GUEST)
        throw Permission();
    if(right_now_user == get_admin_user())
        get_money_of_core();
    else
        right_now_user->get_amount_of_money();
}

void Core::make_admin()
{
    admin_user = new User("admin@admin.com" , "admin" , "admin" , 0 );
    admin_user->set_ID(0);
    my_users.push_back(admin_user);
}

User* Core::get_admin_user()
{
    return admin_user;
}

void Core::get_money_of_core()
{
    cout<<int(account_money)<<endl;
}

void Core::cout_users()
{
    cout<<"-------"<<endl;
    for(int i = 0 ; i<my_users.size() ; i++)
    {
        my_users[i]->print();
        cout<<endl;
    }
    cout << "-------" << endl;
}

std::map<std::string, std::string> Core::get_home_page_films()
{
    return home_page_films;
}

void Core::make_str_for_home_page_films(Film* x , bool candelete)
{
    string temp = x->get_name() + "|" + to_string(x->get_length()) + "|" +
                  to_string(x->get_price()) + "|" + to_string(x->get_rate()) +
                  "|" + to_string(x->get_year()) + "|" + x->get_director() + "|";
    
    if(candelete)
        home_page_films[to_string(x->get_ID())] = temp + "candelete|";
    else
        home_page_films[to_string(x->get_ID())] = temp;
}

void Core::make_home_page_films(Film* x)
{
    if(right_now_user->get_my_type() == CUSTOMER)
    {
        if(right_now_user->get_money() > x->get_price())
        {
            make_str_for_home_page_films(x,false);
        }
    }
    if(right_now_user->get_my_type() == PUBLISHER)
    {
        if(x->get_publisher() == right_now_user)
        {
            make_str_for_home_page_films(x, true);
        }
        else
        {
            if (right_now_user->get_money() > x->get_price())
            {
                make_str_for_home_page_films(x, false);
            }
        }
        
    }
}