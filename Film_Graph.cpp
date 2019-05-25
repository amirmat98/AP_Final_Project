#include "Film_Graph.h"

using namespace std;

Film_Graph::Film_Graph()
{
}

void Film_Graph::update(Core* ccore)
{
    my_core = ccore;
    number_of_core_film = my_core->get_my_films().size();
    init_matrix(number_of_core_film);
    make_matrix();

}

void Film_Graph::init_matrix(int size)
{
    adjacency_matrix.clear();
    for(int i = 0 ; i<size ; i++)
    {
        map < Film* , int > temp_map;
        for(int j = 0 ; j < size ; j++)
        {
            //Film* temp_film = my_core.get_my_films()[j];
            temp_map.insert(pair<Film*,int>(my_core->get_my_films()[j],0));
        }
        adjacency_matrix.insert(pair<Film*,map<Film*,int>>(my_core->get_my_films()[i],temp_map));
    }
}

int Film_Graph::weight_of_edge(Film *a, Film* b)
{
    int indexer = 0;
    for(int i = 0 ; i<a->get_buyer().size() ; i++)
    {
        for(int j = 0 ; j < a->get_buyer()[i]->get_buy_film().size() ; j++)
        {
            if(a->get_buyer()[i]->get_buy_film()[j] == b)
            {
                indexer++;
            }
        }
    }
    return indexer;
}

void Film_Graph::make_matrix()
{
    for(map<Film* , map<Film*,int>>::iterator it1 = adjacency_matrix.begin() ; it1 != adjacency_matrix.end() ; it1++)
    {
        map<Film*,int> temp_map = it1->second;
        for(map<Film*,int>::iterator it2 = temp_map.begin() ; it2!=temp_map.end() ; it2++)
        {
            if(it1->first == it2->first)
                continue;
            int index;
            index = weight_of_edge(it1->first , it2->first);
            adjacency_matrix[it1->first][it2->first] = index;
        }
    }
}
