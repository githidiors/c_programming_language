#include <stdio.h>
#include <ctype.h>

#define countof(array) (sizeof(array) / sizeof((array)[0]))

/* write the function htoi(s), which converts a string of hexadecimal */
/* digits(including an optional 0x or 0X) into its equivalent integer */
/* value. The allowable digits are 0 through 9, a through f and A */
/* through F. */
/* assume string s'format is correct, with an optional 0x or 0X */
long htoiz(const char s[])
{
    int i, baseval;
    
    long n = 0;
    if ((s[0]=='0' && s[1]=='x') || (s[0]=='0' && s[1]=='X'))
        i = 2;
    else i = 0;
    for (; isxdigit(s[i]); ++i) {
        if (isdigit(s[i])) {
            baseval = s[i] - '0';
        }
        else if (s[i]>='a' && s[i]<='f') {
            baseval = s[i]-'a'+10;
        }
        else {
            baseval = s[i]-'A'+10;
        }
        n = 16 * n + baseval;
    }

    return n;
}

void test_htoiz()
{
    char *hex_str[] = {"0x7bfa", "0xc82", "0x1258e", "0x7636", "0xda05", "0x6cd2", "0xdca8", "0xc109", "0x5244", "0x4dbb"};
    long hex_val[] = {31738, 3202, 75150, 30262, 55813, 27858, 56488, 49417, 21060, 19899};
    int i;
    long temp;
    
    for (i = 0; i < countof(hex_str); i++) {
        temp = htoiz(hex_str[i]);
        if (temp != hex_val[i]) {
            printf("%s is %ld, not %ld\n", hex_str[i], hex_val[i], temp);
        }
    }
    
    printf("Verification Done!\n");    
}

/* 
   2015-04-02 
   convert an ASCII hex digit to the corresponding number between 0
   and 15. H should be a hexadecimal digit that satisfies isxdigit
   otherwise, the result is undefined
 */
#define XDIGIT_TO_NUM(h) ((h)<'A' ? (h)-'0' : toupper(h)-'A'+10)

long htoiz_v2(const char s[])
{
    int i, baseval;
    
    long n = 0;
    if ((s[0]=='0' && s[1]=='x') || (s[0]=='0' && s[1]=='X'))
        i = 2;
    else i = 0;
    for (; isxdigit(s[i]); ++i) {
        baseval = XDIGIT_TO_NUM(s[i]);
        n = 16 * n + baseval;
    }

    return n;
}

/*
[(31738, "0x7bfa"),
 (3202,  "0xc82"),
 (75150, "0x1258e"),
 (30262, "0x7636"),
 (55813, "0xda05"),
 (27858, "0x6cd2"),
 (56488, "0xdca8"),
 (49417, "0xc109"),
 (21060, "0x5244"),
 (19899, "0x4dbb")]
*/
void test_htoiz_v2()
{
    char *hex_str[] = {"0x7bfa", "0xc82", "0x1258e", "0x7636", "0xda05", "0x6cd2", "0xdca8", "0xc109", "0x5244", "0x4dbb"};
    long hex_val[] = {31738, 3202, 75150, 30262, 55813, 27858, 56488, 49417, 21060, 19899};
    int i;
    long temp;
    
    for (i = 0; i < countof(hex_str); i++) {
        temp = htoiz_v2(hex_str[i]);
        if (temp != hex_val[i]) {
            printf("%s is %ld, not %ld\n", hex_str[i], hex_val[i], temp);
        }
    }
    
    printf("Verification Done!\n");
}

int main(int argc, char *argv[])
{
    printf("%s is %ld\n", "0xfff", htoiz("0xfff"));
    printf("%s is %ld\n", "0x123", htoiz("0x123"));
    printf("%s is %ld\n", "0x456", htoiz("0x456"));
    printf("%s is %ld\n", "6", htoiz("6"));
    printf("%s is %ld\n", "0", htoiz("0"));
    printf("%s is %ld\n", "f", htoiz("f"));
    printf("%s is %ld\n", "1f", htoiz("1f"));
    printf("%s is %ld\n", "d1", htoiz("d1"));

    test_htoiz();
    test_htoiz_v2();
    return 0;
}
