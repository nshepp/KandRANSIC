#include <stdio.h>
#include <unistd.h>

#define FLUSH fflush(NULL);

int main(int argc, const char * argv[])
{
    int i, instring = 0, incomment = 0;
    char c, pc = '\0'; /* char and previous char */
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    /* pause(); */
 
    while ((c = getchar())!=EOF)
    {
        if (c=='"' && pc=='\\')
        {
            /* not the beginning of a string, just an embedded double quote */
        }
        else if (c=='"' && instring==0 && incomment==0)
        {
            instring = 1;
            /* printf("Entering string"); */
        }
        else if (c=='"' && instring==1 && incomment==0)
        {
            instring = 0;
            /* printf("Exiting string"); */
        }
        
        if (c=='*' && pc=='/' && instring==0 && incomment==0)
        {
            incomment = 1;
            putchar('\b'); FLUSH
            putchar(' '); FLUSH
        }
        else if (c=='/' && pc=='*' && instring==0 && incomment==1)
        {
            incomment = 0;
            c = getchar(); /* advance one character */
        }
        
        if (incomment == 0) {
            putchar(c); FLUSH
        }
        
        pc = c;
    }
    return 0;
}

