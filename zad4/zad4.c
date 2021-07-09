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

int wpiszDoPlik3(FILE *plik3, int c, int tab3[])
{
    for(int i = 0; i<c; i++)
    {
        tab3[i] = losuj();
    }
    sortuj(tab3, c);
    for(int i = 0; i<c; i++)
    {
        fprintf(plik3, "%d ", tab3[i]);
    }
    fclose(plik3);
}

int wpiszDoPlik4(FILE *plik4, int d, int tab4[])
{
    for(int i = 0; i<d; i++)
    {
        tab4[i] = losuj();
    }
    sortuj(tab4, d);
    for(int i = 0; i<d; i++)
    {
        fprintf(plik4, "%d ", tab4[i]);
    }
    fclose(plik4);
}

int wpiszDoPlik5(FILE *plik5, int a, int b, int c, int d, int tab[], int tab2[], int tab3[], int tab4[])
{
    for(int i = 0; i<a; i++)
    {
        fprintf(plik5, "%d ", tab[i]);
    }
    for(int i = 0; i<b; i++)
    {
        fprintf(plik5, "%d ", tab2[i]);
    }
    for(int i = 0; i<c; i++)
    {
        fprintf(plik5, "%d ", tab3[i]);
    }
    for(int i = 0; i<d; i++)
    {
        fprintf(plik5, "%d ", tab4[i]);
    }
    fclose(plik5);
}

int wpiszDoPlik52(FILE *plik5, int n, int tab5[])
{
    for(int i = 0; i<n; i++)
    {
        fprintf(plik5, "%d ", tab5[i]);
    }
}

int zapisz(FILE *plik5, int n, int tab5[])
{
    for(int i = 0; i<n; i++)
    {
        fscanf(plik5, "%d", &tab5[i]);
    }
    sortuj(tab5, n);
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
           printf("%d ", tab5[k]);
           k++;
           if (tab5[k] == NULL)
           {
              break;
           }
        }
        printf("\n");
    }
    fclose(plik5);
}

int main()
{
    srand(time(0));
    FILE *plik = NULL;
    FILE *plik2 = NULL;
    FILE *plik3 = NULL;
    FILE *plik4 = NULL;
    FILE *plik5 = NULL;
    char nazwa[50];
    char nazwaPliku[50];
    char nazwa2[50];
    char nazwaPliku2[50];
    char nazwa3[50];
    char nazwaPliku3[50];
    char nazwa4[50];
    char nazwaPliku4[50];
    char nazwa5[50];
    char nazwaPliku5[50];
    int a,b,c,d;
    int n;

    printf("Podaj nazwe pliku 1: ");
    gets(nazwa);
    printf("Podaj nazwe pliku 2: ");
    gets(nazwa2);
    printf("Podaj nazwe pliku 3: ");
    gets(nazwa3);
    printf("Podaj nazwe pliku 4: ");
    gets(nazwa4);
    printf("Podaj nazwe pliku 5: ");
    gets(nazwa5);

    sprintf(nazwaPliku, "%s.txt", nazwa);
    plik = fopen(nazwaPliku,"w");

    sprintf(nazwaPliku2, "%s.txt", nazwa2);
    plik2 = fopen(nazwaPliku2,"w");

    sprintf(nazwaPliku3, "%s.txt", nazwa3);
    plik3 = fopen(nazwaPliku3,"w");

    sprintf(nazwaPliku4, "%s.txt", nazwa4);
    plik4 = fopen(nazwaPliku4,"w");

    sprintf(nazwaPliku5, "%s.txt", nazwa5);
    plik5 = fopen(nazwaPliku5,"w");



    printf("Podaj ile losowych liczb wpisac do pliku 1: ");
    scanf("%d", &a);
    int tab[a];
    printf("Podaj ile losowych liczb wpisac do pliku 2: ");
    scanf("%d", &b);
    int tab2[b];
    printf("Podaj ile losowych liczb wpisac do pliku 3: ");
    scanf("%d", &c);
    int tab3[c];
    printf("Podaj ile losowych liczb wpisac do pliku 4: ");
    scanf("%d", &d);
    int tab4[d];
    n = a+b+c+d;
    int tab5[n];

    wpiszDoPlik1(plik, a, tab);
    wpiszDoPlik2(plik2, b, tab2);
    wpiszDoPlik3(plik3, c, tab3);
    wpiszDoPlik4(plik4, d, tab4);

    wpiszDoPlik5(plik5, a, b, c, d, tab, tab2, tab3, tab4);
    plik5 = fopen(nazwaPliku5,"r");
    zapisz(plik5, n, tab5);
    plik5 = fopen(nazwaPliku5,"w");
    wpiszDoPlik52(plik5, n, tab5);
    return 0;
}
