#ifndef PHASE_1_USER_H
#define PHASE_1_USER_H

#include "Header.h"
#include "Film.h"
#include "Comment.h"

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
    float money;


public:
    User(std::string, std::string, std::string , int);
    //User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);

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


    void print();
    std::vector<User*> get_following();
    std::vector<User*> sort_following();
    void add_following(User*);
    void add_comment(int _film_id , std::string _content);

    virtual void print_my_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            , int _price = -1 ,  int _max_year = 100000 , std::string _director = "" ) ;

    void add_money(float _amount);

    void add_score_to_a_film(int _film_id , float _score);

    void search_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            , int _price = -1 ,  int _max_year = 100000 , std::string _director = "" );

};


#endif //PHASE_1_USER_H
