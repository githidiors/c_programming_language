#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int binsearch(int x, int v[], int n);     /*  Original K&R function  */
int binsearch2(int x, int v[], int n);    /*  Our new function       */

#define MAX_ELEMENT 20000

/* 
   binsearch: find x in v[0]<v[1]<...<v[n-1] 
   return the index of the founded on in the array or -1 if not found
*/
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;

    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid-1;
        else if (x > v[mid])
            low = mid+1;
        else /*found match*/
            return mid;
    }

    return -1;
}

/*  Implementation of binsearch() using
    only one test inside the loop        */
int binsearch2(int x, int v[], int n) 
{
    int low, high, mid;
    
    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while ( low <= high && x != v[mid] ) {
        if ( x < v[mid] )
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if ( x == v[mid] )
        return mid;
    else
        return -1;
}

/*  Outputs approximation of processor time required
    for our two binary search functions. We search for
    the element -1, to time the functions' worst case
    performance (i.e. element not found in test data)   */
void test_binsearchs(void) 
{
    int testdata[MAX_ELEMENT];
    int index;                  /*  Index of found element in test data  */
    int n = -1;                 /*  Element to search for  */
    int i, j;
    clock_t time_taken;

    /*  Initialize test data  */
    
    for ( i = 0; i < MAX_ELEMENT; ++i )
        testdata[i] = i;
    
    /*  Output approximation of time taken for
        100,000 iterations of binsearch()       */
    
    for (i = 0, time_taken = clock(); i < 1000000; ++i) {
        for (j = 0; j < 100; j++)
        index = binsearch(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    
    if ( index < 0 )
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    
    printf("binsearch() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    
    
    /*  Output approximation of time taken for
        100,000 iterations of binsearch2()        */
    
    for (i = 0, time_taken = clock(); i < 1000000; ++i) {
        for (j = 0; j < 100; j++)
            index = binsearch2(n, testdata, MAX_ELEMENT);
    }
    time_taken = clock() - time_taken;
    
    if ( index < 0 )
        printf("Element %d not found.\n", n);
    else
        printf("Element %d found at index %d.\n", n, index);
    
    printf("binsearch2() took %lu clocks (%lu seconds)\n",
           (unsigned long) time_taken,
           (unsigned long) time_taken / CLOCKS_PER_SEC);
    
}

/* count digits, white space, others */
void chars_count()
{
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;
    while ((c=getchar()) != EOF) {
        switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            ndigit[c-'0']++;
            break;
        case ' ':
        case '\n':
        case '\t':
            nwhite++;
            break;
        default:
            nother++;
            break;
        }
    }
    printf("digits =");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}

/******************************/
/*
  convert s to integer, version 2
  the system provides a more elaborate function 'strtol'
*/
int atoi_ch3(const char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

void test_atoi()
{
    char *s = "   -12789ab1";
    char *endp = NULL;
    printf("%s is %d\n", s, atoi_ch3(s));
    printf("%s is %ld\n", s, strtol(s, &endp, 10));
    printf("first left char is %c\n", *endp);
}
/******************************/

/* reverse string s in place */
void reverse_ch3(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


/*itoa: convert n to characters in s*/
void itoa_ch3(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) //record sign
        n = -n; //make positive

    i = 0;
    
    do { //generate digits in reverse order
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse_ch3(s);
}

/* trim: remove trailing blanks,tabs,newlines */
int trim(char s[])
{
    int n;
    
    for (n=strlen(s)-1; n >= 0; n--) {
        if (s[n]!=' ' && s[n]!='\t' && s[n]!='\n')
            break;
    }
    s[n+1]='\0';
    return n;
}

/******************************/


int main(int argc, char *argv[])
{
    test_binsearchs();
    
    test_atoi();

    return 0;
}
