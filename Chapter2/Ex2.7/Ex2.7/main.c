//
//  main.c
//  Ex2.7
//
//  Created by Andrew Sheppard on 8/5/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

unsigned invert(unsigned x, int p, int n);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i=0;
    unsigned x = 8;
    int p = 0;
    int n = 4;
    unsigned result;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    result = invert(x, p, n);
    
    printf("invert(%d,%d,%d) = %d\n", x, p, n, result);
    
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned pbits = ~0; /* bit pattern for n bits at position p */
    
    /* make n bits one at position p */
    pbits = pbits << n;
    pbits = ~pbits;
    pbits = pbits << p;
    
    /* invert n number of bits in x at position p */
    return x ^ pbits;
}