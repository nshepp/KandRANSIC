#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */
#define TAB_WIDTH 4

int mygetline(char line[], int maxline);
void detab(char s[], int tab_width);

/* detabs a string */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+1];          /* current input line plus '\0' */
  
  while ((len = mygetline(line, MAXLINE)) != EOF)
    if (len>0)
    {
       detab(line, TAB_WIDTH);
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

void detab(char s[], int tab_width)
{
  int i, j, len, tabs=0, newlen, shift;
  char c;
  
  /* Finds string length 'len' and counts tabs */
  i = 0;
  len = 0;
  while (s[i]!='\0')
  {
    if (s[i++]=='\t') tabs++;
    len++;
  }
  
  /* shift moves string along the equivalent length of new tabs */
  shift = tabs * (tab_width-1);
  
  /* new length of original string plus alotted for new spaces */
  newlen = len + shift;
  
  /* Move string including '\0' */
  i = len;
  while (i>=0)
  {
    s[i+shift] = s[i];
    i--;
  }

  /* Traverse string starting at the front */
  i = 0; tabs = 0;
  while (i<len)
  {
    c = s[i+shift];
    if (c=='\t')
    {
      for (j=0; j<tab_width; j++) s[i+tabs*(tab_width-1)+j] = ' ';
      tabs++; 
    }
    else
      s[i+tabs*(tab_width-1)] = c;
    
    i++;
  }
}