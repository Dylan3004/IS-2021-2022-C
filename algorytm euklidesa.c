#include<math.h>
#include<stdlib.h>
#include<stdio.h>

    int main()
{
    int a;
    int b;
    int wynik;

    printf("podaj liczbe a  ");
    scanf("%d", &a);



    printf("podaj liczbe b  ");
    scanf("%d", &b);
    /*program sczytuje liczby*/


    printf("Dla %d oraz %d ", a ,b);

    if (b > a)
    {
        int temp = b;
        b = a;
        a = temp;
    }

        do{
            wynik=a%b;
            a=b;
            b=wynik;
        }
        /* program wykonuje algorytm euklidesa*/
        while(b != 0);
        printf("najwiekszy wspolny dzielnik %d ", a);
    /*program wypisuje liczby*/

        return 0;







}
