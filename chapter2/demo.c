#include <stdio.h>

enum {
    JAN=1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

void test_enum()
{
    int i;
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    printf("this month is %d\n", i=JAN);
    printf("this month is %d\n", FEB);
    printf("this month is %s\n", months[NOV]);
}

unsigned long int next = 1;

/*rand: return pseudo-random integer on 0...32767*/
int randz(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536)%32768;
}

/* set seed for randz() */
void srandz(unsigned int seed)
{
    next = seed;
}

int isleap(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}
/* return the length of a string without '\0'*/
int strlenown(const char s[])
{
    int i;
    
    i = 0;

    while (s[i] != '\0')
        ++i;

    return i;
}

/* aoti_own: convert s to integer */
int atoi_own(const char s[])
{
    int i, n;
    
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}
/* convert a lower letter to upper case */
int lower_own(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int upper_own(int c)
{
    if (c >= 'a' && c <= 'z')
        return c - ('a' - 'A');
    else
        return c;
}

/* zsqueeze: delete all c from s */
void zsqueeze(char s[], int c)
{
    int i, j;
    
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
            s[j] = s[i];
    }
    s[j] = '\0';
}

/* deletes each characters in s1 that matches any character in string s2 */
void zsqueezes(char s1[], const char s2[])
{
    int i, j, k;
    
    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++)
        {
            if (s1[i] != s2[k])
                s1[i] = s1[j];
        }
        s1[j] = '\0';
    }
}

/* returns the first location in the string s1 where any characters from */
/* string s2 occurs, or -1 if s1 contains no characters from s2 */
int any(const char s1[], const char s2[])
{
    int i, j;

    for (i = 0; s2[i] != '\0'; i++) {
        for (j = 0; s1[j] != '\0'; j++)
        {
            if (s1[j] == s2[i])
                return j;
        }
    }

    return -1;
}

/* concatenate t to end of s; assume s is big enough */
void zstrcat(char s[], const char t[])
{
    int i, j;

    i = j = 0;
    while(s[i] != '\0') /*find end of s*/
        i++;
    while((s[i++] = t[j++]) != '\0') /*copy t*/
        ;
}

int main(int argc, char *argv[])
{
    int i;

    printf("the length of %s is %d\n", "hello,world", strlenown("hello,world"));
    printf("the value of %s is %d\n", "123", atoi_own("123"));
    printf("the value of %s is %d\n", "123289", atoi_own("123289"));
    printf("%c %c %c %c\n", 'Z', lower_own('Z'), 'a', upper_own('a'));

    for (i = 0; i < 10; i++)
    {
        printf("%d\t", randz());
    }
    printf("\n");


    test_enum();

    return 0;
}
