#include <iostream>

char** allocMatrixOfChar_RetPtr(int width, int height);
char** freeMatrixOfChar_RetNullptr(char** matrix, int height);
void printMatrixOfChar(char** matrix, int width, int height);