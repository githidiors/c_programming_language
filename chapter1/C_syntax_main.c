/*
  Write a program to check a C program for rudimentary syntax
  errors like unbalanced parentheses, brackets, and braces. Don't forget about
  quotes, both single and double, escape sequences, and comments.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "C_syntax_main.h"

int c_isletter(int c)
{
    if (isalpha(c) || c == '_')
        return 1;
    else
        return 0;
}

int is_keyword(char s[])
{
    int i;
    //printf("%d bytes, %d bytes", sizeof(KeywordTable), sizeof(KeywordTable[0]));
    for (i = 0; i < sizeof(KeywordTable)/sizeof(KeywordTable[0]); i++) {
        if (strcmp(s, KeywordTable[i]) == 0)
            return 1;
    }
    return 0;
}

void parseIdKeyword()
{
    int c;
    FILE *fp = NULL;
    int state = STATE_id_keyword_OUT;
    char temp[1000];
    int i = 0;

	fp = fopen("test.txt", "r");
	if (NULL == fp)
	{
		printf("can't open the file, please check");
		return;
	}

    while ((c=getc(fp)) != EOF) {
        if (state == STATE_id_keyword_OUT) {
            if (c_isletter(c)) {
                state = STATE_id_keyword_IN;
                temp[i++] = c;
            }
        }
        else if (state == STATE_id_keyword_IN) {
            if (c_isletter(c) || isdigit(c)) {
                state = STATE_id_keyword_IN;
                temp[i++] = c;
            }
            else {
                state = STATE_id_keyword_OUT;
                temp[i] = '\0';
                i = 0;

                if (is_keyword(temp)) {
                    printf("keyword: %s\n", temp);
                }
                else {
                    printf("identifier: %s\n", temp);
                }
            }
        }
    }

	fclose(fp);
}

int main()
{
    parseIdKeyword();
    return 0;
}
