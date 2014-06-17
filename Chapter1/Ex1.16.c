#include <stdio.h>
#define MAXLINE 30     /* maximum input line size */

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */

main()
{
  int len;                       /* current line length */
  int max;                       /* maximum length seen so far */
  char line[MAXLINE];            /* current input line */
  char longest[MAXLINE];         /* longest line saved here */
  
  max = 0;
  while ((len = mygetline(line, MAXLINE-2)) > 0)
    if (len > max)
     {
       max = len;
       copy(longest, line);
     }
     if (max >= MAXLINE)    /* longest line saved here */
       printf("First %d chars: %s ...\n", MAXLINE-2, longest);
     else if (max > 0)    /* longest line saved here */
       printf("%s\n", longest);
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

/* copy: copy 'from' into 'to'; assume to is a big enough */
void copy(char to[], char from[])
{
  int i;
  i=0;
  while ((to[i] = from[i]) != '\0')
    ++i; 
}