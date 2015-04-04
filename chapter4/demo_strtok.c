#include <string.h>
#include <stdio.h>

int main()
{
    char test[] = "1 2 - 4 5 -2 -90 +";
    char test1[] = "1 2 3 5 89.3 34.5";
    int i = 0;
    int j;
    char *tokens[100];

    tokens[i++] = strtok(test, " \t");
    while ((tokens[i]=strtok(NULL, " \t")) != NULL)
        i++;
    for (j = 0; j < i; j++)
    {
        printf("%s\n", tokens[j]);
    }

    i = 0;
    tokens[i++] = strtok(test1, " \t");
    while ((tokens[i]=strtok(NULL, " \t")) != NULL)
        i++;
    for (j = 0; j < i; j++)
    {
        printf("%s\n", tokens[j]);
    }    

    return 0;
}
