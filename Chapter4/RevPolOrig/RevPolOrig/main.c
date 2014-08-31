//
//  main.c
//  RevPolOrig
//
//  Created by Andrew Sheppard on 8/27/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100 /*maximum depth of val stack */
#define BUFSIZE 100


int getop(char []);
void push(double);
double pop(void);

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */
int getch(void);
void myungetch(int);
char buf[BUFSIZE];   /* buffer for ungetch */
int bufp = 0;        /* next free position in buf */


int main(int argc, const char * argv[])
{
    int type, i = 0;
    double op2;
    char s[MAXOP];
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    pause();
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push (atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unkown command %s\n", s);
                break;
        }
    }
    return 0;
}




void push(double f)
{
    
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    
}


/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;   /* not a number */
    i = 0;
    if (isdigit(c))  /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            s[i] = '\0';
    if (c != EOF)
        myungetch(c);
    return NUMBER;
}

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf [--bufp] : getchar();
}


void myungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}