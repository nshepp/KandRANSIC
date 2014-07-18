#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    int i;
    char c;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    printf("ABCDEF"); fflush(NULL);
    
    /* pause(); */
    
    printf("\b\b\b"); fflush(NULL);
    
    /* c = getchar(); */
    
    return 0;
}

