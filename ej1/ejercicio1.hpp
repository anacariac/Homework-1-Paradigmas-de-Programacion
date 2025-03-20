#include <vector>
using namespace std;

/*
 Crea una matriz cuadrada de tamaño `n x n` con valores secuenciales.
 n<int> Tamaño de la matriz (número de filas y columnas).
 retorna vector<vector<int>> Matriz generada con valores del 1 al n*n.
 */
vector<vector<int>> creatematrix(size_t n);

/*
 Imprime los valores de la matriz en orden decreciente de índices.
 M<vector<vector<int>>> Matriz cuadrada a imprimir.
 n<int> Tamaño de la matriz (número de filas y columnas).
 */
void printmatrix(vector<vector<int>> M, size_t n);