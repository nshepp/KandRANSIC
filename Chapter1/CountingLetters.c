#include <stdio.h>


int main()
{
  int i, j, k, c;
    
  int nupper[26], nlower[26];
  
  
  for(i = 0; i < 26; ++i) nupper[i] = nlower[i] = 0;
    
  while((c = getchar()) != EOF )
  {
    if (c>='A' && c<='Z') nupper[c-'A']++;
    if (c>='a' && c<='z') nlower[c-'a']++;
  }
  
  for(i = 0; i < 26; ++i) 
  {
    printf("%c,%c | ", i+'A', i+'a');
    
    for (j=0; j< nupper[i]; j++)
    {
      putchar('*');
    }
    
    for (k=0; k< nlower[i]; k++)
    {
      putchar('+');
    }
    
    putchar('\n');
  } 
}