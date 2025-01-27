#include <string>
#include <vector>

using namespace std;

//Sorts vector comidas by priority in descending order
void BubbleSortP(vector<Comida> &comidas, int l, int h){
    int counter = 0;

    for(int i = l; i < h; i++){
        for(int j = l+1; j < h-counter; j++){
            if(comidas[j-1].p > comidas[j].p){
                Comida temp = comidas[j];
                comidas[j] = comidas[j-1];
                comidas[j-1] = temp;
            };
        };
        counter++;
    };
};

//Sorts vector comidas by time in ascending order
void BubbleSortT(vector<Comida> &comidas, int l, int h){
    int counter = 0;
    for(int i = l; i < h; i++){
        for(int j = l+1; j < h-counter; j++){
            if(comidas[j-1].t > comidas[j].t){
                Comida temp = comidas[j];
                comidas[j] = comidas[j-1];
                comidas[j-1] = temp;
            };
        };
        counter++;
    };
};

//Sort vector comidas by priority in descending order, then sorts again by time in ascending order
void BubbleSort(vector<Comida> &comidas){
    BubbleSortP(comidas, 0, comidas.size());

    int sup = 0;
    for(int i = 1; i < comidas.size(); i++){
        if(comidas[i-1].p != comidas[i].p){
            BubbleSortT(comidas, sup, i);
            sup = i;
        }
    }
    BubbleSortT(comidas, sup, comidas.size());
};