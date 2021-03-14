
enum mainMenuOption {opt_shiftCipher, opt_VinegreCipher, opt_exit};
enum controlVariable { cntrl_Enter = 13 ,cntrl_Up =72 , cntrl_Down = 80  };
enum cipherMenuOption {opt_encrypt, opt_decrypt, opt_back};

void displayMainMenu(enum mainMenuOption);
void displayCipherMenu(enum cipherMenuOption);
void displaySelectedOption(const char*);
void mainMenuNavigation();
void cipherMenuNavigation(enum mainMenuOption);
void executeMainMenuOption(enum mainMenuOption);
void executeCipherMenuOption(enum cipherMenuOption, enum mainMenuOption);
void encryptFile(enum mainMenuOption);
void decryptFile(enum mainMenuOption);
void VinegreOption(enum cipherMenuOption cipherOption);
void ShiftOption(enum cipherMenuOption cipherOption);