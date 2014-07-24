//
//  main.c
//  Ex2.2
//

/*
for (i=0, i<lim-1 && (c=getchar()) != '\n' && c != EOF, ++i)
    s[i]=c
*/

#include <stdio.h>
#include <unistd.h>

#define MAXLEN 1000

int main(int argc, const char * argv[])
{
    int i=0, lim=MAXLEN;
    char s[MAXLEN];
    char c;
    
    pause();
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    while (1)
    {
        if (i>=lim-1) break;
        if ((c=getchar()) == '\n') break;
        if (c ==EOF) break;
        s[i]=c;
        i++;
    }
}

