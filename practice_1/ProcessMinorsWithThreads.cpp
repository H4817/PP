#include "ProcessMinorsWithThreads.h"
#include <vector>
#include <iostream>

void ProcessMinorsWithThreads::CalculateMatrixOfMinors(const int (&matrix)[ROWS_COUNTX][COLUMN_COUNTX],
                                                       int (&matrixOfMinors)[ROWS_COUNTX][COLUMN_COUNTX],
                                                       size_t g_linesCounter) {

    #pragma omp parallel for
    for (size_t i = 0; i < COLUMN_COUNTX; ++i) {
        std::vector<int> partOfMatrix;
        for (size_t linesCounter = 0; linesCounter < ROWS_COUNTX; ++linesCounter) {
            for (size_t columnCounter = 0; columnCounter < COLUMN_COUNTX; ++columnCounter) {
                if (columnCounter != i && linesCounter != g_linesCounter) {
                    partOfMatrix.push_back(matrix[linesCounter][columnCounter]);
                    if (partOfMatrix.size() == 4) {
                        matrixOfMinors[g_linesCounter][i] = ((partOfMatrix[0] * partOfMatrix[3]) -
                                                             (partOfMatrix[1] * partOfMatrix[2]));
                    }
                }
            }
        }
    }
}


void ProcessMinorsWithThreads::PrintMatrixOfMinors(int (&matrixOfMinors)[ROWS_COUNTX][COLUMN_COUNTX]) {
    for (size_t linesCounter = 0; linesCounter < ROWS_COUNTX; ++linesCounter) {
        for (size_t columnCounter = 0; columnCounter < COLUMN_COUNTX; ++columnCounter) {
            std::cout << matrixOfMinors[linesCounter][columnCounter] << " ";
        }
        std::cout << "\n";
    }
}
