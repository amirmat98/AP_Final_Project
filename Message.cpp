#include "Message.h"

using namespace std;

Message::Message(User *_sender, User *_receiver, std::string _content)
{
    sender = _sender;
    receiver = _receiver;
    content = _content;
    unread = true;
}

Message::Message(User * _sender, std::string _content)
{
    sender = _sender;
    content = _content;
    unread = true;
}

void Message::print()
{
    unread = false;

    cout<<sender->get_my_type();
    cout<<" ";
    cout<<sender->get_username();
    cout<<" ";
    cout<<"with";
    cout<<" ";
    cout<<"id";
    cout<<" ";
    cout<<sender->get_ID();
    cout<<" ";
    cout<<content;
    cout<<".";

}

bool Message::get_state()
{
    return unread;
}

void Message::set_receiver(User *_receiver)
{
    receiver = _receiver;
}
