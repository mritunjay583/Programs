#include <iostream>

#define N 10

// Dynamically Allocate Memory for 1D Array in C++
int main()
{
	// dynamically allocate memory of size N
	int* A = new int[N];

	// assign values to allocated memory
	for (int i = 0; i < N; i++)
		A[i] = i + 1;

	// print the 1D array
	for (int i = 0; i < N; i++)
		std::cout << A[i] << " ";	// or *(A + i)

	// deallocate memory
	delete[] A;

	return 0;
}