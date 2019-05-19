#include "Comment.h"

using namespace std;

Comment::Comment(std::string _comment)
{
    my_comment = _comment;
}

string Comment::get_comment()
{
    return my_comment;
}

vector<string> Comment::get_replies()
{
    return my_replies;
}

int Comment::get_ID()
{
    return ID;
}

void Comment::add_reply(std::string _reply)
{
    my_replies.push_back(_reply);
}

void Comment::set_comment(std::string _comment)
{
    my_comment = _comment;
}

void Comment::set_ID(int _ID)
{
    ID = _ID;
}