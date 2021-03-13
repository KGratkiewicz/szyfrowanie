#include <stdio.h>
#include <stdbool.h>
#include "fileOperatins.h"
#include "VinegereCipher.h"
#include "stringFormating.h"

#define ENTER 13
#define ESC 27

void encryptFileByVinegre(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, char* key)
{
	FILE* sourceFile = openFileToRead(SOURCE_FILE_NAME, true);
	FILE* resoultFile = openFileToWrite(RESOULT_FILE_NAME);

	char fileChar;
	int keySize = strlen(key);
	for (int keyIndex=0;fscanf_s(sourceFile, "%c", &fileChar)!=EOF; keyIndex++)
	{
		if (keyIndex >= keySize)
		{
			keyIndex = 0;
		}

		if (isLetter(fileChar))
		{
			char encryptedChar = encryptChar(fileChar, key[keyIndex]);
			fprintf(resoultFile, "%c", encryptedChar);
		}
		else
		{
			fprintf(resoultFile, "%c", fileChar);
			keyIndex--;
		}
		
	}
	
	fclose(sourceFile);
	fclose(resoultFile);
}

FILE* openFileToRead(const char* FILE_NAME, bool displayErrors)
{
	FILE* file;
	fopen_s(&file, FILE_NAME, "r");
	if (!file && displayErrors)
	{
		fprintf(stderr, "Cannot open %s file.", FILE_NAME);
	}
	return file;
}

FILE* openFileToWrite(const char* FILE_NAME)
{
	FILE* file = openFileToRead(FILE_NAME, false);
	bool openToWrite = true;
	if (file)
	{
		openToWrite = overwriteConfirmationRequest(FILE_NAME);
	}
	if (openToWrite)
	{
		clearFile(FILE_NAME, file);
		fopen_s(&file, FILE_NAME, "w+");
	}
	else
	{
		fclose(file);
	}
	return file;
}

bool overwriteConfirmationRequest(const char* FILE_NAME)
{
	printf("File %s already exists. Do you want to overwrite if?\n", FILE_NAME);
	printf("YES - Enter | NO - Escape\n");
	for (;;)
	{
		fflush(stdin);
		int choice = getch();
		switch (choice)
		{
		case ENTER:
			return true;
		case ESC:
			return false;
		default:
			break;
		}
	}
	
}

void clearFile(const char* FILE_NAME, FILE* file)
{
	if (file)
	{
		fclose(file);

	}
	fopen_s(&file, FILE_NAME, "w");
	fclose(file);
}
