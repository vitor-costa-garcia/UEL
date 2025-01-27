#include <string>
#include <vector>

using namespace std;

//Sorts vector comidas by priority in descending order and time in ascending order
void BubbleSortP(vector<Comida> &comidas, int l, int h){
    int counter = 0;
    bool swap = true;

    while(swap){
        swap = false;
        for(int j = l+1; j < h-counter; j++){
            if(comidas[j-1].p < comidas[j].p || (comidas[j-1].p == comidas[j].p && comidas[j-1].t > comidas[j].t)){
                Comida temp = comidas[j];
                comidas[j] = comidas[j-1];
                comidas[j-1] = temp;
                swap = true;
            };
        };
        counter++;
    };
};

//Calls Bubblesort algorithm
void BubbleSort(vector<Comida> &comidas){
    BubbleSortP(comidas, 0, comidas.size());
};
