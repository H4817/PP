#include <thread>

namespace {
    const size_t ROWS_COUNTX = 3;
    const size_t COLUMN_COUNTX = 3;
}

class ProcessCofactorMatrix {
public:
    ProcessCofactorMatrix() = delete;

    static int CreateRandomMatrix(int **Arr, int size);

    static int CalculateDeterminant(int **Arr, int size);

    static void MainAlgorithm(int sizeOfMatrix, int **matrix, int **cofactorMatrix, size_t start, size_t end);

    static void PrintMatrix(int **matrix, int size);
};
