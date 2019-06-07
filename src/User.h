#ifndef PHASE_1_USER_H
#define PHASE_1_USER_H

#include "Header.h"
#include "Film.h"
#include "Comment.h"
#include "Message.h"
//#include "Core.h"

class Film;
class Message;
//class Core;

class User
{

protected:
    std::string username;
    std::string email;
    std::string password;
    int ID;
    int age;
    user_type my_type;
    std::vector<Film*> my_films;
    std::vector<User*> my_following;
    float money = 0;
    std::vector<Message> inbox;


public:
    User(std::string, std::string, std::string , int);
    User();
    //Core* my_core;
    //User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);

    std::vector<Film*> profile_page_films;    
    user_type get_my_type();
    std::string get_username();
    std::string get_password();
    int get_ID();
    std::string get_email();

    void set_type(user_type);
    void set_ID(int _id);

    virtual void set_in_my_films(Film& x);
    virtual void add_in_my_films(Film* x);
    virtual void delete_in_my_films(int x);
    virtual Film* pointer_of_my_film(int _ID);
    virtual std::vector<Film*> get_film();
    std::vector<Film*> get_buy_film();


    void print();
    std::vector<User*> get_following();
    std::vector<User*> sort_following();
    void add_following(User*);
    void add_comment(int _film_id , std::string _content);

    virtual void print_my_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            , int _price = -1 ,  int _max_year = 100000 , std::string _director = "" ) ;


    void print_purchased_film(std::string _name = "" , int _min_year = 0
            , int _max_year = 100000 , std::string _director = "");
    void add_money(float _amount);
    virtual void set_money(int _amount);

    void add_score_to_a_film(int _film_id , float _score);

    void add_buy_film(Film* temp);

    void search_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            , int _price = -1 ,  int _max_year = 100000 , std::string _director = "" );

    void add_message(Message _temp);
    void print_unread_message();
    void print_read_message(int _limit);
    void send_following_message(User* _receiver);
    void get_amount_of_money();
    int get_money();

};


#endif //PHASE_1_USER_H
