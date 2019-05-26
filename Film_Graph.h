#ifndef PHASE_1_FILM_GRAPH_H
#define PHASE_1_FILM_GRAPH_H

#include "Header.h"
#include "Core.h"
#include "Film.h"
#include "User.h"

class Core;

class Film_Graph
{
public:
    Film_Graph();
    void update(Core* ccore);
    void recommendation_film_from_graph(Film* x , std::vector<Film*>& recom_film);
private:
    Core* my_core;
    int number_of_core_film;
    //std::vector<int> adjacency_matrix;
    std::map< Film* , std::map< Film* , int > > adjacency_matrix;
    void init_matrix(int size);
    int weight_of_edge(Film* a , Film* b);
    void make_matrix();
    vector<Film*> make_sorted_recom_film(std::map<Film*,int> x);

};


#endif //PHASE_1_FILM_GRAPH_H
