#include <vector>

using namespace std;

//Partitions vector comidas by choosing the last element as pivot and moving elements lower than the pivot to the left, higher to the right
//Partitions using time
int partitioningT(vector<Comida> &comidas, int l, int h){
    Comida pivot = comidas[h];

    int i = l - 1;
    Comida temp;

    for(int j = l; j <= h - 1; j++){
        if(comidas[j].t < pivot.t){
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

//Recursively calls partitioning algorithm to sort vector comidas by time in ascending order
void QuickSortT(vector<Comida> &comidas, int l, int h){
    if(l < h){
        int partition_index = partitioningT(comidas, l, h);

        QuickSortT(comidas, l, partition_index - 1);
        QuickSortT(comidas, partition_index + 1, h);
    }
}


//Partitions vector comidas by choosing the last element as pivot and moving elements lower than the pivot to the left, higher to the right
//Partitions using priority
int partitioningP(vector<Comida> &comidas, int l, int h){
    Comida pivot = comidas[h];

    int i = l - 1;
    Comida temp;

    for(int j = l; j <= h - 1; j++){
        if(comidas[j].p > pivot.p){
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

//Recursively calls partitioning algorithm to sort vector comidas by priority in descending order
void QuickSortP(vector<Comida> &comidas, int l, int h){
    if(l < h){
        int partition_index = partitioningP(comidas, l, h);

        QuickSortP(comidas, l, partition_index - 1);
        QuickSortP(comidas, partition_index + 1, h);
    }   
}

//Sorts vector comidas by priority in ascending order then sorts elements with equal priority by time in descending order
void QuickSort(vector<Comida> &comidas){
    QuickSortP(comidas, 0, comidas.size()-1);

    int sup = 0;
    for(int i = 1; i < comidas.size(); i++){
        if(comidas[i-1].p != comidas[i].p){
            QuickSortT(comidas, sup, i-1);
            sup = i;
        }
    }
    QuickSortT(comidas, sup, comidas.size()-1);
};