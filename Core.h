#ifndef PHASE_1_CORE_H
#define PHASE_1_CORE_H

#include "Header.h"
#include "User.h"
#include "Publisher.h"
#include "Input_Handler.h"
#include "Film.h"
#include "Money_Handler.h"
#include "Parameter_Handler.h"
#include "Message.h"
#include "Film_Graph.h"

static void print_successfuly_message()
{
    std::cout<<"OK"<<std::endl;
}

class Input_Handler;
class Parameter_Handler;
class Money_Handler;
class Film_Graph;

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
    void buying_film(std::map<std::string,std::string> _parameter);
    void comment_film(std::map<std::string,std::string> _parameter);
    void purchased_film(std::map<std::string,std::string> _parameter);
    void notifications(std::map<std::string,std::string> _parameter);
    void add_score(std::map<std::string,std::string> _parameter);
    void add_money_to_account(float _amount);
    std::vector<User*> get_my_users();
    std::vector<Film*> get_my_films();
    void receive_money_from_core();
    void add_reply_to_comment(std::map<std::string,std::string> _parameter);
    void deleting_comment(std::map<std::string,std::string> _parameter);
    void adding_money(std::map<std::string,std::string> _parameter);
    void logout();

private:
    int number_of_users = 0;
    int number_of_films = 0;
    std::vector<User*> my_users;
    std::vector<Film*> my_films;
    Film* pointer_of_my_film(int _ID);
    std::vector<std::string> my_input_file;
    User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);
    user_type current_user ;
    //User* right_now_user;
    float account_money;
    void print_recommendation_films(Film* non_in_there);
    bool check_be_in_buy_film(int _film_id);
    std::vector<Film*> sort_rated_film();
    Film_Graph* my_graph;
    User* admin_user;




};



#endif //PHASE_1_CORE_H
