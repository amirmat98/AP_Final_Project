#include "Error_Handler.h"

using namespace std;

const char* Find::what() const throw()
{
    return "Not Found";
}

const char* Request::what() const throw()
{
    return "Bad Request";
}

const char* Permission::what() const throw()
{
    return "Permission Denied";
}
