#include <stdio.h>
#include <stdlib.h>

int losuj()
{
	return (rand());
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

int wpiszDoPlik1(FILE *plik, int a, int tab[])
{
    for(int i = 0; i<a; i++)
    {
        tab[i] = losuj();
    }
    sortuj(tab, a);
    for(int i = 0; i<a; i++)
    {
        fprintf(plik, "%d ", tab[i]);
    }
    fclose(plik);
}

int wpiszDoPlik2(FILE *plik2, int b, int tab2[])
{
    for(int i = 0; i<b; i++)
    {
        tab2[i] = losuj();
    }
    sortuj(tab2, b);
    for(int i = 0; i<b; i++)
    {
        fprintf(plik2, "%d ", tab2[i]);
    }
    fclose(plik2);
}

int wpiszDoPlik3(FILE *plik3, int a, int b, int tab[], int tab2[])
{
    for(int i = 0; i<a; i++)
    {
        fprintf(plik3, "%d ", tab[i]);
    }
    for(int i = 0; i<b; i++)
    {
        fprintf(plik3, "%d ", tab2[i]);
    }
    fclose(plik3);
}

int wpiszDoPlik32(FILE *plik3, int n, int tab3[])
{
    for(int i = 0; i<n; i++)
    {
        fprintf(plik3, "%d ", tab3[i]);
    }
}

int zapisz(FILE *plik3, int n, int tab3[])
{
    for(int i = 0; i<n; i++)
    {
        fscanf(plik3, "%d", &tab3[i]);
    }
    sortuj(tab3, n);
    printf("Podane liczby to: \n");
    int s;
    int k = 0;
    if ( n % 10 != 0 )
    {
        s = n/10 + 1;
    }
    else
    {
        s = n/10;
    }

    for(int i = 0; i<s; i++)
    {
        for(int j = 0; j<10; j++)
        {
           printf("%d ", tab3[k]);
           k++;
           if (tab3[k] == NULL)
           {
              break;
           }
        }
        printf("\n");
    }
    fclose(plik3);
}

int main()
{
    srand(time(0));
    FILE *plik = NULL;
    FILE *plik2 = NULL;
    FILE *plik3 = NULL;
    char nazwa[50];
    char nazwaPliku[50];
    char nazwa2[50];
    char nazwaPliku2[50];
    char nazwa3[50];
    char nazwaPliku3[50];
    int a,b;
    int n;

    printf("Podaj nazwe pliku 1: ");
    gets(nazwa);
    printf("Podaj nazwe pliku 2: ");
    gets(nazwa2);
    printf("Podaj nazwe pliku 3: ");
    gets(nazwa3);

    sprintf(nazwaPliku, "%s.txt", nazwa);
    plik = fopen(nazwaPliku,"w");
    sprintf(nazwaPliku2, "%s.txt", nazwa2);
    plik2 = fopen(nazwaPliku2,"w");
    sprintf(nazwaPliku3, "%s.txt", nazwa3);
    plik3 = fopen(nazwaPliku3,"w");

    printf("Podaj ile losowych liczb wpisac do pliku 1: ");
    scanf("%d", &a);
    int tab[a];
    printf("Podaj ile losowych liczb wpisac do pliku 2: ");
    scanf("%d", &b);
    int tab2[b];
    n = a+b;
    int tab3[n];
    wpiszDoPlik1(plik, a, tab);
    wpiszDoPlik2(plik2, b, tab2);
    wpiszDoPlik3(plik3, a, b, tab, tab2);
    plik3 = fopen(nazwaPliku3,"r");
    zapisz(plik3, n, tab3);
    plik3 = fopen(nazwaPliku3,"w");
    wpiszDoPlik32(plik3, n, tab3);

    return 0;
}
