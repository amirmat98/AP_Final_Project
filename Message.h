#ifndef PHASE_1_MESSAGE_H
#define PHASE_1_MESSAGE_H

#include "Header.h"
#include "User.h"

class Message
{
private:
    User* sender;
    User* receiver;
    std::string content;
    bool unread;

public:
    Message(User* _sender , User* _receiver , std::string _content);
    void print();
    bool get_state();
};


#endif //PHASE_1_MESSAGE_H
