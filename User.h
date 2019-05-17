#ifndef PHASE_1_USER_H
#define PHASE_1_USER_H

#include "Header.h"
#include "Film.h"

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
    std::vector<User*> my_followers;

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
    std::vector<User*> get_followers();
    std::vector<User*> sort_followers();

};


#endif //PHASE_1_USER_H
