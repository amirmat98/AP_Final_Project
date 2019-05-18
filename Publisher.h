#ifndef PHASE_1_PUBLISHER_H
#define PHASE_1_PUBLISHER_H

#include "Header.h"
#include "User.h"
#include "Film.h"

class Publisher : public User
{
public:
    Publisher(std::string , std::string , std::string , int);
    virtual void add_in_my_films(Film* x);
    virtual void delete_in_my_films(int x);
    virtual void set_in_my_films(Film& x);
    virtual std::vector<Film*> get_film();
    virtual Film* pointer_of_my_film(int _ID);
    virtual void print_my_film(std::string _name = "" , int _min_rate = -1  , int _min_year = 0
            ,  int _price = -1 , int _max_year = 100000 , std::string _director = "" );

private:
    std::vector<Film*> my_films;
    std::vector<User*> my_followers;
    std::vector<User*> my_following;

};


#endif //PHASE_1_PUBLISHER_H
