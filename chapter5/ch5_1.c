#include <stdio.h>

void ch5_1()
{
    int x = 1, y = 2, z[10];
    int *ip; //ip is the pointer to int
    
    ip = &x; //ip now points to x
    y = *ip; //y is now 1
    *ip = 0; //x is now 0
    ip = &z[0]; //ip now points to z[0]

    for (x = 0; x < 10; x++)
        z[x] = x*2;
    ip = z; //ip points to z[0]
    printf("++*ip is %d\n", ++*ip);

    ip = z; //ip points to z[0]
    printf("*ip++ is %d\n", *ip++); //unary operators *,++ associate right to left
    printf("*ip is %d\n", *ip);

    ip = z; //ip points to z[0]
    printf("*++ip is %d\n", *++ip); //unary operators *,++ associate right to left 
}

int main()
{
    ch5_1();

    return 0;
}
