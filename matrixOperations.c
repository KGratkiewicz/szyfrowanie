#include <stdio.h>
#include <stdlib.h>
#include "matrixOperations.h"

char** allocMatrixOfChar(int width, int height)
{
	char** matrix = (char**)calloc(height, sizeof(char*));
	for (int i = 0; i < height; i++)
	{
		matrix[i] = (char*)calloc(width, sizeof(char));
	}
	return matrix;

}

void freeMatrixOfChar(char** matrix, int height)
{
	for (int i = 0; i < height; i++)
	{
		free (matrix[i]);
	}
	free(matrix);
}

void printMatrixOfChar(char** matrix, int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			printf("%c",matrix[i][j]);
		}
		printf("\n");
	}
}