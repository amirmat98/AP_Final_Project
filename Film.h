#ifndef PHASE_1_FILM_H
#define PHASE_1_FILM_H

#include "Header.h"
class Film
{
private:
    std::string name;
    int year;
    int length;
    int price;
    std::string summery;
    std::string director;
    int ID;

public:
    Film(std::string _name , int _year , int _length , int _price , std::string _summery , std::string _director);
    void set_ID(int x);
    int get_ID();
    void set_name(std::string);
    std::string get_name();
    void set_year(int);
    void set_length(int);
    void set_price(int);
    void set_summery(std::string);
    void set_director(std::string);
};


#endif //PHASE_1_FILM_H
