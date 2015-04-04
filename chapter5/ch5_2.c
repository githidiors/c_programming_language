#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE]; //buffer for zungetch
int bufp = 0; //next free position in buf

int zgetch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void zungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("zungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

//c passes arguments to functions by value, not reference
void swap_wrong(int x, int y) //wrong
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

/*
  pointer arguments enable a function to access and change objects in the
  function that called it
*/
void swap_int(int *px, int *py)
{
    int temp;
    
    temp = *px;
    *px = *py;
    *py = temp;
}

/* get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    
    while (isspace(c = zgetch())) //skip white space
        ;
    if (!isdigit(c) && c !=EOF && c != '+' && c != '-') {
        zungetch(c); //it is not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = zgetch();
    if (!isdigit(c))
        return 0;
    for (*pn = 0; isdigit(c); c = zgetch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        zungetch(c);
    return c;
}

void test_getint()
{
    int n;
    int rec;
    
    while (1) {
        rec = getint(&n);
        if (rec == EOF || rec == 0)
            break;
        printf("%d\n", n);
    };
}

int getfloat(double *pf)
{
    int c, sign;
    double power;
    
    while (isspace(c = zgetch())) //skip white space
        ;
    if (!isdigit(c) && c !=EOF && c != '+' && c != '-' && c != '.') {
        zungetch(c); //it is not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = zgetch();
    if (!isdigit(c) && c != '.')
        return 0;
    for (*pf = 0.0; isdigit(c); c = zgetch())
        *pf = 10.0 * *pf + (c-'0');
    if (c != '.') {
        *pf = sign**pf;
        zungetch(c);
        return 1;
    }
    c = zgetch();
    for (power = 1.0; isdigit(c); c = zgetch()) {
        *pf = 10.0 * *pf + (c-'0');
        power *= 10.0;
    }
    
    if (c != EOF)
        zungetch(c);
    *pf = sign * *pf /power;
    return c;
}

void test_getfloat()
{
    double f[3];
    int n;

    for (n = 0 ; n < 3 && getfloat(&f[n]) != EOF; n++);

    for (n = 0; n < 3; n++)
        printf("%lf\n", f[n]);
}

int main()
{
    /* test_getint(); */
    test_getfloat();
    return 0;
}
