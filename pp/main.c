#include <stdio.h>
#include "lr.h"
int main()
{
    int choise;
    scanf("%d", &choise);
    switch(choise){
    case(1): return lab1();
    case(2): return lab2();
    case(3): return lab3();
    case(4): return lab4();
        }
return 0;
}
