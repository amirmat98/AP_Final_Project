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
    void check_validate_user(Core* ccore , std::string& _username , std::string _password , User* _temp);

};


#endif //PHASE_1_PARAMETER_HANDLER_H
