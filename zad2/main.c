#include <stdio.h>
#include <stdlib.h>

int losuj()
{
	return (rand());
}

int wpiszDoPlik1(FILE *plik, int n, int tab[])
{
    for(int i = 0; i<n; i++)
    {
        tab[i] = losuj();
    }
    for(int i = 0; i<n; i++)
    {
        fprintf(plik, "%d ", tab[i]);
    }
    fclose(plik);
}

int wypiszLiczby(FILE *plik, int n, int tab[])
{
    for(int i = 0; i<n; i++)
    {
        fscanf(plik, "%d", &tab[i]);
    }

    printf("Podane liczby to: \n");
    int b;
    int k = 0;
    if ( n % 10 != 0 )
    {
        b = n/10 + 1;
    }
    else
    {
        b = n/10;
    }

    for(int i = 0; i<b; i++)
    {
        for(int j = 0; j<10; j++)
        {
           printf("%d ", tab[k]);
           k++;
           if (tab[k] == NULL)
           {
              break;
           }
        }
        printf("\n");
    }
    fclose(plik);
}

int wypiszLiczby2(FILE *plik2, int n, int tab[])
{

    printf("Posortowane liczby to: \n");
    int b;
    int k = 0;
    if ( n % 10 != 0 )
    {
        b = n/10 + 1;
    }
    else
    {
        b = n/10;
    }

    for(int i = 0; i<b; i++)
    {
        for(int j = 0; j<10; j++)
        {
           printf("%d ", tab[k]);
           k++;
           if (tab[k] == NULL)
           {
              break;
           }
        }
        printf("\n");
    }
}

int swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int sortuj(int tab[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (tab[j] > tab[j+1])
            swap(&tab[j], &tab[j+1]);
        }
    }

}

int wpiszDoPlik2(FILE *plik2, int n, int tab[])
{
    for(int i = 0; i<n; i++)
    {
        fprintf(plik2, "%d ", tab[i]);
    }
    fclose(plik2);
}

int main()
{
    srand(time(0));
    FILE *plik = NULL;
    FILE *plik2 = NULL;
    char nazwa[50];
    char nazwa2[50];
    int n = 100;
    printf("Podaj nazwe pliku 1: ");
    gets(nazwa);
    printf("Podaj nazwe pliku 2: ");
    gets(nazwa2);

    plik = fopen(nazwa,"r");

    plik2 = fopen(nazwa2,"w");

    printf("Podaj ile losowych liczb wpisac do pliku 1: ");
    scanf("%d", &n);
    int tab[n];
    wpiszDoPlik1(plik, n, tab);

    plik = fopen(nazwaPliku,"r");
    wypiszLiczby(plik, n, tab);

    sortuj(tab, n);

    wypiszLiczby2(plik2, n, tab);

    wpiszDoPlik2(plik2, n, tab);


    return 0;
}
