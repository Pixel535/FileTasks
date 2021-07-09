#include <stdio.h>
#include <stdlib.h>

int losuj(int a, int b)
{
	return (rand()%(b-a+1)+a);
}

int wypelnij(FILE *plik, int a, int b, int n)
{
    int tab[n];
    for(int i = 0; i<n; i++)
    {
        tab[i] = losuj(a, b);
    }
    for(int i = 0; i<n; i++)
    {
        fprintf(plik, "%d ", tab[i]);
    }
    fclose(plik);
}

int main()
{
    srand(time(0));
    FILE *plik = NULL;
    char nazwa[50];
    printf("Podaj nazwe pliku: ");
    gets(nazwa);
    plik = fopen(nazwa,"w");


    int n;
    int a,b;
    printf("Podaj <a,b> przedzialu liczb oraz ile ich ma byc wpisanych w plik: \n");
    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("n: ");
    scanf("%d", &n);
    printf("Plik wypelniam %d losowymi liczbami z przedzialu <%d,%d> \n",  n, a, b);
    wypelnij(plik, a,b,n);
    printf("\n...Wypelniono...\n");
    return 0;
}
