#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0  /* outside a word */


int main()
{
  int i, j, c, lc = 0, state;
  
  int nletter[11];
  
  for(i = 0; i < 11; ++i) nletter[i] = 0;
  
  state = OUT;
  
  while((c = getchar()) != EOF )
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      if (state == IN)
      {
        ++nletter[lc-1];
      }
      state = OUT;
      lc = 0;
    }
    else
    {
      state = IN;
      ++lc;      
    }
  }
  
  for(i = 0; i < 11; ++i) 
  {
    printf("%2d | ", i+1);
    
    for (j=0; j< nletter[i]; j++)
    {
      putchar('*');
    }
    putchar('\n');
  } 
}