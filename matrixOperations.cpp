#include <iostream>
#include "matrixOperations.h"

using namespace std;

char** allocMatrixOfChar_RetPtr(int width, int height)
{
	char** matrix = new char* [height];
	for (int i = 0; i < height; i++)
	{
		matrix[i] = new char[width];
	}
	return matrix;

}

char** freeMatrixOfChar_RetNullptr(char** matrix, int height)
{
	for (int i = 0; i < height; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	return nullptr;
}

void printMatrixOfChar(char** matrix, int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}