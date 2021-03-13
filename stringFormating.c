#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "stringFormating.h"
#include "global.h"

void transformToUpper(char* text)
{
	for (int i = 0; text[i]; i++)
	{
		text[i] = toupper(text[i]);
	}
}

void transformToLower(char* text)
{
	for (int i = 0; text[i]; i++)
	{
		text[i] = tolower(text[i]);
	}
}

bool isLetter(char theChar)
{
	if (theChar >= FIRST_ALFABET_UPPER_LETTER && theChar <= LAST_ALFABET_UPPER_LETTER)
	{
		return true;
	}
	if (theChar >= FIRST_ALFABET_LOWER_LETTER && theChar <= LAST_ALFABET_LOWER_LETTER)
	{
		return true;
	}
	return false;
}
