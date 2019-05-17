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

private:
    std::vector<Film*> my_films;
    std::vector<User*> my_followers;
    std::vector<User*> my_following;
};


#endif //PHASE_1_PUBLISHER_H
