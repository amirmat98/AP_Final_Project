#include "Money_Handler.h"

using namespace std;

Money_Handler::Money_Handler(Core *ccore, Film *ffilm)
{
    my_film = ffilm;
    my_core = ccore;

}

void Money_Handler::run()
{
    my_core->right_now_user->set_money(my_film->get_price());

    if(my_film->get_score() < 5)
    {
        Lower_Film(this);
    }
    else if ( my_film->get_score() >= 5 && my_film->get_score() < 8)
    {
        Middle_Film(this);
    }

    else if (my_film->get_score()>=8)
    {
        Higher_Film(this);
    }
}

Lower_Film::Lower_Film(Money_Handler *x)
{
    int temp = x->my_film->get_price();
    x->my_film->get_publisher()->set_money(int(0.8*temp));
    x->my_core->add_money_to_account(int(0.2*temp));
    //x->my_core->add_money_to_account(int(677.4));
}

Middle_Film::Middle_Film(Money_Handler *x)
{
    int temp = x->my_film->get_price();
    x->my_film->get_publisher()->set_money(int(0.9*temp));
    x->my_core->add_money_to_account(int(0.1*temp));
}

Higher_Film::Higher_Film(Money_Handler *x)
{
    int temp = x->my_film->get_price();
    x->my_film->get_publisher()->set_money(int(0.95*temp));
    x->my_core->add_money_to_account(int(0.05*temp));
}

