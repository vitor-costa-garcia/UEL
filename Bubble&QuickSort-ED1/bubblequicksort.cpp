#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

struct Comida{
    int t;
    int p;
    string n;
};

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

void BubbleSort(vector<Comida> &comidas){
    for(int i = 0; i < comidas.size(); i++){
        for(int j = 1; j < comidas.size()-i-1; j++){
            cout << "i: " << i << " j: " << j << endl;
            if(comidas[j-1].p > comidas[j].p){
                Comida temp = comidas[j];
                comidas[j] = comidas[j-1];
                comidas[j-1] = temp;
            };
        };
    };
};

int partitioning(vector<Comida> &comidas, int l, int h){
    int pivot = comidas[h].p;

    int i = l - 1;
    int temp;

    for(int j = l; j <= h - 1; j++){
        if(comidas[j].p < pivot){
            i++;
            temp = comidas[i].p;
            comidas[i].p = comidas[j].p;
            comidas[j].p = temp;
        }
    }

    temp = comidas[i + 1].p;
    comidas[i + 1].p = pivot;
    comidas[h].p = temp;

    return i+1;
};

void QuickSort(vector<Comida> &comidas, int l, int h){
    if(l < h){
        int partition_index = partitioning(comidas, l, h);

        QuickSort(comidas, l, partition_index - 1);
        QuickSort(comidas, partition_index + 1, h);
    }
}

void QuickSort(vector<Comida> &comidas){
    QuickSort(comidas, 0, comidas.size()-1);
};

int main(){
    vector<Comida> comidas = ReadCSV("restaurante_pratos.csv", ',', true);

    //BubbleSort(comidas);
    QuickSort(comidas);

    cout << "Done";

    for(int i = 0; i < comidas.size(); i++){
        cout << comidas[i].p << ", " << comidas[i].t << ", " << comidas[i].n << endl;
    }
}