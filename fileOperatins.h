#include <stdio.h>
void encryptFileByVinegre(const char* FILE_NAME);
FILE* openFileToRead(const char* FILE_NAME, bool displayErrors);
FILE* openFileToWrite(const char* FILE_NAME);
bool overwriteConfirmationRequest(const char* FILE_NAME);
void clearFile(const char* FILE_NAME, FILE* file);