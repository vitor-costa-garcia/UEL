#include "src/utils/neuroniorelu.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main(){
    srand(42);

    vector<double> pesos_n1;
    vector<double> pesos_n2;
    vector<double> pesos_n3;

    int n_pesos = 3; //Caso queira alterar número de pesos

    // Gera n pesos para cada neurônio. Números entre -10 e 10;
    for(int i = 1; i <= n_pesos; i++){
        pesos_n1.push_back((rand()%10)*(rand()%2*-1));
        pesos_n2.push_back((rand()%10)*(rand()%2*-1));
        pesos_n3.push_back((rand()%10)*(rand()%2*-1));
    }

    // Gera 3 bias para cada neurônio. Números entre 0 e 100
    int bias_n1 = (rand()%100);
    int bias_n2 = (rand()%100);
    int bias_n3 = (rand()%100);

    Neuronio* n1 = new NeuronioReLU(pesos_n1, bias_n1);
    Neuronio* n2 = new NeuronioReLU(pesos_n2, bias_n2);
    Neuronio* n3 = new NeuronioReLU(pesos_n3, bias_n3);
    
    vector<double> entradas;
    for(int i = 1; i <= n_pesos; i++){
        entradas.push_back((rand()%10));
    }

    cout << "Saída N1: " << n1->predict(entradas) << endl;
    cout << "Saída N2: " << n2->predict(entradas) << endl;
    cout << "Saída N3: " << n3->predict(entradas) << endl;

}