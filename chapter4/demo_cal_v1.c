#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100

/* read a line into line, return length*/
int zgetline(char line[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if ('\n' == c) {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

double atof_v2(char s[])
{
    double val, power;
    int i, sign;
    double exp_power = 0;
    int sign_exp = 0;

    for (i = 0; isspace(s[i]); i++); //skip white space
    
    sign = (s[i]=='-')?-1:1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (val=0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i]-'0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i]-'0');
        power *= 10.0;
    }
    //handle the optional exponent part
    if (s[i] == 'e')
        i++;
    sign_exp = (s[i] == '-')?-1:1;
    if (s[i]=='+' || s[i]=='-')
        i++;
    for (exp_power = 0; isdigit(s[i]); i++) {
        exp_power = 10*exp_power + (s[i]-'0');
    }
    exp_power = pow(10, sign_exp*exp_power);
    return sign*val/power*exp_power;
}

/*rudimentary calculator*/
int main()
{
    double sum;
    char line[MAXLINE];
    
    sum = 0.0;
    while (zgetline(line, MAXLINE) > 0) {
        if (!strcmp(line, "quit\n")) //zgetline put the '\n' at the end of the string
            break;
        sum += atof_v2(line);
        printf("\t%g\n", sum);
    }

    printf("the result is %lf\n", sum);

    return 0;
}


