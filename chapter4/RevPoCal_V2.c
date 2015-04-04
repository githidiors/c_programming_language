/* read a line and split it into tokens, then parse it */
/* add the modulus(%) operator and provisoins for negative numbers */

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 1000 /* maximum input line size */
#define MAXNUM 100  /* maximum token per line */

enum _TokenType{
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLE,
    DIVIDE,
    MOD,
    SIN,
    COS,
    EXP,
    POW,
    QUIT
};

#define STACK_SIZE MAXNUM
double stack[STACK_SIZE];
int sp = 0; //next free stack position

/********************************************************************************/

int zgetline(char line[], int lim); //read a line

void push(double);
double pop(void);
void clear_stack(void);

int gettokentype(char s[]);

int main()
{
    char temp[MAXLINE];
    char *tokens[MAXNUM];
    int token_num = 0;
    int type, i;
    double op2;

    printf("Reverse Polish Calculator(type 'Quit' to quit)\n");
    while (zgetline(temp, MAXLINE) > 0) {
        if (!strcmp(temp, "Quit \n"))
            break;

        token_num = 0;
        if ((tokens[token_num] = strtok(temp, "\t ")) == NULL) {
            continue;
        }
        else {
            token_num++;
        }
        while ((tokens[token_num] = strtok(NULL, "\t ")) != NULL) {
            token_num++;
        }
        for (i = 0; i < token_num; i++) {
            type = gettokentype(tokens[i]);
            if (type == QUIT) {
                printf("\t%.8g\n", pop());
                clear_stack();
                break;                
            }
            switch (type) {
            case NUMBER:
                push(atof(tokens[i]));
                break;
            case PLUS:
                push(pop()+pop());
                break;
            case MULTIPLE:
                push(pop()*pop());
                break;
            case MINUS:
                op2 = pop();
                push(pop()-op2);
                break;
            case DIVIDE:
                op2 = pop();
                if (op2 != 0.0)
                    push(pop()/op2);
                else
                    printf("error: zero divisor\n");
                break;
            case MOD:
                op2 = pop();
                push((int)pop()%(int)op2);
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(sin(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            default:
                printf("error: unknown command %s\n", tokens[i]);
                break;
            }
        }
        printf("Reverse Polish Calculator(type 'Quit' to quit)\n");
    }

    return 0;
}


/* read a line into line, return length*/
int zgetline(char line[], int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
    {
        line[i++] = ' ';  //in order to split the '\n'
        line[i++] = '\n';
        line[i] = '\0';
    }
    else
        line[i] = '\0';

    return i;
}

void push(double f)
{
    if (sp < STACK_SIZE)
        stack[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return stack[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clear_stack(void)
{
    sp = 0;
}

/* return the operator type */
int gettokentype(char s[])
{
    int i;
    char *oper_table[] = {"+","-","*","/","%","sin","cos","exp","pow", "\n"};
    
    for (i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i]))
            return NUMBER;
    }
    
    for (i = 0; i < sizeof(oper_table)/sizeof(oper_table[0]); i++) {
        if (!strcmp(s, oper_table[i]))
            return i+1;
    }
    return -1; //unknown type
}
