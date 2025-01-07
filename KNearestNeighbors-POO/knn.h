#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#ifndef KNN
#define KNN

class KNearestNeighbors{
    public:
        void fit(int k, void* data, int** label, int nrow, int ncol, bool isInt){
            this -> k = k;
            this -> label = label;
            this -> nrow = nrow;
            this -> ncol = ncol;
            this -> isInt = isInt;

            if(isInt){
                dataI = static_cast<int**>(data);
            } else {
                dataF = static_cast<float**>(data);
            }
        };

        int* predict(float** arr, int len){
            int* resultsLabels = new int[len];
            for(int t = 0; t < len; t++){
                int shortestIndexLabel[k];
                for(int i = 0; i < k; i++){
                    shortestIndexLabel[i] = i;
                }

                float shortestDistance[k] = {INFINITY};
                fill(shortestDistance, shortestDistance + k, INFINITY);
                float maxDistance[2] = {INFINITY, 0};
                float tempDist;

                for(int i = 0; i < nrow; i++){
                    if(isInt){
                        tempDist = euclidean_dist(dataI[i], arr[t]);
                    } else {
                        tempDist = euclidean_dist(dataF[i], arr[t]);
                    }
                    if(tempDist < maxDistance[0]){
                        shortestDistance[int(maxDistance[1])] = tempDist;
                        shortestIndexLabel[int(maxDistance[1])] = i;
                        tempDist = 0;
                        for(int j = 0; j < k; j++){
                            if(shortestDistance[j] > tempDist){
                                tempDist = shortestDistance[j];
                                maxDistance[1] = j;
                            }
                        }
                        maxDistance[0] = shortestDistance[int(maxDistance[1])];
                    }
                }
                for(int i = 0; i < k; i++){
                    shortestIndexLabel[i] = label[shortestIndexLabel[i]][0];
                }
                
                int finalLabel = count_labels(shortestIndexLabel);

                resultsLabels[t] = finalLabel;
            };
            return resultsLabels;
        };

    private:
        float euclidean_dist(float* datarow, float pred[]){
            float distance = 0;
            for(int i = 0; i < ncol; i++){
                distance += pow(datarow[i] - pred[i], 2);
            }
            return pow(distance, 0.5);
        }

        float euclidean_dist(int* datarow, float pred[]){
            float distance = 0;
            for(int i = 0; i < ncol; i++){
                distance += pow(datarow[i] - pred[i], 2);
            }
            return pow(distance, 0.5);
        }

        int count_labels(int arr[]){
            map<int, int> counter;
            vector<int> chaves;
            for(int i = 0; i < k; i++){
                if(counter.count(arr[i])){
                    counter[arr[i]]++;
                } else {
                    counter[arr[i]] = 1;
                    chaves.push_back(arr[i]);
                }
                cout << arr[i] << ":" << counter[arr[i]] << endl;
            }

            int finalLabel = -1;

            for(int i = 0; i < chaves.size(); i++){
                if(counter[chaves[i]] > counter[finalLabel]) finalLabel = chaves[i];
            }

            return finalLabel;
        };

        int** dataI;
        float** dataF;
        int** label;
        int nrow;
        int ncol;
        int k;
        bool isInt;

};

#endif