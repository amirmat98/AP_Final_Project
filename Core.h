#ifndef PHASE_1_CORE_H
#define PHASE_1_CORE_H

#include "Header.h"
#include "User.h"
#include "Publisher.h"
#include "Input_Handler.h"
#include "Film.h"
#include "Money_Handler.h"
#include "Parameter_Handler.h"

static void print_successfuly_message()
{
    std::cout<<"OK"<<std::endl;
}

class Input_Handler;
class Parameter_Handler;
class Money_Handler;

class Core
{

public:
    Core();
    Input_Handler* my_input_handler;
    Parameter_Handler* param;
    std::vector<std::string> get_my_input_file();
    void main();
    void handel();
    order_type right_now_order_type;
    void set_right_now_order_type(std::string);
    void set_right_now_order(std::string);
    void set_right_now_parameter(std::map<std::string,std::string>);
    std::string right_now_order;
    std::map< std::string , std::string > right_now_parameter;
    User* right_now_user;

    void sign_up(std::map< std::string , std::string >);
    void login(std::map< std::string , std::string >);
    void add_film(std::map< std::string , std::string >);
    void modify_film(std::map< std::string , std::string >);
    void delete_film(std::map< std::string , std::string >);
    void get_followers();
    void get_published_film(std::map< std::string , std::string >);
    void add_following(std::map<std::string,std::string>);
    void search_in_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            , int _price = -1 ,  int _max_year = 100000 , std::string _director = "" );

    void get_search_films(std::map<std::string, std::string> _parameter);
    void add_score(std::map<std::string,std::string> _parameter);
    void add_money_to_account(float _amount);
    std::vector<User*> get_my_users();


private:
    int number_of_users = 0;
    int number_of_films = 0;
    std::vector<User*> my_users;
    std::vector<Film*> my_films;
    std::vector<std::string> my_input_file;
    User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);
    user_type current_user ;
    //User* right_now_user;
    float account_money;




};



#endif //PHASE_1_CORE_H
