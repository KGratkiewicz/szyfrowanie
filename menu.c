#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "menu.h"

#define	 WHITE 15

void displayMainMenu(enum menuOption option)
{
	printf("-----------------------------------------------------\n");
	printf("|---------------------- MENU -----------------------|\n");
	printf("|---------------------------------------------------|\n");
	if (option == shiftCipher)
	{
		displaySelectedOption("|                >> Shift Cipher <<                 |\n");
	}
	else
	{
	printf("|                   shift cipher                    |\n");
	}
	if (option == VinegreCipher)
	{
		displaySelectedOption("|               >> Vinegre Cipher <<                |\n");
	}
	else
	{
	printf("|                  Vinegre Cipher                   |\n");
	}
	printf("-----------------------------------------------------\n");
}

void displaySelectedOption(const char* text)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_GREEN);
	printf(text);
	SetConsoleTextAttribute(hOut, COLOR_BACKGROUND);
	SetConsoleTextAttribute(hOut, WHITE);
}