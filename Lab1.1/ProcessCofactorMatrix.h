#include <thread>

class ProcessCofactorMatrix {
public:
    ProcessCofactorMatrix() = delete;

    static int CreateRandomMatrix(int **Arr, int size);

    static int CalculateDeterminant(int **Arr, int size);

    static void MainAlgorithm(int sizeOfMatrix, int **matrix, int **cofactorMatrix, size_t start, size_t end);

    static void PrintMatrix(int **matrix, int size);
};
