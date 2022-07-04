#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
    double a;
    double b;
    double c;
    double p;
    double q;
    double delta;
    double x1;
    double x2;
    printf("Wprowadz a od x kwadrat\n");
    scanf( "%lf" , &a );
    if(a==0){
        printf("a nie moze byc rowne 0 uruchom program ponownie\n");
        printf("Wprowadz a od x kwadrat\n");
    scanf( "%lf" , &a );
    }
        else{

        }


    printf("Wprowadz b od x\n");
    scanf("%lf" , &b);

    printf("Wprowadz c\n");
    scanf("%lf" , &c);
    /*program zczytuje podane wartosci i sprawdza czy a nie jest rowne 0*/

    delta = ((b*b)-(4*a*c));
    printf("delta wynosi %0.2lf\n" , delta);

    if(delta<0){
        printf(" brak pierwiastkow rownania");
    }

    if(delta==0){
        x1=-b+sqrt(delta)/2*a;
        printf("tylko jeden pierwiastek %lf, x1");

    }
    if(delta>0){
    x1=(-b+sqrt(delta))/(2*a);
    x2=(-b-sqrt(delta))/(2*a);
        printf("\n dwie odpowiedzi\n %lf i %lf \n", x1 , x2);

    }
    /*program liczy delte oraz podane pierwiastki funkcji dla podanych sytuacji */
    q=(-delta/(4*a));
        printf("\n q wynosi %lf \n", q);
    p=(-b/(2*a));
     printf("\n p wynosi %lf \n", p);
     /* p i q dodalem jako wspolrzendne wiezcholka funkcji*/

    return 0;



}
