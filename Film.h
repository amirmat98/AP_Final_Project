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
    float rate;
    std::string summary;
    std::string director;
    int ID;

public:
    Film(std::string _name , int _year , int _length , int _price , std::string _summary , std::string _director);
    void set_ID(int x);
    int get_ID();
    float get_rate();
    void set_name(std::string);
    std::string get_name();
    void set_year(int);
    int get_year();
    int get_price();
    std::string get_director();
    void set_length(int);
    void set_price(int);
    void set_summary(std::string);
    void set_director(std::string);
    void print_film();
};


#endif //PHASE_1_FILM_H
