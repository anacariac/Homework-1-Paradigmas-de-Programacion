#include "ejercicio1.hpp"
#include <iostream>

vector<vector<int>> creatematrix(size_t n){

    vector<vector<int>> M(n,vector<int>(n)); //crea un tipo vector con n filas con n columnas (matriz cuadrada n x n)
    size_t cont = 1;

    for(auto& fila : M){
        for(auto& value : fila){
            value = cont; //asigna valores secuenciales a la matriz
            cont +=1;
        }
    }
    return M;
}

void printmatrix(vector<vector<int>> M, size_t n){
    for(int ind = n*n; ind >0 ;ind--){
        int i = (ind - 1) / n; // número de fila
        int j = (ind - 1) % n; // número de columna

        cout << "M" << n <<"["<< i <<"]["<< j <<"] ="<< M[i][j] << endl;
    }
    return;
}

int main(){
    size_t n;
    cout << "Ingrese dimensión de la matriz a crear:"<< endl; //solicita al usuario un tamaño de matriz, la genera y la imprime.
    cin >> n;
    vector<vector<int>> M = creatematrix(n);
    
    cout<<"\nLa matriz de forma decreciente se ve de la siguiente manera:"<< endl;
    printmatrix(M,n);
}