#ifndef PHASE_1_PARAMETER_HANDLER_H
#define PHASE_1_PARAMETER_HANDLER_H

#include "Header.h"
#include "Core.h"

class Core;

class Parameter_Handler
{
public:
    Parameter_Handler();

    void handler_content_of_message_for_reply(std::string& _content_message);

    ///sign up///
    void handler_sign_up(std::map<std::string,std::string>& _parameter ,
            std::string& _email , std::string& _username , std::string& _password ,
            int& _age , bool& _is_publisher);
    void check_validate_username(Core* ccore ,std::string _username);

    ///login///
    void handler_loging(std::map<std::string,std::string>& _parameter ,
                        std::string& _username , std::string& _password);
    void check_validate_user(Core* ccore , std::string& _username , std::string _password , User*& _temp);

    ///publisher add film///

    void handler_add_film(std::map<std::string, std::string>& _parameter,
                          std::string& _name , int& _year , int& _length , int& _price,
                          std::string& _summary , std::string& _director);

    ///publisher modify film///
    void handler_modify_film(std::map<std::string,std::string> _parameter,
            Film*& _temp);

    ///publisher delete film///
    void handler_delete_film(std::map<std::string, std::string> _parameter , int& _film_id);
    void check_validate_film_for_delete(Core* ccore , int _film_id);

    ///print published films///
    void handler_print_published_film(std::map<std::string, std::string> _parameter , std::string& _name ,
            float& _min_rate , int& _min_year , int& _price , int& _max_year,
            std::string& _director);

    ///add reply to comment///
    void handler_add_reply(Core* ccore , std::map<std::string, std::string> _parameter , int& _film_id , int& _comment_id ,
            std::string _content);

    ///delete comment///
    void handler_delete_comment(Core* ccore , std::map<std::string, std::string> _parameter , int& _film_id , int& _comment_id);

    ///search///
    void handler_search_film(Core* ccore ,std::map<std::string, std::string> _parameter , std::string& _name ,
            float& _min_rate , int& _min_year , int& _price , int& _max_year,
            std::string& _director );

    ///buying film///
    void handler_buying_film(Core* ccore , std::map<std::string,std::string> _parameter , int& _film_id);

    ///rating film///
    void handler_rating_film(Core* ccore , std::map<std::string,std::string> _parameter , int& _film_id , float& _score);

    ///comment film///
    void handler_comment_film(Core* ccore , std::map<std::string,std::string> _parameter , int& _film_id , std::string& _content);

    ///purchased film////
    void handler_purchased_film(std::map<std::string, std::string> _parameter , std::string& _name ,
                                int& _min_year , int& _max_year,
                                std::string& _director);
};


#endif //PHASE_1_PARAMETER_HANDLER_H
