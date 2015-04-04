/*
  Write a program to remove all comments from a C program.
  Don't forget to handle quoted string and character constants properly.
  C comments do not nest.
*/

#include <stdio.h>

void test_ungetc()
{
    int c;
    
    printf("demo ungetc, when read a, convert it into b and put it back\n");

    while ((c=getchar()) != EOF) {
        if (c == 'a') {
            printf("this is a, put it back\n");
            ungetc(c+1, stdin);
        }
        else {
            putchar(c);
        }
    }
}

int main()
{

    
    return 0;
}
