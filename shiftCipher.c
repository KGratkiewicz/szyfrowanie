#include <stdio.h>
#include <ctype.h>
#include "shiftCipher.h"
#include "global.h"

void encryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = FIRST_ALFABET_LOWER_LETTER + ((text[i] - FIRST_ALFABET_LOWER_LETTER) + key) % ALPHABET_LENGTH;
        else if (isupper(text[i]))
            text[i] = FIRST_ALFABET_UPPER_LETTER + ((text[i] - FIRST_ALFABET_UPPER_LETTER) + key) % ALPHABET_LENGTH;
    }
}

void decryptShiftCipher(char* text, int key)
{
    for (int i = 0; text[i]; i++)
    {
        if (islower(text[i]))
            text[i] = FIRST_ALFABET_LOWER_LETTER + ((text[i] - FIRST_ALFABET_LOWER_LETTER) - key) % ALPHABET_LENGTH;
        else if (isupper(text[i]))
            text[i] = FIRST_ALFABET_UPPER_LETTER + ((text[i] - FIRST_ALFABET_UPPER_LETTER) - key) % ALPHABET_LENGTH;
    }
}