#include "Publisher.h"

using namespace std;

Publisher::Publisher(std::string _email, std::string _username, std::string _password ,int _age)
    :Customer(_email , _username , _password , _age)
{
    cout<<"Publisher"<<endl;
}
