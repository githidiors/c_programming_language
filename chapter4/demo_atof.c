#include <stdio.h>
#include <ctype.h>
#include <math.h>

/* convert string s to double*/
double zatof(char s[])
{
    double val, power;
    int i, sign;

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

    return sign*val/power;
}

void zatof_test()
{
    char *s1[] = {"12.", "-.23", "-23.45", "123242"};
    int i;
    
    for (i = 0; i < sizeof(s1)/sizeof(s1[0]); i++) {
        printf("%s is %lf\n", s1[i], zatof(s1[i]));
    }
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

void zatof_test_v2()
{
    char *s1[] = {"-23.45e-1", "123242e2", "123.45e-2", "123.45e-6"};
    int i;
    
    for (i = 0; i < sizeof(s1)/sizeof(s1[0]); i++) {
        printf("%s is %lf\n", s1[i], atof_v2(s1[i]));
    }

}

int main()
{
    //zatof_test();
    zatof_test_v2();

    return 0;
}
