#include <stdio.h>

int main() {

  int c, nl, nt, nb;
  
  nl = 0; nt = 0; nb = 0;
  while ((c = getchar()) != EOF)
  {
    if(c == ' ')
    {
        ++nb;
    }
    
    if(c == '\t')
    {
        ++nt;
    }
    
    if(c == '\n')
    {
        ++nl;
    }
    
  }
  
  printf("nl = %d nt = %d nb = %d\n", nl, nt, nb);

}

