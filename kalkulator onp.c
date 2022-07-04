
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

double stack[256];
int StackSize = 0;
// tablica komend
char commands[][5] =
{
    "add",
    "sub",
    "mul",
    "div",
    "pow",
    "neg",
    "sin",
    "cos",
    "log",

    "=",
    "pop",
    "clear",
    "quit",
};
//dodanie do stosu
void StackPush(double x) {
    if (StackSize >= 256)
    {
        printf("error: stack is full\n");
    }
    else
    {
        stack[StackSize] = x;
        StackSize++;
    }
}
//zdjecie ze stosu
double StackPop() {
    if (StackSize <= 0)
    {
        printf("error, stack empty\n");
        return 0;
    }
    double res = stack[StackSize - 1];
    StackSize--;
    return res;
}

double StackPeek()
{
    if (StackSize <= 0)
    {
        printf("error: stack empty\n");
        return 0;
    }
    return stack[StackSize - 1];
}
// odpowiedznic funkcji podanej w tresci do zadania
bool CompareStrings(char* data, int dataLen, char* dest, int destLen)
{
    if (dataLen != destLen)
    {
        return false;
    }

    for (int i = 0; i < destLen; i++)
    {
        if (data[i] != dest[i])
        {
            return false;
        }
    }

    return true;
}
//lista komend
bool CheckCommands (char* word, int wordLen)
{   //dodawanie
    if (CompareStrings(word, wordLen, "add", 3))
    {
        StackPush(StackPop() + StackPop());
        return true;
    }
    //odejmowanie
    else if (CompareStrings(word, wordLen, "sub", 3))
    {
        double temp = StackPop();
        StackPush(StackPop() - temp);
        return true;
    }
    //mnozenie
    else if (CompareStrings(word, wordLen, "mul", 3))
    {
        StackPush(StackPop() * StackPop());
        return true;
    }
    //dzielenie
    else if (CompareStrings(word, wordLen, "div", 3))
    {
        double temp = StackPop();
        StackPush(StackPop() / temp);
        return true;
    }
    //potegowanie
    else if (CompareStrings(word, wordLen, "pow", 3))
    {
        double temp = StackPop();
        StackPush(pow(StackPop(), temp));
        return true;
    }
    //negacja
    else if (CompareStrings(word, wordLen, "neg", 3))
    {
        StackPush(-StackPop());
        return true;
    }
    //sinus
    else if (CompareStrings(word, wordLen, "sin", 3))
    {
        StackPush(sin(StackPop()));
        return true;
    }
    //cosinus
    else if (CompareStrings(word, wordLen, "cos", 3))
    {
        StackPush(cos(StackPop()));
        return true;
    }
    //logarytm
    else if (CompareStrings(word, wordLen, "log", 3))
    {
        StackPush(log(StackPop()));
        return true;
    }
    //wypisanie wartosci
    else if (CompareStrings(word, wordLen, "=", 1))
    {
        printf("%lf\n", StackPeek());
        return true;
    }
    //zdjecie ze stosu
    else if (CompareStrings(word, wordLen, "pop", 3))
    {
        StackPop();
        return true;
    }
    //czyszczenie stosu
    else if (CompareStrings(word, wordLen, "clear", 5))
    {
        while(StackSize > 0)
        {
            StackPop();
        }
        return true;
    }
    //wyjscie z programu
    else if (CompareStrings(word, wordLen, "quit", 4))
    {
        exit(1);
        return true;
    }

    return false;
}


int main ()
{
    char command[6];
    bool endOfLine = false;
    bool error = false;
    double val;
    printf("commands:   add,sub,mul,div,pow,neg,sin,cos,log,=,pop,clear(clears stack),quit\n" );
    //warunek zawsze prawdziwy
    while (1)
    {

        if (endOfLine == true)
        {
            endOfLine = false;
            if (StackSize > 0)
            {
                printf("%g",  StackPeek());
            }
        }

        int j = 0;

        if (scanf("%lf", &val) == 1)
        {
            //sprawdzanie spacji i znaku nowej linii
            if (scanf("%c", &command[j]) == 1 && command[j] != 32 && command[j] != 10)
            {
                //znalezienie bledu
                error = true;
                j++;
            }
            else
            {
                StackPush(val);
            }
            if (command[j] == 10)
            {
                endOfLine = true;
            }
        }
        else
        {
            while (scanf("%c", &command[j]) == 1 && command[j] != 32 && command[j] != 10)
            {
                j++;
            }
            if (command[j] == 10)
            {
                endOfLine = true;
            }

            //sprawdzanie listy komend
            if (j > 5)
            {
                //bald przy za dlugiej komedzie
                error = true;
            }
            else if (j != 0 && error != true)
            {
                if (CheckCommands(command, j) == false)
                {
                    //zla komenda
                    error = true;
                }
            }

            //wydzucaanie bledu
            if (error == true)
            {
                error = false;
                for (int i = 0; i < StackSize; i++)
                {
                    printf("%lf ", stack[i]);
                }
                printf("\n");
                printf("error: unrecognized command\n");
            }

        }
    }
    return 1;
}
