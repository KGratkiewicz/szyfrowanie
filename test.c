#include <stdio.h>
#include <string.h>
#include "matrixOperations.h"
#include "VinegereCipher.h"
#include "global.h"
#include "menu.h"
#include "fileOperatins.h"

void test_allocMatrixOfChar_createVigenerateAlfabet()
{
	char** matrix = allocMatrixOfChar(26, 26);
	createVigenereAlfabetMatix(matrix);
	printMatrixOfChar(matrix, 26, 26);
	freeMatrixOfChar(matrix, 26);
}

void test_encryptVigenereCipher()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";
	
	encryptVigenereCipher(text, key);

	printf(text);

}

void test_encryptChar()
{
	printf(" %c", encryptChar('a', 'a'));
}

void test_setValueOfCoordinate_RetCoord()
{
	int test_int = calculateAplhabetCoord('K');
	printf(" %d", test_int);
}

void test_decryptVingereCipher()
{
	char text[] = "ABCDABCDABCD";
	char key[] = "abcd";

	decryptVingereCipher(text, key);

	printf(text);

}

void test_encryptDecryptVignereCipher()
{
	char text[100], key[100], tmpText[100], newKey[100];
	printf("Enter text: ");
	fflush(stdin);
	gets(text);
	printf("Enter key: ");
	fflush(stdin);
	gets(key);

	printf("Oryginal: %s\n", text);

	encryptVigenereCipher(text, key);
	printf("Encrypted: %s\n", text);

	strcpy_s(tmpText, strlen(text)+1, text);

	decryptVingereCipher(text, key);
	printf("Decrypted by key: %s\n", text);

	printf("Enter new key: ");
	fflush(stdin);
	gets(newKey);

	decryptVingereCipher(tmpText, newKey);
	printf("Decrypted by new key: %s\n", tmpText);

}

void test_global()
{
	printf("%c %d", FIRST_ALFABET_UPPER_LETTER, ALPHABET_LENGTH);
}

void test_display()
{
	for (int i = 0; i < opt_exit + 1; i++)
	{
		displayMainMenu(i);
		system("pause");
		system("cls");
	}
	

}

void test_menuNaviation()
{
	mainMenuNavigation();
}

void test_ascii()
{
	for (int i = 10; i != 'a'; )
	{
		i = getch();
		printf(" %d", i);
	}
}

void test_openToWrite()
{
	openFileToWrite("test.txt");

}

void test_encryptFileByVinegre()
{
	encryptFileByVinegre("test.txt", "resoult.txt", "KRYPTO");
}