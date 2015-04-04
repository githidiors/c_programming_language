#include <stdio.h>
#include <string.h>

#define Arraycount(a) (sizeof((a)) / sizeof((a)[0]))

/* verify if the array is in ascending order */
int VeriOrder(int a[], int n)
{
    int i;
    
    for (i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            return 0;
        }
    }
    
    return 1;
}

void swap(int *pa, int *pb)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap_c(char *pa, char *pb)
{
    char temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

/* printd: print n in decimal */

void printd(int n)
{
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n/10)
        printd(n/10);
    putchar(n%10+'0');
}

void test_printd()
{
    int a[] = {409, 968, 224, 118, 168, 403, 383, 648, 135, 905};
    int i;
    
    for (i = 0; i < Arraycount(a); i++) {
        printd(a[i]);
        printf("\n");
    }
}

/* exercise 4-13 */
void reverse_recur(char s[], int len)
{
    if (len == 1)
        return;
    else if (len == 2)
    {
        swap_c(&s[0], &s[1]);
        return;
    }
    else 
    {
        swap_c(&s[0], &s[len-1]);
        reverse_recur(++s, len-2);
    }
}

void test_reverse_recur()
{
    char s[] = "hello world";
    printf("%s\n", s);
    reverse_recur(s, strlen(s));
    printf("%s\n", s);

    char s1[] = "1";
    printf("%s\n", s1);
    reverse_recur(s1, strlen(s1));
    printf("%s\n", s1); 

    char s2[] = "hello world kdfdk kdfj dk";
    printf("%s\n", s2);
    reverse_recur(s2, strlen(s2));
    printf("%s\n", s2); 
}

/* exercise 4-12: */
/* Adapt the ideas of printd to write a recursive version of itoa */
/* that is,convert an integer into a string by calling a recursive */
/* routine */
void itoa_rev(int i, char s[])
{
    if (i <= 9) {
        s[0] = i+'0';
        s[1] = '\0';
        return;
    }
    else {
        s[0] = i%10+'0';
        itoa_rev(i/10, ++s);
    }
}

void itoa_recursive(int i, char s[])
{
    if (i < 0) {
        i = -i;
        s[0] = '-';
        itoa_rev(i, ++s);
    }
    else
        itoa_rev(i, s);
    
    reverse_recur(s, strlen(s));
}

void test_itoa_recursive()
{
    char temp[100];
    itoa_recursive(1234, temp);
    printf("%s\n", temp);

    itoa_recursive(-134, temp);
    printf("%s\n", temp);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;

    if (left >= right) //do nothing if array contains fewer than two elements
        return;
    swap(&v[left], &v[(left+right)/2]); //move partition elem to v[0]
    last = left;
    for (i = left+1; i <= right; i++) //partition
        if (v[i] < v[left])
            swap(&v[++last], &v[i]);
    swap(&v[left], &v[last]); //restore partition elem

    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

void test_qsort()
{
    int a[] = {409, 968, 224, 118, 168, 403, 383, 648, 135, 905};
    int i;

    for (i = 0; i < Arraycount(a); i++)
        printf("%d\t", a[i]);
    printf("\n");


    qsort(a, 0, Arraycount(a)-1);

    for (i = 0; i < Arraycount(a); i++)
        printf("%d\t", a[i]);
    printf("\n");

    printf("Verification value:%d\n", VeriOrder(a, Arraycount(a)));
}

int main()
{
    test_printd();
    test_qsort();

    test_reverse_recur();

    test_itoa_recursive();

    return 0;
}
