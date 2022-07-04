#include<stdio.h>
double dwumian_iteracja(int n, int k)
{

    // zalozenia
    double wynik = 1;
      if (k > n)
        wynik= 0;
    int zakres = n;
    if (k > n - k)
    {
        zakres -= k;
    }    else
        {
            zakres -= n - k;
        }
    for (int i = 1; i <= zakres; i++)
    {
        wynik *= (n - i + 1);
        wynik /= i;
    }
    return wynik;
}
    double dawumian_rekurencja(int n, int k)
{
    // zalozenia
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;

    // rekurencja
    return dawumian_rekurencja(n - 1, k - 1)
           + dawumian_rekurencja(n - 1, k);
}
double prawdopodobienstwo(double p, int n, int k)
{
    return dwumian_iteracja(n, k) * exp(k * log(p)) * exp((n - k) * log(1 - p));
}

    int main(){

    int n;
    int k;
    double p = 0.2;
    printf("wpisz n  ");
    scanf("%d", &n);
    printf("wpisz k  ");
    scanf("%d",&k);
    //wypisanie wartosci
    printf("dwumian iteracyjnie %g\n",dwumian_iteracja(n,k));
    printf("dwumian rekurencyjnie %g\n",dawumian_rekurencja(n,k));
    printf("prawdopodobienstwo  %g", prawdopodobienstwo(p,n,k));


    return 0;
}
