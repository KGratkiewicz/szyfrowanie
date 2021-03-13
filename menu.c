#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"

#define	 WHITE 15

void displayMainMenu(enum menuOption option)
{
	printf("-----------------------------------------------------\n");
	printf("|                       MENU                        |\n");
	printf("|---------------------------------------------------|\n");
	if (option == opt_shiftCipher)
	{
		displaySelectedOption("|                >> Shift Cipher <<                 |\n");
	}
	else
	{
	printf("|                   shift cipher                    |\n");
	}
	if (option == opt_VinegreCipher)
	{
		displaySelectedOption("|               >> Vinegre Cipher <<                |\n");
	}
	else
	{
	printf("|                  Vinegre Cipher                   |\n");
	}
	if (option == opt_exit)
	{
		displaySelectedOption("|                    >> exit <<                     |\n");
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

void menuNavigation()
{
	enum menuOption currentPointerIsThere = 0;
	while (1)
	{
		system("cls");
		displayMainMenu(currentPointerIsThere);
			fflush(stdin);
		enum controlVariable navigationVariable = getch();
		switch (navigationVariable)
		{
		case cntrl_Enter:
			execute(currentPointerIsThere);
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

void execute(enum menuOption chosenOption)
{
	switch (chosenOption)
	{
	case opt_shiftCipher:
		break;
	case opt_VinegreCipher:
		break;
	case opt_exit:
		exit(0);
		break;
	default:
		break;
	}
}

