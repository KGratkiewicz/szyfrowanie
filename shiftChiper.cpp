#include <iostream>
#include <ctype.h>
#include "shiftChiper.h"

void encryptShiftChiper(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = 'a' + ((text[i] - 'a') + key) % 26;
        else if (isupper(text[i]))
            text[i] = 'A' + ((text[i] - 'A') + key) % 26;
    }
}

void decryptShiftChiper(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = 'a' + ((text[i] - 'a') - key) % 26;
        else if (isupper(text[i]))
            text[i] = 'A' + ((text[i] - 'A') - key) % 26;
    }
}