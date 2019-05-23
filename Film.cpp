#include "Film.h"

using namespace std;

Film::Film(std::string _name, int _year, int _length, int _price, std::string _summary, std::string _director)
{
    name = _name;
    year = _year;
    length = _length;
    price = _price;
    summary = _summary;
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

void Film::set_summary(std::string x)
{
    summary = x;
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

void Film::print_recom_film()
{
    cout<<ID;
    cout<<" "<<"|"<<" ";
    cout<<name;
    cout<<" "<<"|"<<" ";
    cout<<length;
    cout<<" "<<"|"<<" ";
    cout<<director;
}

void Film::print_detailed_film()
{
    cout<<"Details of Film "<<name<<endl;
    cout<<"Id = "<<ID<<endl;
    cout<<"Director = "<<director<<endl;
    cout<<"Length = "<<length<<endl;
    cout<<"Year = "<<year<<endl;
    cout<<"Summary = "<<summary<<endl;
    cout<<"Rate = "<<rate<<endl;
    cout<<"Price = "<<price<<endl;
}

void Film::print_all_comment()
{
    cout<<"Comments"<<endl;
    for(int i = 0 ; i<my_comments.size() ; i++)
    {
        cout<<my_comments[i].get_ID();
        cout<<". ";
        cout<<my_comments[i].get_comment();
        cout<<endl;

        for(int j = 0 ; j<my_comments[i].get_replies().size() ; j++)
        {
            cout<<my_comments[i].get_ID();
            cout<<".";
            cout<<j+1;
            cout<<". ";
            cout<<my_comments[i].get_replies()[j];
            cout<<" ";
        }
        cout<<endl;
    }
}

void Film::add_to_my_comment(Comment _temp_comment)
{
    _temp_comment.set_ID(my_comments.size() + 1 );
    my_comments.push_back(_temp_comment);
}

std::vector<Comment> Film::get_my_comments()
{
    return my_comments;
}

void Film::delete_a_comment(int _comment_id)
{
    vector<Comment>::iterator it;
    for(int i=0 ; i<my_comments.size() ; i++)
    {
        if(my_comments[i].get_ID() == _comment_id)
            it = my_comments.begin() + i;
    }

    my_comments.erase(it);

}

void Film::calculate_score()
{
    float temp = 0;
    for(int i = 0 ; i<scores.size() ; i++)
    {
        temp+=scores[i];
    }
    temp = temp/scores.size();

    my_score = temp;
    rate = my_score;
}

void Film::set_publisher(User* _publisher)
{
    my_publisher = _publisher;
}

float Film::get_score()
{
    return my_score;
}

User* Film::get_publisher()
{
    return my_publisher;
}