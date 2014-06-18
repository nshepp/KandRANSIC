#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */

int mygetline(char line[], int maxline);
void reverse(char s[]);

/* reverses a string */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+1];          /* current input line plus '\0' */
  
  while ((len = mygetline(line, MAXLINE)) != EOF)
    if (len>0)
    {
       reverse(line);
       printf("%s\n", line);
    }
    else
    {
      /* skip line */
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

void reverse(char s[])
{
  int i, len=0;
  char c;
  
  while (s[len]!='\0') len++;
  
  for (i=len-1; i>=len/2; i--)
  {
    c = s[i];
    s[i] = s[len-i-1];
    s[len-i-1] = c; 
  }
}