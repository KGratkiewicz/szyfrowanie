#include <iostream>
#include <ctype.h>
#include "shiftCipher.h"
#include "global.h"

void encryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = firstAlfabetLowerLetter + ((text[i] - firstAlfabetLowerLetter) + key) % alphabetLength;
        else if (isupper(text[i]))
            text[i] = firstAlfabetUpperLetter + ((text[i] - firstAlfabetUpperLetter) + key) % alphabetLength;
    }
}

void decryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = firstAlfabetLowerLetter + ((text[i] - firstAlfabetLowerLetter) - key) % alphabetLength;
        else if (isupper(text[i]))
            text[i] = firstAlfabetUpperLetter + ((text[i] - firstAlfabetUpperLetter) - key) % alphabetLength;
    }
}