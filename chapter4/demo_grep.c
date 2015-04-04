#include <stdio.h>
#include <string.h>

#define MAXLINE 1000 /* maximum input line length */

int zgetline(char line[], int max);
int strindex(const char source[], char searchfor[]);
int strindex_test(char *pattern);
int strindex_rightmost(const char s[], char t[]);
void strindex_rightmost_test(char *pattern);

char pattern_default[] = "ou"; /*pattern to search for*/

/* find all lines matching pattern */
int main(int argc, char *argv[])
{
    char *pattern = NULL;

    if (argc <=1)
        pattern = pattern_default;
    else
        pattern = argv[1];
    
    //return strindex_test(pattern);

    strindex_rightmost_test(pattern);
    return 0;
}

/*get line into s, return length*/
int zgetline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while (--lim>0 && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    if (c=='\n')
        s[i++]=c;
    s[i] = '\0';
    
    return i;
}

/* return index of t in s, -1 if none */
int strindex(const char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}

int strindex_test(char *pattern)
{
    char line[MAXLINE];
    int found = 0;

    printf("the pattern is %s\n", pattern);

    while (zgetline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;    
}

/* exer4.1:write the function strrindex(s, t), which returns the position of the */
/*     rightmost occurence of t in s, or -1 if there is none */
int strindex_rightmost(const char s[], char t[])
{
    int i, j, k;
    int len_s, len_t;
    len_s = len_t = 0;
    
    while (s[len_s] != '\0') len_s++;
    while (t[len_t] != '\0') len_t++;

    if (len_s < len_t)
        return -1;

    for (i = len_s-1; i >= 0; i--) {
        for (j = i, k = len_t-1; k >= 0 && s[j] == t[k]; j--,k--)
            ;
        if (k == -1)
            return i-len_t+1;
    }

    return -1;
}

void strindex_rightmost_test(char *pattern)
{
    char source[] = "could you shout!";
    int index = 0;

    index = strindex_rightmost(source, pattern);

    printf("the rightmost occurance of %s is %d\n", pattern, index);
}
