#ifndef PHASE_1_MESSAGE_H
#define PHASE_1_MESSAGE_H

#include "Header.h"
#include "User.h"

class User;

class Message
{
private:
    User* sender;
    User* receiver;
    std::string content;
    bool unread;

public:
    Message(User* , User*, std::string _content);
    Message(User*,std::string _content);
    void print();
    bool get_state();
    void set_receiver(User* _receiver);
};


#endif //PHASE_1_MESSAGE_H
