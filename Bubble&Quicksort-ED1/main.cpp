#include <iostream>
#include <chrono>
#include <vector>
#include "read_csv.hpp"
#include "bubblesort.hpp"
#include "quicksort.hpp"

using namespace std;
using namespace std::literals::chrono_literals;

int main(){
    //BUBBLESORT ALGORITHM---------------------------------------------------------------------------------
    //Reading comidas csv file
    vector<Comida> comidas = ReadCSV("restaurante_pratos.csv", ',', true);

    //Starts timer
    auto start = std::chrono::high_resolution_clock::now();

    //Sorting comidas vector using BubbleSort algorithm -> Time complexity:O(n^2) - Space complexity:O(1)
    BubbleSort(comidas);

    //Ends timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    //Time taken by BubbleSort algorithm to sort vector comidas;
    cout << "Tempo BubbleSort: " << duration.count() << endl;

    //QUICKSORT ALGORITHM----------------------------------------------------------------------------------
    //Reading comidas csv file again (resets positions)
    vector<Comida> comidas = ReadCSV("restaurante_pratos.csv", ',', true);

    //Starts timer
    auto start = std::chrono::high_resolution_clock::now();

    //Sorting comidas vector using QuickSort algorithm -> Time complexity:O(n*logn) - Space complexity:O(1)
    QuickSort(comidas);

    //Ends timer
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    cout << "Tempo: " << duration.count() << endl;


}