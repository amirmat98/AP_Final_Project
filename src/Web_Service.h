#ifndef WEB_SERVICE_H
#define WEB_SERVICE_H

#include "Web_Handlers.h"
#include "Core.h"
#include "my_server.h"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>
#include "Header.h"

class Core;

class Web_Service
{
 public:
  Web_Service(Core* core);
  MyServer server;
  Core* netflix_core;
  void run();
};

#endif