#include <iostream>
#include <cstring>
#include "matrixOperations.h"
#include "VinegereChiper.h"

void test_allocMatrixOfChar_createVigenerateAlfabet()
{
	char** matrix = allocMatrixOfChar_RetPtr(26, 26);
	createVigenereAlfabetMatix(matrix);
	printMatrixOfChar(matrix, 26, 26);
	matrix = freeMatrixOfChar_RetNullptr(matrix, 26);
}

void test_encryptVigenereChiper()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";
	
	encryptVigenereChiper(text, key);

	printf(text);

}

void test_encryptChar_RetChar()
{
	printf(" %c", encryptChar_RetChar('a', 'a'));
}

void test_setValueOfCoordinate_RetCoord()
{
	int test_int = setValueOfCoordinate_RetCoord('K');
	printf(" %d", test_int);
}

void test_decryptVingereChiper()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";

	decryptVingereChiper(text, key);

	printf(text);

}

void test_encryptDecryptVignereChip()
{
	char text[100], key[100], tmpText[100], newKey[100];
	printf("Enter text: ");
	fflush(stdin);
	gets_s(text);
	printf("Enter key: ");
	fflush(stdin);
	gets_s(key);
	
	printf("Oryginal: %s\n", text);

	encryptVigenereChiper(text, key);
	printf("Encrypted: %s\n", text);

	strcpy_s(tmpText, text);

	decryptVingereChiper(text, key);
	printf("Decrypted by key: %s\n", text);
	
	printf("Enter new key: ");
	fflush(stdin);
	gets_s(newKey);

	decryptVingereChiper(tmpText, newKey);
	printf("Decrypted by new key: %s\n", tmpText);



}