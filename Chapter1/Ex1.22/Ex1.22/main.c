#include <stdio.h>
#include <unistd.h>

#define MAXLINE 1000     /* Maximum length of an input string */
#define WRAP_COL 30      /* Column at which the line is wrapped */

int mygetline(char line[], int maxline);
void linewrap(char s[], int len, int tab_width);
void oneblank(char s[]);
int myisblank(char c);
void moveright(char s[], int len, int shift);

/* wraps a string to next line */

int main(int argc, char *argv[])
{
    int i;
    int len;                       /* current line length */
    char line[MAXLINE+1];          /* current input line plus '\0' */
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    for (i=0; i<WRAP_COL; i++)
        printf("%1d", i%10);
    printf("\n\n");
    
    pause();
    
    while ((len = mygetline(line, MAXLINE)) != EOF)
        if (len>0)
        {
            linewrap(line, len, WRAP_COL);
            printf("%s\n", line);
        }
    return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    
    for (i = 0; (c = getchar())!=EOF && c!='\n'; ++i)
        if (i < lim)
            s[i] = c;
    if (i < lim)
        lim = i;
    s[lim] = '\0';
    if (c == EOF)
        return EOF;
    else
        return i;
}

void linewrap(char s[], int len, int wrap_col)
{
    int i, j;
    char c, d;
    
    oneblank(s);
    
    if (len <= wrap_col) return;
    
    /* break lines */
    i = wrap_col;
    do
    {
        c = s[i];
        d = s[i+1];
        printf("i, c, d = %d, %c, %c\n", i, c, d);
       
        if (myisblank(c))
            s[i] = '\n';
        else
        {
            j = i;
            while (!myisblank(s[j]) && i-j<wrap_col)
                j--;
            
            
            if ((i-j)==wrap_col && !myisblank(d)) /* hyphenate */
            {
                printf("Hyphenate line\n");
                
                moveright(&s[i], len-i, 2);
                
                s[i-1] = '-';
                s[i] = '\n';
                
                len += 2; /* effective length of string has increased by two chars: '-' and '\n' */
                
                i += wrap_col + 1; /* account for '-' */
            }
            else /* break line */
            {
                printf("Break line\n");
                
                s[j] = '\n';
                
                i = j + 1 + wrap_col;
            }
        }
    }
    while (i < len);
}

int myisblank(char c)
{
    if (c==' ' || c=='\t')
        return 1;
    else
        return 0;
}

/* compress whitespace to one blank character */
void oneblank(char s[])
{
    int i = 0, ws = 0 /* whitespace count */, wc = 0 /* word count */, shift = 0, inword = 0;
    char c;
    
    while (s[i]!='\0')
    {
        c = s[i];
        
        /* outside word */
        if (myisblank(c))
        {
            inword = 0;
            ws++;
        }
        else /* inside word */
        {
            if (!inword) wc++;
            inword = 1;
        }
        
        if (inword && ws>0)
            shift = ws - wc + 1;
        else
            shift = 0;
        
        s[i-shift] = c;
        if (shift > 0) s[i] = ' ';
        
        i++;
    }
    
    s[i-shift] = '\0';
}

/* move word along 2 characters to place hyphen and newline char */
void moveright(char s[], int len, int shift)
{
    char c;
    int k = len;
    do
    {
        c = s[k];
        
        s[k+shift] = c;
        
        k--;
    }
    while (k>=0);
}