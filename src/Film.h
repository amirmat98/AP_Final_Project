#ifndef PHASE_1_FILM_H
#define PHASE_1_FILM_H

#include "Header.h"
#include "Comment.h"
#include "User.h"

class Comment;
class User;

class Film
{
private:
    std::string name;
    int year;
    int length;
    int price;
    float rate = 0;
    std::string summary;
    std::string director;
    int ID;
    //int number_of_comments = 0;
    std::vector<Comment> my_comments;
    float my_score;
    User* my_publisher;
    std::vector<User*> my_buyer;

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
    int get_length();
    std::string get_director();
    void set_length(int);
    void set_price(int);
    void set_publisher(User*);
    void set_summary(std::string);
    void set_director(std::string);
    void print_film();
    void print_detailed_film();
    void add_buyer(User* temp_buyer);
    std::vector<User*> get_buyer();
    void print_all_comment();
    void print_recom_film();
    void add_to_my_comment(Comment _temp_comment);
    std::vector<Comment> get_my_comments();
    void delete_a_comment(int _comment_id);
    std::vector<float> scores;
    void calculate_score();
    float get_score();
    User* get_publisher();
    int number_of_comments;
    Comment* pointer_to_comment(int _comment_id);
};


#endif //PHASE_1_FILM_H
