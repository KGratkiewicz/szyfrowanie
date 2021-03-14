#include <stdbool.h>
void encryptFileByVinegre(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, char* key);
FILE* openFileToRead(const char* FILE_NAME, bool displayErrors);
FILE* openFileToWrite(const char* FILE_NAME, bool displayErrors);
bool overwriteConfirmationRequest(const char* FILE_NAME);
void clearFile(const char* FILE_NAME, FILE* file);
void encryptFileByShift(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, int key);
void decryptFileByVinegre(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, char* key);
void decryptFileByShift(const char* SOURCE_FILE_NAME, const char* RESOULT_FILE_NAME, int key);
