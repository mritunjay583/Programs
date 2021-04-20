// using single pointer

#include <iostream>

// M x N matrix
#define M 4
#define N 5

// Dynamically Allocate Memory for 2D Array in C++
int main()
{
	// dynamically allocate memory of size M*N
	int* A = new int[M * N];

	// assign values to allocated memory
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			*(A + i*N + j) = rand() % 100;

	// print the 2D array
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			std::cout << *(A + i*N + j) << " ";	// or (A + i*N)[j])

		std::cout << std::endl;
	}

	// deallocate memory
	delete[] A;

	return 0;
}