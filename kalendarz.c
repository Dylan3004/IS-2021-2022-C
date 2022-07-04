#include<stdio.h>
#include<stdlib.h>

int dzien_roku(int rok){
    int pierwszy;
    // funkcja liczaca pierwszy dzien w roku
    pierwszy = (((rok-1)*365) + ((rok-1)/4) - ((rok - 1) /100) + ((rok) / 400)+1) % 7;
    return pierwszy;
}

int main(){

    int rok,miesiac,dzien,dni,dnimiesiaca,dnitygodnia=0,funkcja;
    int liczbadni[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((rok%4==0&&rok%100!=0)||rok%400==0)
    {
       liczbadni[1]=29;
    }


    printf("Wpisz rok ");
    scanf("%d", &rok);
    printf("wpisz miesiac ");
    scanf("%d", &miesiac);
    printf("wpisz dzien ");
    scanf ("%d",&dzien);
    char *miesiace[]={"Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien"};


    if ( miesiac==1 )
    {
        dni=liczbadni[miesiac-1];
        printf("\n\n\n _________%s___________",miesiace[miesiac-1]);

    }
    else if( miesiac==2 )
    {
        dni=liczbadni[miesiac-1];
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==3 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==4 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if ( miesiac==5 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if ( miesiac==6 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if ( miesiac==7 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==8 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==9 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==10 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==11 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    else if( miesiac==12 )
    {
         printf("\n\n\n _________%s___________",miesiace[miesiac-1]);
    }
    printf("\n Nd Pon  Wt  Sr  Czw Pt  Sb \n");
     dnimiesiaca=liczbadni[miesiac-1];
     funkcja=dzien_roku(rok);

     for(dnitygodnia=0;dnitygodnia<funkcja;dnitygodnia++)
     {
         printf("    ");
         // pozostawienie pustego miejsca

    for(dni=1;dni<=dnimiesiaca;dni++){
        printf("%4d",dni);
        if(++dnitygodnia>6)
        {
            printf("\n");
            dnitygodnia=0;
            //ustalanie nowej lini dla nast tygodnia,nie wiedzia³em jak rozwiazac problem z pierwszym tygodniem
            }
            if(dzien==dni)
            {
                printf("*");
            //wskazanie danego dnia
            }
            funkcja=dnitygodnia;
    }
    }
    printf("\nPodany dzien jest zaznaczony *");
    }


