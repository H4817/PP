#include <iostream>
#include <ctime>
#include <cmath>
#include <thread>
#include "ProcessCofactorMatrix.h"

int main() {
	int sizeOfMatrix;
	size_t k;
	size_t k1;
	std::cout << "input size of matrix:\n";
	std::cin >> sizeOfMatrix;
	if (sizeOfMatrix <= 0) {
		std::cout << "the value should be positive\n";
		throw;
	}
	int **matrix = new int *[sizeOfMatrix];
	int **cofactorMatrix = new int *[sizeOfMatrix];
	for (int i = 0; i < sizeOfMatrix; i++) {
		matrix[i] = new int[sizeOfMatrix];
		cofactorMatrix[i] = new int[sizeOfMatrix];
	}
	ProcessCofactorMatrix::CreateRandomMatrix(matrix, sizeOfMatrix);
	std::cout << "\n";

	std::clock_t start;
	start = std::clock();

	//std::thread t1(ProcessCofactorMatrix::MainAlgorithm, sizeOfMatrix, std::ref(matrix), std::ref(cofactorMatrix), 0, sizeOfMatrix / 2);
	//std::thread t2(ProcessCofactorMatrix::MainAlgorithm, sizeOfMatrix, std::ref(matrix), std::ref(cofactorMatrix), sizeOfMatrix / 2, sizeOfMatrix);
	//t1.join();
	//t2.join();

	ProcessCofactorMatrix::MainAlgorithm(sizeOfMatrix, matrix, cofactorMatrix, 0, sizeOfMatrix / 2);
	ProcessCofactorMatrix::MainAlgorithm(sizeOfMatrix, matrix, cofactorMatrix, sizeOfMatrix / 2, sizeOfMatrix);

	std::cout << "Time: " << (std::clock() - start) / (double) (CLOCKS_PER_SEC / 1000) << " ms\n" << std::endl;
}
