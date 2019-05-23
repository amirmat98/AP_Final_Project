#ifndef PHASE_1_MONEY_HANDLER_H
#define PHASE_1_MONEY_HANDLER_H

#include "Header.h"
#include "Core.h"
#include "Film.h"

class Core;
class Lower_Film;
class Middle_Film;
class Higher_Film;

class Money_Handler
{
private:
    friend class Lower_Film;
    friend class Middle_Film;
    friend class Higher_Film;
public:
    Core* my_core;
    Film* my_film;
    Money_Handler(Core* ccore , Film* ffilm);
    void run();
};


class Lower_Film
{
public:
    Lower_Film(Money_Handler* x);
};

class Middle_Film
{
public:
    Middle_Film(Money_Handler* x);
};

class Higher_Film
{
public:
    Higher_Film(Money_Handler* x);
};




#endif //PHASE_1_MONEY_HANDLER_H
