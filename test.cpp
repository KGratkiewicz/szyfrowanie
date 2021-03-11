#include <iostream>
#include <cstring>
#include "matrixOperations.h"
#include "VinegereCipher.h"

void test_allocMatrixOfChar_createVigenerateAlfabet()
{
	char** matrix = allocMatrixOfChar_RetPtr(26, 26);
	createVigenereAlfabetMatix(matrix);
	printMatrixOfChar(matrix, 26, 26);
	matrix = freeMatrixOfChar_RetNullptr(matrix, 26);
}

void test_encryptVigenereCipher()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";
	
	encryptVigenereCipher(text, key);

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

void test_decryptVingereCipher()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";

	decryptVingereCipher(text, key);

	printf(text);

}

void test_encryptDecryptVignereCipher()
{
	char text[100], key[100], tmpText[100], newKey[100];
	printf("Enter text: ");
	fflush(stdin);
	gets_s(text);
	printf("Enter key: ");
	fflush(stdin);
	gets_s(key);
	
	printf("Oryginal: %s\n", text);

	encryptVigenereCipher(text, key);
	printf("Encrypted: %s\n", text);

	strcpy_s(tmpText, text);

	decryptVingereCipher(text, key);
	printf("Decrypted by key: %s\n", text);
	
	printf("Enter new key: ");
	fflush(stdin);
	gets_s(newKey);

	decryptVingereCipher(tmpText, newKey);
	printf("Decrypted by new key: %s\n", tmpText);



}