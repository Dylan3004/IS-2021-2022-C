#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int main(){

    int i,j,zakres;
    bool tablica[10000];
    printf("Podaj gorny zakres, do ktorego chcesz odnalezc liczby pierwsze\n");
    scanf("%d",&zakres);
    for (i=2; i<=zakres; i++) tablica[i]=true;
    /* okreslam wartosci tablicy aby liczylo od 2*/
    for (i=2; i<=zakres; i++)
    {
        if (tablica[i] == true)
        {j = i+i;
            while (j<=zakres)
            {   tablica[j] = false;
                j = j+i;
            }
        }
    }
    /*petle przypisuja danym wielokrotnosciom liczb 2(4,6,8...),3(6,9,12),4(8,12,16)... wartosc false przez co nie wchodza do cyklu ,wiec koncowo
    uzyskujemy same liczby niepodzelne przez zadna wczesniejsa czyli liczby pierwsze*/
    printf("Liczby pierwsze dla zakresu od 1 do %d to\n",zakres);
    for (i=2; i<=zakres; i++) if (tablica[i]==true) printf("%d, ",i);
    /*program wypisuje dane wartosci true czyli liczby pierwsze*/

    return 0;

}
