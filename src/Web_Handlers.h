#ifndef _MY_HANDLERS_
#define _MY_HANDLERS_

#include "../server/server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

/*class RandomNumberHandler : public RequestHandler {
public:
  Response *callback(Request *);
};*/

class SignupHandler : public RequestHandler
{
public:
  Response *callback(Request *);
};

class LoginHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class PostfilmHandler : public RequestHandler
{
public:
  Response* callback(Request*);
};

class HomepageHandler : public TemplateHandler
{
public:
  HomepageHandler(std::string filePath);
  std::map<std::string, std::string> handle(Request *req);
};

#endif
