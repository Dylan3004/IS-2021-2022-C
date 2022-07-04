#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i,ilosc;
    float liczba , suma , sa;
    printf("Ile liczb wprowadzisz?" );
    scanf("%d", &ilosc);
    /* program zczytuje ile liczb ma zostaæ wprowadzone*/
    suma=0;
    printf("Wprowadz %d Liczby ", ilosc);
    for(i=0; i<ilosc; i++)
    {
            scanf("%f", &liczba);
            suma= suma + liczba;
    }
    /* program za pomoca petli zczytuje kolejne liczby */
        sa = suma/ilosc;
        printf("\nSrednia arytmetyczna = %0.3f", sa);
        /* wypisanie liczb*/

        return 0;


}
