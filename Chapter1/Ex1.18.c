#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */

int mygetline(char line[], int maxline);
int iswhitespace(char c);
void trimline(char s[], int len);

/* delete trailing whitespace */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+1];          /* current input line plus '\0' */
  
  while ((len = mygetline(line, MAXLINE)) != EOF)
    if (len>0)
    {
       trimline(line,len);
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

int iswhitespace(char c)
{
  if (c==' ' || c=='\b' || c=='\t'|| c=='\n')
    return 1;
  else
    return 0;
}

void trimline(char s[], int len)
{
  int i;
  
  for (i=len-1; i>=0; i--)
  {
    if (iswhitespace(s[i]))
      s[i] ='\0';
    else
      break;
  }
}