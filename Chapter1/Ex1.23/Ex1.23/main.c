#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    int i, instring = 0, incomment = 0;
    char c, pc = '\0'; /* char and previous char */
    
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    pause();

    while ((c = getchar())!=EOF)
    {
        if (c=='"' && pc=='\\')
        {
            /* not the beginning of a string, just an embedded double quote */
        }
        else if (c=='"' && instring==0)
        {
            instring = 1;
            /* printf("Entering string"); */
        }
        else if (c=='"' && instring==1)
        {
            instring = 0;
            /* printf("Exiting string"); */
        }
        
        if (c=='*' && pc=='/' && instring==0)
            incomment=1;
        else if (c=='/' && pc=='*' && instring==0)
            incomment=0;
        
        if (incomment == 0)
            putchar(c); fflush(NULL);
        
        pc = c;
    }
    return 0;
}

