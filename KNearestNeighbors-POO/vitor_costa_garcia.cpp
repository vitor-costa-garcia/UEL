#include <iostream>
#include "read_csv.h"
#include "knn.h"

using namespace std;

int main(){
    //Lendo os dados e os rótulos
    dataCSVReader feat1("dataset1.csv");

    dataCSVReader lab1("label1.csv");
    int** labels = static_cast<int**>(lab1.get_data());

    //Criando o conjunto de dados de exemplo
    float** arr;
    int nrow;

    cout << "Quantos exemplos seu conjunto de testes tera?\n";
    cin >> nrow;

    arr = new float*[nrow];
    for(int i = 0; i < nrow; i++){
        arr[i] = new float[feat1.get_columns()];
        for(int j = 0; j < feat1.get_columns(); j++){
            cout << "Digite o valor na posicao ("<<i<<","<<j<<")";
            cin >> arr[i][j];
        }
    }

    //Declarando a classe KNN
    KNearestNeighbors knn;

    //Método fit
    knn.fit(3, feat1.get_data(), labels, feat1.get_rows(), feat1.get_columns(), false);

    //Método predict
    int* teste = knn.predict(arr, nrow);

    //Exibindo o resultado do algoritmo
    cout << "[ " << teste[0];
    for(int i = 1; i < nrow; i++){
        cout << " , "<< teste[i];
    }
    cout << " ]";
}