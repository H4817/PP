#include <sstream>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctime>
#include "PiCalculator.h"


int main(int argc, char *argv[]) {
    if (argc == 3) {
        std::clock_t start;
        std::istringstream ss(argv[1]);
        int iterationsCount;
        int processAmount;
        if (!(ss >> processAmount)) {
            std::cerr << "Invalid number " << argv[1] << '\n';
            return 0;
        }
        std::istringstream ss1(argv[2]);
        if (!(ss1 >> iterationsCount)) {
            std::cerr << "Invalid number " << argv[2] << '\n';
        }
        else {
            pid_t pids[processAmount];
            int pipefd[processAmount * 2];

            for (int i = 0; i < processAmount; ++i) {
                if (pipe(pipefd + i * 2) < 0) {
                    perror("pipe");
                }
            }


            for (int i = 0; i < processAmount; ++i) {
                if ((pids[i] = fork()) < 0) {
                    perror("fork");
                    abort();
                } else if (pids[i] == 0) {
                    start = std::clock();
                    std::cout << "Pi: " << PiCalculator::GetPi(iterationsCount) << std::endl;
                    std::cout << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms"
                              << std::endl;
                    exit(0);
                }
            }

            int status;
            pid_t pid;
            while (processAmount > 0) {
                pid = wait(&status);
                printf("Child with PID %ld exited with status 0x%x. Iterations count: %zu\n", (long) pid,
                       status, iterationsCount);
                --processAmount;  // TODO(pts): Remove pid from the pids array.
            }
        }
    }
    else {
        std::cerr << "You forgot to pass process amount and iterations count" << std::endl;
    }
    return 0;
}

