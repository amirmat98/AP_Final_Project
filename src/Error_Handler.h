#ifndef PHASE_1_ERROR_HANDLER_H
#define PHASE_1_ERROR_HANDLER_H

#include "Header.h"
#include <exception>

class Find : public std::exception
{
public:
    const char* what() const throw();
};

class BadRequest : public std::exception
{
public:
    const char* what() const throw();
};

class Permission : public std::exception
{
public:
    const char* what() const throw();
};





#endif //PHASE_1_ERROR_HANDLER_H
