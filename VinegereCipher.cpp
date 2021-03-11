#include <iostream>
#include <ctype.h>
#include "VinegereCipher.h"
#include "matrixOperations.h"
#include "stringFormating.h"

void encryptVigenereCipher(char* text, char* key)
{
	transformToUpper(text);
	transformToUpper(key);

	int textSize = strlen(text);
	int keySize = strlen(key);

	for (int textIndex = 0, keyIndex = 0; textIndex < textSize; textIndex++, keyIndex++)
	{
		if (keyIndex >= keySize)
			keyIndex = 0;
		text[textIndex] = encryptChar_RetChar(text[textIndex], key[keyIndex]);
	}
}

char encryptChar_RetChar(char textChar, char keyChar)
{
	char** alfabetMatrix = nullptr;
	alfabetMatrix = allocMatrixOfChar_RetPtr(26, 26);
	createVigenereAlfabetMatix(alfabetMatrix);

	int valueTextCharCoordinate = setValueOfCoordinate_RetCoord(textChar);
	int valueKeyCharCoordinate = setValueOfCoordinate_RetCoord(keyChar);

	char relevantChar = alfabetMatrix[valueTextCharCoordinate][valueKeyCharCoordinate];

	alfabetMatrix = freeMatrixOfChar_RetNullptr(alfabetMatrix, 26);

	return relevantChar;

}

void createVigenereAlfabetMatix(char** alfabetMatrix)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (alfabetMatrix)
			{
				char revelantChar = (j + i) % 26 + 'A';
				alfabetMatrix[i][j] = revelantChar;
			}
		}
	}
}

int setValueOfCoordinate_RetCoord(char argChar)
{
	int coord = (argChar - 'A') % 26;
	return coord;
}

void decryptVingereCipher(char* text, char* key)
{
	transformToUpper(text);
	transformToUpper(key);

	int textSize = strlen(text);
	int keySize = strlen(key);

	for (int textIndex = 0, keyIndex = 0; textIndex < textSize; textIndex++, keyIndex++)
	{
		if (keyIndex >= keySize)
			keyIndex = 0;
		text[textIndex] = decryptChar_RetChar(text[textIndex], key[keyIndex]);
	}


}

char decryptChar_RetChar(char textChar, char keyChar)
{
	int valueKeyCharCoordinate = setValueOfCoordinate_RetCoord(keyChar);
	int differenceBetwenTextCharKeyChar = textChar - keyChar;

	if (differenceBetwenTextCharKeyChar < 0)
		differenceBetwenTextCharKeyChar += 26;

	char relevantChar = 'A' + differenceBetwenTextCharKeyChar;

	return relevantChar;
}




