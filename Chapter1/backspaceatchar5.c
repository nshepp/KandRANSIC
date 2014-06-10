#include <stdio.h>

int main(void)
{
  int c, cnt=0;
  
  while ((c = getchar()) != EOF)
  {
    putchar(c);
    
    cnt++;
    
    if (cnt==5) putchar('\b');
  }
}