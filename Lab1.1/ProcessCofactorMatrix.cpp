#include "ProcessCofactorMatrix.h"
#include <iostream>
#include <cmath>

void ProcessCofactorMatrix::MainAlgorithm(int sizeOfMatrix, int **matrix, int **cofactorMatrix, size_t start,
                                          size_t end) {
    int **tempMatrix = new int *[sizeOfMatrix - 1];
    for (int i = 0; i < sizeOfMatrix - 1; i++)
        tempMatrix[i] = new int[sizeOfMatrix - 1];
    for (int linesCounter = start; linesCounter < end; ++linesCounter)
        for (size_t k, k1, columnCounter = 0; columnCounter < sizeOfMatrix; columnCounter++) {
            k = linesCounter;
            k1 = columnCounter;
            for (int i = 0, s = 0, s1 = 0;
                 i < sizeOfMatrix; ++i)
                if (i != k) {
                    s1 = 0;
                    for (int j = 0; j < sizeOfMatrix; ++j) {
                        if (j != k1) {
                            tempMatrix[s][s1] = matrix[i][j];
                            s1++;
                        }
                    }
                    s++;
                }
            cofactorMatrix[k][k1] = pow(-1., k + 1 + k1 + 1) * CalculateDeterminant(tempMatrix, sizeOfMatrix - 1);
        }
}

int ProcessCofactorMatrix::CalculateDeterminant(int **Arr, int size) {
    int j;
    int determinant = 0;
    int **tempMatrix;
    if (size == 1) {
        determinant = Arr[0][0];
    }
    else if (size == 2) {
        determinant = Arr[0][0] * Arr[1][1] -
                      Arr[0][1] * Arr[1][0];
    }
    else {
        tempMatrix = new int *[size - 1];
        for (int i = 0; i < size; ++i) {
            for (j = 0; j < size - 1; ++j) {
                if (j < i) {
                    tempMatrix[j] = Arr[j];
                }
                else
                    tempMatrix[j] = Arr[j + 1];
            }
            determinant +=
                    pow(-1., (i + j)) * CalculateDeterminant(tempMatrix, size - 1) * Arr[i][size - 1];
        }
        delete[] tempMatrix;
    }
}

void ProcessCofactorMatrix::PrintMatrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int ProcessCofactorMatrix::CreateRandomMatrix(int **Arr, int size) {
    for (int linesCounter = 0; linesCounter < size; ++linesCounter) {
        for (int columnCounter = 0; columnCounter < size; ++columnCounter) {
            Arr[linesCounter][columnCounter] = rand() % 10 - 5;
        }
    }
    return 0;
}
