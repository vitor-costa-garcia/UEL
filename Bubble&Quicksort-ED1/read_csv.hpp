#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct Comida{
    int t;
    int p;
    string n;
};

//Turns csv file in a comidas vector
vector<Comida> ReadCSV(string name, char sep, bool header){
    vector<Comida> c;
    ifstream mfile(name);
    string line;
    
    int t;
    int p;
    string n;

    if(header){mfile >> line;};
    
    while(mfile){
        mfile >> line;
        
        int support = 0;
        int counter = 1;

        for(int i = 0; i < line.size(); i++){
            if(line[i] == sep){

                switch(counter){
                    case 1:
                        p = stoi(line.substr(support, i-support));
                        break;
                    case 2:
                        t = stoi(line.substr(support, i-support));
                        break;
                }
                support = i+1;
                counter++;

                if(counter > 2){break;}
            }
        }
        n = line.substr(support, line.size()-support);

        
        Comida comida = {t, p, n};
        c.push_back(comida);
        
    }
    
    return c;
};
