#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nazwa[100];
    char sciezka[100];
    getcwd(sciezka,100);
    printf("Sciezka: %s\n", sciezka);
    printf("Podaj nazwe folderu do utworzenia: ");
    gets(nazwa);
    strcat(sciezka, nazwa);
    mkdir(sciezka);

    return 0;
}
