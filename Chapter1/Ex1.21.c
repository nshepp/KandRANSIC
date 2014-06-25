#include <stdio.h>
#define MAXLINE 1000     /* Maximum length of an input string */
#define TAB_WIDTH 4

int mygetline(char line[], int maxline);
void entab(char s[], int tab_width);

/* entabs a string */

main()
{
  int len;                       /* current line length */
  char line[MAXLINE+1];          /* current input line plus '\0' */
  
  while ((len = mygetline(line, MAXLINE)) != EOF)
    if (len>0)
    {
       entab(line, TAB_WIDTH);
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

void entab(char s[], int tab_width)
{
  int i, j, idx, len, tabs, spaces, whitespaces;
  char c;
  
  /* Finds string length 'len' */
  len = 0;
  while (s[len]!='\0') len++;
  
  /* entabs */
  tabs = spaces = whitespaces = 0;
  i = len-1;
  while (i >= 0)
  {
    c = s[i];
    
    if(c == ' ')
    {
      /* is previous character on a tab stop */
      if ((i+1)%tab_width == 0)
        tabs++;
      else if (tabs == 0) 
        spaces++;
      
      whitespaces++;
    }
    else if (tabs!=0 || spaces!=0) /* new word found */
    {
      /* writes tabs over spaces */
      j = 0;
      while (j++ < tabs) s[i+j+1] = '\t';
      
      /* index of start character for previous word */
      idx = i + whitespaces + 1;
      
      /* compress white space into tabs and spaces */
      j = idx;
      do
      {
        c = s[j];
        
        s[j-(whitespaces-tabs-spaces)] = c;
        
        j++;
      }
      while (c != '\0');
      
      tabs = spaces = whitespaces = 0;  
    }
    
    i--;
  }
}    
    
    
    
    
    
    
    
    
    
    
    
    
