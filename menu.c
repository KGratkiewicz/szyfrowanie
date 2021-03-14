#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "menu.h"
#include "stringFormating.h"
#include "fileOperatins.h"

#define	WHITE 15
#define MAX_BUFFER_SIZE 256

void displayMainMenu(enum mainMenuOption option)
{
	printf("-----------------------------------------------------\n");
	printf("|                       MENU                        |\n");
	printf("|---------------------------------------------------|\n");
	if (option == opt_shiftCipher)
	{
		displaySelectedOption("|                >> SHIFT CIPHER <<                 |\n");
	}
	else
	{
	printf("|                   Shift Cipher                    |\n");
	}
	if (option == opt_VinegreCipher)
	{
		displaySelectedOption("|               >> VINEGRE CIPHER <<                |\n");
	}
	else
	{
	printf("|                  Vinegre Cipher                   |\n");
	}
	if (option == opt_exit)
	{
		displaySelectedOption("|                    >> EXIT <<                     |\n");
	}
	else
	{
		printf("|                       exit                        |\n");
	}
	printf("-----------------------------------------------------\n");
}

void displaySelectedOption(const char* TEXT)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
	printf(TEXT);
	SetConsoleTextAttribute(hOut, COLOR_BACKGROUND);
	SetConsoleTextAttribute(hOut, WHITE);
}

void mainMenuNavigation()
{
	enum mainMenuOption currentPointerIsThere = 0;
	while (1)
	{
		system("cls");
		displayMainMenu(currentPointerIsThere);
			fflush(stdin);
		enum controlVariable navigationVariable = getch();
		switch (navigationVariable)
		{
		case cntrl_Enter:
			executeMainMenuOption(currentPointerIsThere);
			break;
		case cntrl_Up:
			currentPointerIsThere = (currentPointerIsThere==0) ? opt_exit: currentPointerIsThere-1;
			break;
		case cntrl_Down:
			currentPointerIsThere = (currentPointerIsThere == opt_exit) ? 0 : currentPointerIsThere + 1;
			break;
		default:
			break;
		}
	}
	
}

void executeMainMenuOption(enum mainMenuOption chosenOption)
{
	switch (chosenOption)
	{
	case opt_shiftCipher: case opt_VinegreCipher:
		cipherMenuNavigation(chosenOption);
		break;
	case opt_exit:
		exit(0);
		break;
	default:
		break;
	}
}

void displayCipherMenu(enum cipherMenuOption curentOption, enum mainMenuOption cipherChosen)
{
	printf("-----------------------------------------------------\n");
	switch (cipherChosen)
	{
	case opt_shiftCipher:
		printf("|                   SHIFT CIPHER                    |\n");
		break;
	case opt_VinegreCipher:
		printf("|                 VINEGERE CIPHER                   |\n");
		break;
	default:
		break;
	}
	
	printf("|---------------------------------------------------|\n");
	if (curentOption == opt_encrypt)
	{
		displaySelectedOption("|                >> ENCRYPT FILE <<                 |\n");
	}
	else
	{
		printf("|                   Encrypt File                    |\n");
	}
	if (curentOption == opt_decrypt)
	{
		displaySelectedOption("|                >> DECRYPT FILE <<                 |\n");
	}
	else
	{
		printf("|                   Decrypt File                    |\n");
	}
	if (curentOption == opt_back)
	{
		displaySelectedOption("|                >> BACK TO MENU <<                 |\n");
	}
	else
	{
		printf("|                   Back to menu                    |\n");
	}
	printf("-----------------------------------------------------\n");
}

void cipherMenuNavigation(enum mainMenuOption cipherChosen)
{
	enum cipherMenuOption currentPointerIsThere = 0;
	bool end = false;
	while (!end)
	{
		system("cls");
		displayCipherMenu(currentPointerIsThere,cipherChosen);
		fflush(stdin);
		enum controlVariable navigationVariable = getch();
		switch (navigationVariable)
		{
		case cntrl_Enter:
			executeCipherMenuOption(currentPointerIsThere, cipherChosen);
			if (currentPointerIsThere == opt_back)
			{
				end = true;
			}
			break;
		case cntrl_Up:
			currentPointerIsThere = (currentPointerIsThere == 0) ? opt_back : currentPointerIsThere - 1;
			break;
		case cntrl_Down:
			currentPointerIsThere = (currentPointerIsThere == opt_back) ? 0 : currentPointerIsThere + 1;
			break;
		default:
			break;
		}
	}
}

void executeCipherMenuOption(enum cipherMenuOption chosenOption, enum mainMenuOption cipherChosen)
{
	switch (chosenOption)
	{
	case opt_encrypt:
		encryptFile(cipherChosen);
		break;
	case opt_decrypt:

		break;
	default:
		break;
	}
}

void encryptFile(enum mainMenuOption cipherChosen)
{
	switch (cipherChosen)
	{
	case opt_shiftCipher:
		ShiftEncryptOption();
		break;
	case opt_VinegreCipher:
		VinegreEncryptOption();
		break;
	default:
		break;
	}
}

void decryptFile(enum mainMenuOption cipherChosen)
{
	switch (cipherChosen)
	{
	case opt_shiftCipher:
		break;
	case opt_VinegreCipher:
		break;
	default:
		break;
	}

}

void VinegreEncryptOption()
{
	char sourceFileName[MAX_BUFFER_SIZE];
	char key[MAX_BUFFER_SIZE];
	char resoultFileName[MAX_BUFFER_SIZE];

	fflush(stdin);
	printf("Insert source file name: ");
	fgets(sourceFileName, MAX_BUFFER_SIZE, stdin);
	sourceFileName[strlen(sourceFileName) - 1] = 0;
	
	fflush(stdin);
	printf("Insert resoult file name: ");
	fgets(resoultFileName, MAX_BUFFER_SIZE, stdin);
	resoultFileName[strlen(resoultFileName) - 1] = 0;

	fflush(stdin);
	printf("Insert key: ");
	fgets(key, MAX_BUFFER_SIZE, stdin);
	key[strlen(key) - 1] = 0;
	transformToUpper(key);

	encryptFileByVinegre(sourceFileName, resoultFileName, key);
}

void ShiftEncryptOption()
{
	char sourceFileName[MAX_BUFFER_SIZE];
	int key;
	char resoultFileName[MAX_BUFFER_SIZE];

	fflush(stdin);
	printf("Insert source file name: ");
	fgets(sourceFileName, MAX_BUFFER_SIZE, stdin);
	sourceFileName[strlen(sourceFileName) - 1] = 0;

	fflush(stdin);
	printf("Insert resoult file name: ");
	fgets(resoultFileName, MAX_BUFFER_SIZE, stdin);
	resoultFileName[strlen(resoultFileName) - 1] = 0;

	printf("Insert key: ");
	scanf_s(" %d", &key);


	

	encryptFileByShift(sourceFileName, resoultFileName, key);
}