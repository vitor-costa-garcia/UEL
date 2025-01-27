#include <iostream>
#include "src/utils/read_csv.h"
#include "src/utils/knn.h"

using namespace std;

int main(){
    //Lendo os dados e os rótulos
    dataCSVReader feat1("data/dataset2.csv");
    float** features = static_cast<float**>(feat1.get_data());

    dataCSVReader lab1("data/label1.csv");
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
    knn.fit(3, features, labels, feat1.get_rows(), feat1.get_columns());

    //Método predict
    int* teste = knn.predict(arr, nrow);

    //Exibindo o resultado do algoritmo
    cout << "[ " << teste[0];
    for(int i = 1; i < nrow; i++){
        cout << " , "<< teste[i];
    }
    cout << " ]";
}
