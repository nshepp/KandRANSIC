#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */
#define WRAP_COL 16      /* Column at which the line is wrapped */

int mygetline(char line[], int maxline);
void linewrap(char s[], int tab_width);
void oneblank(char s[]);
int isblank(char c);

/* wraps a string to next line */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+1];          /* current input line plus '\0' */
  
  while ((len = mygetline(line, MAXLINE)) != EOF)
    if (len>0)
    {
       linewrap(line, WRAP_COL);
       printf("%s\n", line);
    }
  return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
  int c, i;
  
  for (i = 0; (c = getchar()) !=EOF && c!='\n'; ++i)
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

void linewrap(char s[], int wrap_col)
{
  oneblank(s);
}

int isblank(char c)
{
  if (c==' ' || c=='\t')
    return 1;
  else
    return 0; 
}

/* compress whitespace to one blank character */
void oneblank(char s[])
{
  int i = 0, ws = 0, shift = 0;
  
  while (s[i]!='\0')
  {
    if (isblank(s[i]))
    {
      ws++;
    }
    else if (ws > 1)
    {
      shift = ws - 1;
      
      ws = 0;
      
      s[i-shift] = s[i];
    }    
    else /* non-blank */
    {
      s[i-shift] = s[i];
    }
    
    i++;
  }
  
  s[i-shift] = '\0';
}