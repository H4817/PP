#include <iostream>
#include <vector>

namespace {
    const size_t ROWS_COUNT = 3;
    const size_t COLUMN_COUNT = 3;
}

class ProcessMinors {

public:
    ProcessMinors() = delete;

    static void CalculateMatrixOfMinors(int matrix[ROWS_COUNT][COLUMN_COUNT],
                                        int (&matrixOfMinors)[ROWS_COUNT][COLUMN_COUNT], size_t g_linesCounter);

    static void PrintMatrixOfMinors(int (&matrixOfMinors)[ROWS_COUNT][COLUMN_COUNT]);

};



