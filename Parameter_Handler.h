#ifndef PHASE_1_PARAMETER_HANDLER_H
#define PHASE_1_PARAMETER_HANDLER_H

#include "Header.h"
#include "Core.h"

class Core;

class Parameter_Handler
{
public:
    Parameter_Handler();

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

};


#endif //PHASE_1_PARAMETER_HANDLER_H
