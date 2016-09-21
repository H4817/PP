#include "ProcessMinors.h"


void ProcessMinors::CalculateMatrixOfMinors(int matrix[ROWS_COUNT][COLUMN_COUNT],
                                            int (&matrixOfMinors)[ROWS_COUNT][COLUMN_COUNT], size_t g_linesCounter) {
    for (size_t i = 0; i < COLUMN_COUNT; ++i) {
        std::vector<int> partOfMatrix;
        for (size_t linesCounter = 0; linesCounter < ROWS_COUNT; ++linesCounter) {
            for (size_t columnCounter = 0; columnCounter < COLUMN_COUNT; ++columnCounter) {
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
    if (g_linesCounter < ROWS_COUNT) {
        ++g_linesCounter;
        CalculateMatrixOfMinors(matrix, matrixOfMinors, g_linesCounter);
    }
}


void ProcessMinors::PrintMatrixOfMinors(int (&matrixOfMinors)[ROWS_COUNT][COLUMN_COUNT]) {
    for (size_t linesCounter = 0; linesCounter < ROWS_COUNT; ++linesCounter) {
        for (size_t columnCounter = 0; columnCounter < COLUMN_COUNT; ++columnCounter) {
            std::cout << matrixOfMinors[linesCounter][columnCounter] << " ";
        }
        std::cout << "\n";
    }
}