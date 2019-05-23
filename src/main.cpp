#include "Header.h"
#include "Core.h"
#include <fstream>

using namespace std;


vector<string> get_input_from_file(string file_address)
{
    vector <string> temp;
    ifstream file (file_address);
    string temp_line;
    while (getline( file , temp_line ))
    {
        temp.push_back(temp_line);
    }

    return temp;
}



int main(int argc , char *argv[])
{
    //vector<string> my_input_file;
    //my_input_file = get_input_from_file(argv[1]);
    Core x;
    x.main();

    getchar();
    return 0;
}