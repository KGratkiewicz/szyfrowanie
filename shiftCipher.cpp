#include <iostream>
#include <ctype.h>
#include "shiftCipher.h"

void encryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = 'a' + ((text[i] - 'a') + key) % 26;
        else if (isupper(text[i]))
            text[i] = 'A' + ((text[i] - 'A') + key) % 26;
    }
}

void decryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = 'a' + ((text[i] - 'a') - key) % 26;
        else if (isupper(text[i]))
            text[i] = 'A' + ((text[i] - 'A') - key) % 26;
    }
}