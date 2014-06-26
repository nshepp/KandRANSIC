#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */
#define WRAP_COL 16      /* Column at which the line is wrapped */

int mygetline(char line[], int maxline);
void linewrap(char s[], int tab_width);

/* entabs a string */

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
  if (i<lim)
    lim = i;
  s[lim] = '\0';
  if (c == EOF)
    return EOF;
  else
    return i;
}

void linewrap(char s[], int wrap_col)
{
  int i, len;
  char c;
  
  /* Finds string length 'len' */
  len = 0;
  while (s[len]!='\0') len++;
  
  if (len < wrap_col) 
    return;
  else 
  {
    if (c!=' ' || c!='\t')
    {
      /* move word along 2 characters to place hyphen and newline char */
      i = len;
      do
      {
        c = s[i];
        
        s[i+2] = c;
        
        i--;
      }
      while (i>=wrap_col);
      
      s[wrap_col] = '-';
      s[wrap_col+1] = '\n';

    }  
  }  
}