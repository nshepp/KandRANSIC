#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */

int mygetline(char line[], int maxline);
int iswhitespace(char c);

/* delete trailing whitespace */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+2];          /* current input line plus '\n' and '\0' */
  
  while ((len = mygetline(line, MAXLINE)) > 0)
    if (len>2)
    {
       trimline(line,len);
       printf("%s", line);
    }
  return 0;
}

/* getline: read a line into s, return length */
int mygetline(char s[], int lim)
{
  int c, i;
  
  for (i = 0; (c = getchar()) !=EOF && c!='\n'; ++i)
    if (i <= lim)
      s[i] = c;
  if (i<lim)
    lim = i;    
  if (c == '\n')
  {
    s[lim] = c;
    ++i;
  }
  s[lim+1] = '\0';
  return i;
}

int iswhitespace(char c)
{
  if (c==' ' || c=='\b' || c=='\t'|| c=='\n')
    return 1;
  else
    return 0;
}

int trimline(char s[], int len)
{
  int i;
  
  for (i=len-2; i<=0; i--)
  {
    if (iswhitespace(s[i]))
      s[i] ='\0';
    else
      break;
  }
  
  return i;
}