#ifndef PHASE_1_USER_H
#define PHASE_1_USER_H

#include "Header.h"



class User
{

protected:
    std::string username;
    std::string email;
    std::string password;
    int ID;
    int age;
    user_type my_type;

public:
    User(std::string, std::string, std::string , int);
    //User* add_user(std::string, std::string, std::string , int , bool is_publisher = false);
    user_type get_my_type();
    std::string get_username();
    std::string get_password();
    void set_type(user_type);
    void set_ID(int _id);

};


#endif //PHASE_1_USER_H
