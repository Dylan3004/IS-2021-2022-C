
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


 double silnia_iteracyjnie(int liczba){

    int silnia = 1;
    for(int i=2;i<=liczba;i++)
    {
       silnia=silnia*i;
    }
    return silnia;
}

 double silnia_rekurencyjnie(int silnia,int liczba){



    if (silnia<liczba){
     return silnia * silnia_rekurencyjnie(silnia+1,liczba);
 }
 else
    return silnia;

 }



int main()

{
    int liczba;
    int i;
    int wynik;
    int powiekszenie;
    int silnia=1;

    printf("wpisz liczbe  ");
    scanf("%d", &liczba);
    //czas start
    clock_t begin1 = clock();
    //petla dla zwiekszenia liczby operacji
    for(i=0;i<100000000;i++)
    {
        powiekszenie=silnia_iteracyjnie(liczba);
    }
    printf(" silnia iteracyjnie = %lf\n",silnia_iteracyjnie(liczba));
    //sprawdz czas
    clock_t end1 = clock();
    //porownanie przed i po
    double time_spent1 = (double)((end1 - begin1)) / CLOCKS_PER_SEC;
    //wypisanie wartosci i czasu
    printf("czas operacji silni iteracyjnej = %1.2lf sekundy\n",time_spent1);
    clock_t begin2 = clock();
    //czas start,pêtla dla zwiekszenia liczby operacji
     for(i=0;i<100000000;i++)
    {
        powiekszenie=silnia_rekurencyjnie(silnia,liczba);
    }
     printf(" silnia rekurencyjnie %lf\n",silnia_rekurencyjnie(silnia,liczba));
    clock_t end2 = clock();
    //czas stop
    //wypisanie wartosci i czasu
    double time_spent2 = (double)((end2 - begin2)) / CLOCKS_PER_SEC;
    printf("czas operacji silni rekurencyjnej %1.2lf sekund\n",time_spent2);

    return 0;
}
