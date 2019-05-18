#ifndef PHASE_1_CORE_H
#define PHASE_1_CORE_H

#include "Header.h"
#include "User.h"
#include "Publisher.h"
#include "Input_Handler.h"
#include "Film.h"

class Input_Handler;

class Core
{

public:
    Core();
    Input_Handler* my_input_handler;
    std::vector<std::string> get_my_input_file();
    void main();
    void handel();
    order_type right_now_order_type;
    void set_right_now_order_type(std::string);
    void set_right_now_order(std::string);
    void set_right_now_parameter(std::map<std::string,std::string>);
    std::string right_now_order;
    std::map< std::string , std::string > right_now_parameter;


    void sign_up(std::map< std::string , std::string >);
    void login(std::map< std::string , std::string >);
    void add_film(std::map< std::string , std::string >);
    void modify_film(std::map< std::string , std::string >);
    void delete_film(std::map< std::string , std::string >);
    void get_followers();
    void get_published_film(std::map< std::string , std::string >);
    void add_following(std::map<std::string,std::string>);



private:
    std::vector<User*> my_users;
    std::vector<Film*> my_films;
    std::vector<std::string> my_input_file;
    User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);
    user_type current_user ;
    User* right_now_user;




};


#endif //PHASE_1_CORE_H
