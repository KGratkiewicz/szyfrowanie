#include <stdio.h>
#include <stdbool.h>
#include "fileOperatins.h"
#include "VinegereCipher.h"
#include "stringFormating.h"
#include "shiftCipher.h"

#define ENTER 13
#define ESC 27
#define MAX_BUFFER_SIZE 256

void encryptFileByVinegre(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, char* key)
{
	FILE* sourceFile = openFileToRead(SOURCE_FILE_NAME, true);
	if (sourceFile)
	{
		FILE* resoultFile = openFileToWrite(RESOULT_FILE_NAME, true);
		if (resoultFile)
		{
			char fileChar;
			int keySize = strlen(key);
			for (int keyIndex = 0; fscanf_s(sourceFile, "%c", &fileChar) != EOF; keyIndex++)
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
			printf("Encryption succes: %s -> %s.\n", SOURCE_FILE_NAME, RESOULT_FILE_NAME);
			system("pause");

			fclose(resoultFile);
		}
		
		fclose(sourceFile);
		
	}
	
}

FILE* openFileToRead(const char* FILE_NAME, bool displayErrors)
{
	FILE* file;
	fopen_s(&file, FILE_NAME, "r");
	if (!file && displayErrors)
	{
		fprintf(stderr, "Cannot open %s file.\n", FILE_NAME);
		system("pause");
	}
	return file;
}

FILE* openFileToWrite(const char* FILE_NAME, bool displayErrors)
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
		if (displayErrors)
		{
			printf("Encryption canceled.\n");
			system("pause");
		}
		return NULL;
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

void encryptFileByShift(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, int key)
{
	FILE* sourceFile = openFileToRead(SOURCE_FILE_NAME, true);
	if (sourceFile)
	{
		FILE* resoultFile = openFileToWrite(RESOULT_FILE_NAME, true);
		if (resoultFile)
		{
			char fileString[MAX_BUFFER_SIZE];
			while (fgets(fileString, MAX_BUFFER_SIZE, sourceFile))
			{
			
				encryptShiftCipher(fileString, key);

				fprintf(resoultFile, "%s", fileString);
			}
			printf("Encryption succes: %s -> %s.\n", SOURCE_FILE_NAME, RESOULT_FILE_NAME);
			system("pause");

			fclose(resoultFile);
		}

		fclose(sourceFile);

	}

}

void decryptFileByVinegre(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, char* key)
{
	FILE* sourceFile = openFileToRead(SOURCE_FILE_NAME, true);
	if (sourceFile)
	{
		FILE* resoultFile = openFileToWrite(RESOULT_FILE_NAME, true);
		if (resoultFile)
		{
			char fileChar;
			int keySize = strlen(key);
			for (int keyIndex = 0; fscanf_s(sourceFile, "%c", &fileChar) != EOF; keyIndex++)
			{
				if (keyIndex >= keySize)
				{
					keyIndex = 0;
				}

				if (isLetter(fileChar))
				{
					char encryptedChar = decryptChar(fileChar, key[keyIndex]);
					fprintf(resoultFile, "%c", encryptedChar);
				}
				else
				{
					fprintf(resoultFile, "%c", fileChar);
					keyIndex--;
				}

			}
			printf("Decryption succes: %s -> %s.\n", SOURCE_FILE_NAME, RESOULT_FILE_NAME);
			system("pause");

			fclose(resoultFile);
		}

		fclose(sourceFile);

	}

}

void decryptFileByShift(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, int key)
{
	FILE* sourceFile = openFileToRead(SOURCE_FILE_NAME, true);
	if (sourceFile)
	{
		FILE* resoultFile = openFileToWrite(RESOULT_FILE_NAME, true);
		if (resoultFile)
		{
			char fileString[MAX_BUFFER_SIZE];
			while (fgets(fileString, MAX_BUFFER_SIZE, sourceFile))
			{

				decryptShiftCipher(fileString, key);

				fprintf(resoultFile, "%s", fileString);
			}
			printf("Encryption succes: %s -> %s.\n", SOURCE_FILE_NAME, RESOULT_FILE_NAME);
			system("pause");

			fclose(resoultFile);
		}

		fclose(sourceFile);

	}

}