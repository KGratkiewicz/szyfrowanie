
enum menuOption {opt_shiftCipher, opt_VinegreCipher, opt_exit};
enum controlVariable { cntrl_Enter = 13 ,cntrl_Up =72 , cntrl_Down = 80  };

void displayMainMenu(enum menuOption);
void displaySelectedOption(const char*);
void menuNavigation();
void execute(enum menuOption);