#include <vector>

using namespace std;

//Partitions vector comidas by choosing the last element as pivot and moving elements lower than the pivot to the left, higher to the right
//Partitions using priority
int partitioningP(vector<Comida> &comidas, int l, int h){
    Comida pivot = comidas[h];

    int i = l - 1;
    Comida temp;

    for(int j = l; j <= h - 1; j++){
        if(comidas[j].p > pivot.p || (comidas[j].p == pivot.p && comidas[j].t < pivot.t)){
            i++;
            temp = comidas[i];
            comidas[i] = comidas[j];
            comidas[j] = temp;
        }
    }

    temp = comidas[i + 1];
    comidas[i + 1] = pivot;
    comidas[h] = temp;

    return i+1;
};

//Recursively calls partitioning algorithm to sort vector comidas by priority in descending order and time in ascending order
void QuickSortP(vector<Comida> &comidas, int l, int h){
    if(l < h){
        int partition_index = partitioningP(comidas, l, h);

        QuickSortP(comidas, l, partition_index - 1);
        QuickSortP(comidas, partition_index + 1, h);
    }   
}

//Calls Quicksort algorithm
void QuickSort(vector<Comida> &comidas){
    QuickSortP(comidas, 0, comidas.size()-1);
};
