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
  int i, j, k, len, spaces;
  char c;
  
  /* Finds string length 'len' */
  len = 0;
  while (s[len]!='\0') len++;
  
  /* detabs */
  i = 0;
  while (i < len)
  {
    c = s[i];
    
    if(c == '\t') 
    {
      spaces = (i/tab_width + 1) * (tab_width) - i - 1;
      
      /* shift remainder of string to the right */
      j = len;
      while(j >= i + 1)
      {
        s[j+spaces] = s[j];
        
        j--;
      }
      
      /* backfill with blanks */
      for(k = 0; k <= spaces; k++) s[i+k] = ' ';
      
      i += spaces + 1;
      
      len += spaces;
    }
    else
      i++;
  }
  
}