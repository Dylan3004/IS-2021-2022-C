#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include<time.h>
#define R_MAX 65536

    double funkcja_pi(int a , int b)
    {
       double p = (double)b/a;
       double sigma_k = sqrt(p*(1-p)*a);
       double sigma_pi = 4*sigma_k /a;
       return sigma_pi;

    }
    double pi_przyklad(int iteracje)
    {
    double a=0;
    double b=0;
    int i;
    double x;
    double y;
    double odleglosc;
    int licznik=0;
    double pi;

    for(i=0;i<iteracje;i++)
    {
       int c=a;
       int d=b;
       a=(((75*(c+1))%65537)-1);
       b=(((100*(d+1))%65537)-1);
        x = (double)a / (R_MAX + 1.0);
        y = (double)b / (R_MAX + 1.0);
        double odleglosc= x*x+y*y;
        if (odleglosc<=1)
        licznik+=1;
    //licznik jest suma trafien w kolo
      }

        pi=(double)licznik/iteracje*4;
        return pi;
    }
    double licznik_przyklad(int iteracje)
    {
    double a=0;
    double b=0;
    int i;
    double x;
    double y;
    double odleglosc;
    int licznik=0;
    double pi;

    for(i=0;i<iteracje;i++)
    {
       int c=a;
       int d=b;
       a=(((75*(c+1))%65537)-1);
       b=(((100*(d+1))%65537)-1);
        x = (double)a / (R_MAX + 1.0);
        y = (double)b / (R_MAX + 1.0);
        double odleglosc= x*x+y*y;
        if (odleglosc<=1)
        licznik+=1;
    //licznik jest suma trafien w kolo
      }
      return licznik;
    }
    double pi_srand(int iteracje)
    {
        double x,y;
        int i,licznik=0;
        double odleglosc;
        double pi;
        srand(time(NULL));
   // petla pozwala nam na generowanie losowycz liczb z zakresu od 0 do 1 przez dzielenie przez rand max
   for ( i=0; i<iteracje; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      // nie jest potrzebne pierwiastkowanie odloeglosci bo wynik pierwiastka z powyzej 1 zawsze bd powyzej jedynki a  ponizej 1 analogicznie rowniez ponizej
      odleglosc = x*x+y*y;
      if (odleglosc<=1) licznik++;
    //licznik jest suma trafien w kolo
      }
        pi=(double)licznik/iteracje*4;
        return pi;

    }
    double licznik_srand(int iteracje)
    {
        double x,y;
        int i,licznik=0;
        double odleglosc;
        double pi;
        srand(time(NULL));
   for ( i=0; i<iteracje; i++) {
      x = (double)rand()/RAND_MAX;
      y = (double)rand()/RAND_MAX;
      odleglosc = x*x+y*y;
      if (odleglosc<=1) licznik++;
      }
        return licznik;
    }

int main()
{
    int iteracje;
    printf("Wpisz liczbe iteracji: ");
    scanf("%d",&iteracje);
    printf("pi wedlog wzoru wynosi :%lf \n",pi_przyklad(iteracje));
    printf("sigma pi wedlog wzoru wynosi: %lf\n",funkcja_pi(iteracje,licznik_przyklad(iteracje)));
    printf("pi z srand em : %lf\n",pi_srand(iteracje));
    printf("sigma pi z srand em wynosi: %lf\n",funkcja_pi(iteracje,licznik_srand(iteracje)));
    //na poczatku byly to dwa oddzielne programy ale wolalem je scalic i dac mozliwosc porownania dokladnosci , chcialbym jeszcze zapytac czy jest mozliwosc jakiegos
    //prostrzego zaimplementowania wracania 2 wartosci przez funkcje zeby jej nie powtarzac(tak jak zrobilem )




    return 0;
}
