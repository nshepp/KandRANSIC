#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */

int mygetline(char line[], int maxline);
bool iswhitespace(char c);

/* print all lines longer than MAXLINE */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+2];          /* current input line plus '\n' and '\0' */
  
  while ((len = mygetline(line, MAXLINE)) > 0)
    printf("%s\n", trimline(line,len));
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

bool iswhitespace(char c)
{
  if (c==' ' || c=='\b' || '\t')
    return true;
  else
    return false;
}

int trimline(char s[], int len)
{
  int i;
  
  for (i=len-1; i<=0; i--)
  {
    if (iswhitespace(s[i])
      s[i] ='\0';
    else
      break;
  }
  
  return i;
}