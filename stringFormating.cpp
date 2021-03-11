#include <iostream>
#include <ctype.h>
#include "stringFormating.h"

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

