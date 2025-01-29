#include "neuronio.hpp"
#include <stdexcept>

using namespace std;

class NeuronioReLU : public Neuronio{
    public:
        NeuronioReLU(vector<double>& pesos, double bias) : Neuronio(pesos, bias){
        }

        double predict(const vector<double> entradas) const {
            if(entradas.size() != pesos.size()){throw invalid_argument("Tamanho do vetor de entradas não condiz com o dos pesos");}
            float saida = bias;

            for(int i = 0; i < pesos.size(); i++){
                saida += (pesos[i]*entradas[i]);
            }

            return (saida > 0 ? saida : 0);
        };

        ~NeuronioReLU(){};
};