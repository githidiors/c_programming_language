#include<stdio.h>

#define MAXLINE 1000 /* maximum input line size */
int zgetline(char line[], int maxline, FILE *fp);
void copy(char to[], const char from[]);

/*
exercise 1-19:
Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverse its input a line at a time.
*/

void reverse(char s[])
{
	int i = 0;
	int j;
	char temp;

	while (s[i] != '\0')
		i++;

	if (i != 0) /*there is a line*/
	{
		for (j = 0; j < i / 2; j++) { 
			temp = s[j];
			s[j] = s[i -j -1];
			s[i-j -1] = temp;
		}
	}
}

void reverse_line()
{
	char line[MAXLINE]; /*current input line*/
	FILE *fp;
	int len = 0;
	
	fp = fopen("test.txt", "r");
	if (NULL == fp)
	{
		printf("can't open the file, please check");
		return;
	}
	
	while ((len = zgetline(line, MAXLINE, fp)) > 0)
	{
		reverse(line);
		printf("%s", line);
	}
	
	fclose(fp);
}

/* power: raise base to n-th power: n>=0 */
int power(int base, int n)
{
	int i, p;

	p = 1;
	for (i = 1; i <= n; i++)
	{
		p = p * base;
	}
	return p;
}

void demo_power()
{
	int i;
	
	for (i = 0; i < 10; i++) {
		printf("%d %7d %7d\n", i, power(2, i), power(-3, i));
	}
}
/*count digits, white spaces, others*/
void demo_16()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
	{
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;
	}

	printf("digits =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}

/*
print longest lines
*/
void get_maxline()
{
	int len; /*current line length*/
	int max; /*maximum length seen so far*/
	int linenum; /*current line number*/
	int max_linenum; /*maximum length line's line-number*/
	char line[MAXLINE]; /*current input line*/
	char longest[MAXLINE]; /*longest line saved here*/
	FILE *fp;
	
	fp = fopen("test.txt", "r");
	if (NULL == fp)
	{
		printf("can't open the file, please check");
		return;
	}

	max = 0;
	linenum = 0;
	max_linenum = 0;
	while ((len = zgetline(line, MAXLINE, fp)) > 0)
	{
		linenum++;
		if (len > max)
		{
			max = len;
			max_linenum = linenum;
			copy(longest, line);
		}
	}

	fclose(fp);

	if (max > 0)  /*there is a line*/
		printf("%dth line, %d chars\n%s", max_linenum, max, longest);
}

/* read a line into line, return length*/
int zgetline(char line[], int lim, FILE *fp)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getc(fp)) != EOF && c != '\n'; ++i)
		line[i] = c;
	if ('\n' == c) {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*copy 'from' to 'to', assume to is big enough*/
void copy(char to[], const char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0')
		++i;
}

int main(int argc, char *argv[])
{
	reverse_line();
	return 0;
}
