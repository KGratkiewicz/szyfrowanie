# Szyfrowanie
Projekt ku czci dobrego kodu. Pierwsze podejście do programowania po przeczytaniu książki "Clean Code" Roberta C. Martina. 

### Środowisko 
Program stworzony za pomocą IDE udostępnianego przez [Microsoft](https://www.microsoft.com/pl-pl?SilentAuth=1&wa=wsignin1.0) -> [Visual Studio](https://visualstudio.microsoft.com/pl/)


## Nawigacja menu za pomocą strzałek menu.h/.c
Chyba najciekawszy fragment kodu programu - pomysł własny.
```
void mainMenuNavigation()
{
	enum mainMenuOption currentPointerIsThere = 0;
	while (1)
	{
		system("cls");
		displayMainMenu(currentPointerIsThere);
			fflush(stdin);
		enum controlVariable navigationVariable = getch();
		switch (navigationVariable)
		{
		case cntrl_Enter:
			executeMainMenuOption(currentPointerIsThere);
			break;
		case cntrl_Up:
			currentPointerIsThere = (currentPointerIsThere==0) ? opt_exit: currentPointerIsThere-1;
			break;
		case cntrl_Down:
			currentPointerIsThere = (currentPointerIsThere == opt_exit) ? 0 : currentPointerIsThere + 1;
			break;
		default:
			break;
		}
	}
	
}

```

Nie jest on bezbłędny - pozostanie zapewne porzucony, ale oby nie zapomniany.
`+ do doświadczenia` `+ do kreatywności`

***
&copy; Jakub Grątkiewicz
