#include <stdio.h>
#include <ctype.h>
#include "VinegereCipher.h"
#include "matrixOperations.h"
#include "stringFormating.h"
#include "global.h"

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
		text[textIndex] = encryptChar(text[textIndex], key[keyIndex]);
	}
}

char encryptChar(char textChar, char keyChar)
{
	char** alfabetMatrix = allocMatrixOfChar(ALPHABET_LENGTH, ALPHABET_LENGTH);
	createVigenereAlfabetMatix(alfabetMatrix);

	int textCharCoordinate = calculateAplhabetCoord(textChar);
	int keyCharCoordinate = calculateAplhabetCoord(keyChar);

	char relevantChar = alfabetMatrix[textCharCoordinate][keyCharCoordinate];

	freeMatrixOfChar(alfabetMatrix, ALPHABET_LENGTH);

	return relevantChar;

}

void createVigenereAlfabetMatix(char** alfabetMatrix)
{
	for (int i = 0; i < ALPHABET_LENGTH; i++)
	{
		for (int j = 0; j < ALPHABET_LENGTH; j++)
		{
			if (alfabetMatrix)
			{
				char revelantChar = (j + i) % ALPHABET_LENGTH + FIRST_ALFABET_UPPER_LETTER;
				alfabetMatrix[i][j] = revelantChar;
			}
		}
	}
}

int calculateAplhabetCoord(char argChar)
{
	return (argChar - FIRST_ALFABET_UPPER_LETTER) % ALPHABET_LENGTH;
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
		text[textIndex] = decryptChar(text[textIndex], key[keyIndex]);
	}


}

char decryptChar(char textChar, char keyChar)
{
	
	int valueKeyCharCoordinate = calculateAplhabetCoord(keyChar);
	int differenceBetwenTextCharKeyChar = textChar - keyChar;

	if (differenceBetwenTextCharKeyChar < 0)
		differenceBetwenTextCharKeyChar += ALPHABET_LENGTH;

	return  FIRST_ALFABET_UPPER_LETTER + differenceBetwenTextCharKeyChar;
}




