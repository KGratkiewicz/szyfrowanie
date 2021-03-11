#include <iostream>
#include <ctype.h>
#include "VinegereChiper.h"
#include "matrixOperations.h"
#include "stringFormating.h"

void encryptVigenereChiper(char* text, char* key)
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

	char revelantChar = alfabetMatrix[valueTextCharCoordinate][valueKeyCharCoordinate];

	alfabetMatrix = freeMatrixOfChar_RetNullptr(alfabetMatrix, 26);

	return revelantChar;

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

void decryptVingereChiper(char* text, char* key)
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
	int differenceBetwentextCharkeyChar = textChar - keyChar;

	if (differenceBetwentextCharkeyChar < 0)
		differenceBetwentextCharkeyChar += 26;

	char revelantChar = 'A' + differenceBetwentextCharkeyChar;

	return revelantChar;
}




