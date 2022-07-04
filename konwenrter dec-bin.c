#include<stdio.h>
#include<stdlib.h>


int Konwersja_Dec_Bin1(unsigned a, char *bin)
{
    int i=0;
    int j=0;
    int wynik [20];
    for(j=0;a>j;i++)
    {
    bin[i]=a%2;
    a=a/2;
    }
    i-=1;
    //odwrocenie tablicy
    for(j=0;i>=0;i--)
    {
        wynik[j]=bin[i];
        printf("%d",wynik[j]);
        j++;
    }
    printf("\n");
    return j;
}
int Konwersja_Dec_Bin2(unsigned a, char *bin)
{
    int wynik[20];
    int i=0;
    int c=0;
    for(;i<16;i++)
    {
        wynik[i]=a&1;
        a=a>>1;
        if(wynik[i]==1)
        c=i;
    }
    i=c;
    int j;
    //odwrocenie tablicy
    for(j=0;i>=0;i--)
    {
        wynik[j]=bin[i];
        printf("%d",wynik[j]);
        j++;

    }
    printf("\n");
    return c+1;
}






int main(void)
{
    int a;
    int bin [20];
    printf("wpisz liczbe :  ");
    scanf("%d",&a);
    Konwersja_Dec_Bin1(a,bin);
    printf("\n");
    Konwersja_Dec_Bin2(a,bin);
    printf("\n");
    printf("wartosc z 1 funkcji %d wartosc z 2 funkcji  %d",Konwersja_Dec_Bin1(a,bin),Konwersja_Dec_Bin2(a,bin));
    //obie funkcje wypisuja podana liczbe za pomoca systemu binarnego pierwsza za pomoca dzielenia modulo 2 a druga za pomoca przesuniecia bitowego
    //oraz zwracaja liczbe znakow danej liczby w systemie binarnym
}
