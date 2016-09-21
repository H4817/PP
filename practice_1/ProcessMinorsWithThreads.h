#include <thread>
#include <omp.h>

namespace {
    const size_t ROWS_COUNTX = 3;
    const size_t COLUMN_COUNTX = 3;
}

class ProcessMinorsWithThreads {
public:
    ProcessMinorsWithThreads() = delete;

    static void CalculateMatrixOfMinors(const int (&matrix)[ROWS_COUNTX][COLUMN_COUNTX],
                                        int (&matrixOfMinors)[ROWS_COUNTX][COLUMN_COUNTX], size_t g_linesCounter);

    static void PrintMatrixOfMinors(int (&matrixOfMinors)[ROWS_COUNTX][COLUMN_COUNTX]);

};


