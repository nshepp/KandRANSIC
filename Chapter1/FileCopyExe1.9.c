#include <stdio.h>

int main() {
  
  int c, p='b';
  
  while ((c = getchar()) != EOF)
  {
    if(p==' ' && c==' ')
    { /* do nothing */}
    else 
    {
      putchar(c);
    }
    
    p = c;
  }
}

