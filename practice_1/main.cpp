#include <iostream>
#include <ctime>
#include "ProcessMinors.h"
#include "ProcessMinorsWithThreads.h"

int main() {
    int matrix[ROWS_COUNT][COLUMN_COUNT] = {{1,  -2, 0},
                                            {4,  6,  2},
                                            {-3, 4,  -2}};
    int matrixOfMinors[ROWS_COUNT][COLUMN_COUNT];

    std::clock_t start;
    start = std::clock();
    ProcessMinors::CalculateMatrixOfMinors(matrix, matrixOfMinors, 0);
    std::cout << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
    ProcessMinors::PrintMatrixOfMinors(matrixOfMinors);

    std::cout << "=============== " << "with threads" << " ===============" << "\n";

    std::clock_t startForThreads;
    startForThreads = std::clock();
    #pragma omp parallel for
    for (size_t i = 0; i < 3; ++i) {
        ProcessMinorsWithThreads::CalculateMatrixOfMinors(matrix, matrixOfMinors, i);
    }
    std::cout << "Time: " << (std::clock() - startForThreads) / (double) (CLOCKS_PER_SEC / 1000) << " ms"
              << std::endl;
    ProcessMinorsWithThreads::PrintMatrixOfMinors(matrixOfMinors);

    return 0;
}
