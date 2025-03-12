#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> creatematrix(size_t n){

    vector<vector<int>> M(n,vector<int>(n));
    size_t cont = 1;

    for(auto& fila : M){
        for(auto& value : fila){
            value = cont++;
        }
    }
    return M;
}

void printmatrix(vector<vector<int>> M, size_t n){
    for(int ind = n*n; ind >0 ;ind--){
        int i = (ind - 1) / n;
        int j = (ind - 1) % n;

        cout << "M" << n <<"["<< i <<"]["<< j <<"] ="<< M[i][j] << endl;
    }
    return;
}