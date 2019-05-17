#include "Film.h"

using namespace std;

Film::Film(std::string _name, int _year, int _length, int _price, std::string _summery, std::string _director)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summery = _summery;
    director = _director;

}

void Film::set_ID(int x)
{
    ID =x;
}

void Film::set_name(std::string x)
{
    name = x;
}

void Film::set_year(int x)
{
    year = x;
}

int Film::get_year()
{
    return year;
}

int Film::get_price()
{
    return price;
}

string Film::get_director()
{
    return director;
}

void Film::set_length(int x)
{
    length = x;
}

void Film::set_price(int x)
{
    price = x;
}

void Film::set_summery(std::string x)
{
    summery = x;
}

void Film::set_director(std::string x)
{
    director = x;
}

int Film::get_ID()
{
    return ID;
}

string Film::get_name()
{
    return name;
}

float Film::get_rate()
{
    return rate;
}

void Film::print_film()
{
    cout<<ID;
    cout<<" "<<"|"<<" ";
    cout<<name;
    cout<<" "<<"|"<<" ";
    cout<<length;
    cout<<" "<<"|"<<" ";
    cout<<price;
    cout<<" "<<"|"<<" ";
    cout<<rate;
    cout<<" "<<"|"<<" ";
    cout<<year;
    cout<<" "<<"|"<<" ";
    cout<<director;
}