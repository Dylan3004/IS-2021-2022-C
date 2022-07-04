#include <stdio.h>
#include<ctype.h>


int main(){
    char liczba[10];
    printf("Wprowadz liczbe arabska lub rzymska(duze litery)  ");
    scanf("%s",&liczba);
    if(isdigit(liczba[0]))
    {

    int a = atoi(liczba);

//   w przypdaku wartosci poza ustalonym zakresem
    while(a>3999)
{
    printf("Wartosc niepoprawna , podaj wartosc ponownie  ");
    scanf("%d", &a);

}
// w przypadku wpisania 0 ktore nie ma rzymskiego odpowiednika
 while(a==0)
{
    printf("Wartosc niepoprawna , podaj wartosc ponownie  ");
    scanf("%d", &a);

}
    printf("liczba rzymska to  ");
// algorytm odpowiadajacy kolejnemu odejmowaniu liczb i wypisywaniu liter odpowiadajacych danje liczbie
    while(a >0)
    {


    if(a >= 1000)
    {
     printf("M");
     a-=1000;

    }

    else if(a >= 900)
    {
    printf("CM");
    a-=900;
    }

    else if(a >= 500)
    {
        printf("D");
         a-=500;
    }

    else if(a >= 400)
    {
        printf("CD");
         a=a-400;
    }

    else if(a >= 100)
    {
        printf("C");
         a=a-100;
    }

    else if(a >= 90)
    {
        printf("XC");
         a=a-90;
    }

    else if(a >= 50)
        {
        printf("L");
         a=a-50;
    }

    else if(a >= 40)
    {
        printf("XL");
         a=a-40;
    }
    else if(a>=10)
    {
        printf("X");
         a=a-10;
    }
    else if(a>=9)
    {
        printf("IX");
         a=a-9;
    }
    else if(a>=5)
    {
        printf("V");
         a=a-5;
    }
    else if(a>=4)
    {
        printf("IV");
         a=a-4;
    }
    else if(a>=1)
    {
        printf("I");
         a=a-1;
    }

    }
    }
    else
    {
    // algorytm korzystajacy z 2 oddzielnych tablic z wartosciami arabskimi i rzymskimi

    int wynik=0;
    int poprzednia=0;
    printf("Wartosc jako liczba arabska to  ");

    int arab[]={1,5,10,50,100,500,1000};
    char rzym[]={'I','V','X','L','C','D','M'};
    for(int i=0;i<10;i++)
        {

            for(int j=0;j<7;j++)
            {
                if(liczba[i]==rzym[j])
                {
                wynik+=arab[j];
    //algorytm dopisuje dane wartosci jesli napotka dany znak
                if(poprzednia<arab[j])
                {
                wynik-=poprzednia*2;
                }
                poprzednia=arab[j];
                }
     //algorytm jesli napotka ze poprzednik liczby obecnej jest mniejszy od danej liczby to odejmuje 2 krotnosc liczby wczesniejszej
            }

        }
       printf("%d",wynik);
    }





  return 0;
}






