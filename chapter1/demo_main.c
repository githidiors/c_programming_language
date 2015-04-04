/*
  the example programs of the chapter 1
*/
#include <stdio.h>

//magic number
#define LOWER	0		/*lower limit of table*/
#define UPPER	300		/*upper limit*/
#define STEP	20		/*step size*/

/*
  print Fahrenheit-Celsius table in int-format
*/
void fahr2cel()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0; /* lower of temperature table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/*
  print Fahrenheit-Celsius table in float-format
*/
void fahr2cel_1()
{
    double fahr, celsius;
    int lower, upper, step;
	
    lower = 0; /* lower of temperature table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */
	
    fahr = (double)lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

/*
  use for statement
*/
void fahr2cel_2()
{
    int fahr;

    for (fahr = 0; fahr <= 300; fahr += 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}
/*
  print Celsius-Fahrenheit table in float-format
*/
void cel2fahr()
{
    double fahr, celsius;
    int lower, upper, step;
	
    lower = 0; /* lower of temperature table */
    upper = 100; /* upper limit */
    step = 10;   /* step size */
	
    celsius = (double)lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

/*
  Exercise 1-5
  Modify the temperature conversion program to print the table in reverse order,
  that is, from 300 degrees to 0.
*/
void exer1_5()
{
    int fahr;

    for (fahr = 300; fahr >= 0; fahr -= 20)
    {
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
    }
}

/*
  copy the characters of the input-stream
  count the number of the characters

  in the console, you should input the key 'Enter' to tell the system
  the end of the input, and the system process the input buffer and output the chars.
  If you input some normal chars with the EOF(Ctrl+Z in Windows) appending, the system
  will deal with the EOF as an indicate of end of line and you should input another EOF
  to tell the system that the input stream is over.
*/
void file_copy()
{
    int ch;
    long nc = 0;
    long nl = 0;

    while ((ch = getchar()) != EOF)
    {
        nc++;

        if (ch == '\n')
        {
            nl++;
        }

        putchar(ch);
    }

    printf("\nthere are %ld chars, %ld lines\n", nc, nl+1);
}

/*
  write a program to count a text file's blanks,tabs,and newlines
  the test file is 'test.txt'
*/
void exer1_8()
{
    int ch;
    long nc, nl, nt, nbl;
    FILE *fp;

    nc = nl = nt = nbl = 0;

    fp = fopen("test.txt", "r");
    if (NULL == fp)
    {
        printf("can't open the file, please check");
        return;
    }

    while ((ch = getc(fp)) != EOF)
    {
        nc++;
        if (ch == '\n')
            nl++;
        else if (ch == '\t')
            nt++;
        else if (ch == ' ')
            nbl++;
        else
            ;
    }

    printf("chars:%ld tabs:%ld blanks:%ld lines:%ld", nc, nt, nbl, nl);
}

/*
  Write a program to copy its input to its output, replacing each string of one or more blanks by a single
  blank
  the test file is 'test.txt'
*/
void exer1_9()
{
    int ch, ch_pre; //ch_pre is the previous char
    ch_pre = 0; //set a non-space value
    FILE *fp;

    fp = fopen("test.txt", "r");
    if (NULL == fp)
    {
        printf("can't open the file, please check");
        return;
    }

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == ' ' && ' ' == ch_pre)
            continue;
        else
            putchar(ch);
        ch_pre = ch;
    }
}

// a word is defined as any sequences of chars that does not contain a blank,tab or new lines
#define IN		1 // inside a word
#define OUT		0 // outside a word

//count lines, words, and characters of the text file
void demo_WordCount()
{
    int ch, nl, nw, nc, state;
    FILE *fp;
	
    fp = fopen("test.txt", "r");
    if (NULL == fp)
    {
        printf("can't open the file, please check");
        return;
    }

    state = OUT;
    nl = nw = nc = 0;
    while ((ch = getc(fp)) != EOF)
    {
        ++nc;
        if ('\n' == ch)
            ++nl;
        if (ch == ' ' || ch == '\t' || ch == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);
}

//exercise1-12. Write a program that prints its input one word per line
void exer1_12()
{
    int ch, state;
    FILE *fp;
	
    fp = fopen("test.txt", "r");
    if (NULL == fp)
    {
        printf("can't open the file, please check");
        return;
    }
	
    state = OUT;
    while ((ch = getc(fp)) != EOF)
    {

        if (!(ch == ' ' || ch == '\t' || ch == '\n'))
        {
            putchar(ch);
            state = IN;
        }
        else if (state == IN)
        {
            state = OUT;
            putchar('\n'); //newline, one word per line
        }
    }

}

int main(int argc, char *argv[])
{
    exer1_9();
		
    return 0;
}


