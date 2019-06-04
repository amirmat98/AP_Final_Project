#ifndef PHASE_1_COMMENT_H
#define PHASE_1_COMMENT_H

#include "Header.h"
#include "Film.h"
#include "User.h"

class User;

class Comment
{

private:
    User* sender;
    std::string my_comment;
    std::vector <std::string> my_replies;
    int ID;

public:
    Comment(std::string _comment , User*);
    std::string get_comment();
    User* get_sender();
    std::vector <std::string> get_replies();
    int get_ID();
    void add_reply(std::string _reply);
    void set_comment(std::string _comment);
    void set_ID(int _ID);

};


#endif //PHASE_1_COMMENT_H
