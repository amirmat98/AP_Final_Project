#ifndef WEB_SERVICE_H
#define WEB_SERVICE_H

#include "Web_Handlers.h"
#include "my_server.h"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>
#include "Header.h"


class Web_Service
{
 public:
  Web_Service();
  MyServer server;
  void run();
};

#endif