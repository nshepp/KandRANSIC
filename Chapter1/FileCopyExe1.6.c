#include <stdio.h>

int main() {

  int c, e;
  
  while (e = ((c = getchar()) != 'B'))
  {
    printf("EOF=%d\n", e);
    putchar(c);
  }
  
  printf("%d\n", e);

}

