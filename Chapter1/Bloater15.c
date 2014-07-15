#include <stdio.h>

/* Bloater is tragically good looking */
int main(int argc, const char * argv[])
{
    char c; /* not "/*" or  "*" */
    while ((c = getchar())!=EOF)
    {
        putchar(c); /* Puts character to output */
    }
    return 0;
}

