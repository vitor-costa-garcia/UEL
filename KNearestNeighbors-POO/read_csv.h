#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifndef DATA_CSV_READER
#define DATA_CSV_READER

class dataCSVReader{
    public:
        //Construtor que lê o aquivo inserido na declaração do objeto
        dataCSVReader(string filename, char sep = ',', bool header = true){
            this -> filename = filename;
            this -> sep = sep;
            get_file_info(filename, sep, header);

            if(isInt){
                dataI = new int*[nrow];
                for(int i = 0; i < nrow; i++){
                    dataI[i] = new int[ncol];
                };
            } else {
                dataF = new float*[nrow];
                for(int i = 0; i < nrow; i++){
                    dataF[i] = new float[ncol];
                };
            }

            read_csv(filename, sep, header);
        }

        //Destrutor que limpa a matriz sendo usada
        ~dataCSVReader(){
            if(isInt){
                for(int i = 0; i < nrow; i++){
                    delete[] dataI[i];
                }
                delete[] dataI;
            } else {
                for(int i = 0; i < nrow; i++){
                    delete[] dataF[i];
                }
                delete[] dataF;
            }
        }

        //Retorna os dados salvos
        void* get_data(){
            if(isInt){
                return dataI;
            }
            return dataF;
        }

        //Retorna o nº de linhas
        int get_rows(){
            return nrow;
        }

        //Retorna o nº de colunas
        int get_columns(){
            return ncol;
        }

    private:
        string filename;
        char sep;
        int ncol, nrow;
        int** dataI;
        float** dataF;
        bool isInt = true;

        //Lê os dados do arquivo e salva na devida matriz (int ou float)
        void read_csv(string filename, char sep, bool header){
            int counterRow = 0, counterCol = 0, supInt = 0, supIndex = 0;
            float supFloat = 0;
            string currentRow, tempRow;

            ifstream mfile;
            mfile.open(filename);

            if(header){mfile >> currentRow;};

            for(int _ = 0; _ < nrow; _++){
                mfile >> currentRow;

                for(int i = 0; i < currentRow.length()+1; i++){
                    if(currentRow[i] == sep || currentRow[i] == '\0'){
                        tempRow = currentRow.substr(supIndex, i-supIndex);
                        supIndex = i+1;

                        if(tempRow.empty()){
                            isInt ? dataI[counterRow][counterCol] = 0 : dataF[counterRow][counterCol] = 0;
                            counterCol++;
                            continue;
                        }

                        if(isInt){
                            supInt = stoi(tempRow);
                            dataI[counterRow][counterCol] = supInt;
                        } else {
                            supFloat = stof(tempRow);
                            dataF[counterRow][counterCol] = supFloat;
                        }
                        counterCol++;
                    }
                }
                supIndex = 0;
                counterCol = 0;
                counterRow++;
            }
            
            mfile.close();
        }

        //Lê todo o arquivo para salvar informações necessárias para o funcionamento correto do algoritmo (nº de linhas e colunas, tipo do dado)
        void get_file_info(string filename, char sep, bool header){
            ifstream mfile;
            mfile.open(filename);
            int cCounter = 1;
            int lCounter = 0;

            string currentRow;
            if(header){mfile >> currentRow;};
            while(mfile){
                mfile >> currentRow;
                for(int i = 0; i < currentRow.length(); i++){
                    if(currentRow[i] == sep && !lCounter){cCounter++;};
                    if(currentRow[i] == '.'){isInt = false;};
                }
                lCounter++;
            }
            mfile.close();
            ncol = cCounter;
            nrow = lCounter;
        }
};

#endif