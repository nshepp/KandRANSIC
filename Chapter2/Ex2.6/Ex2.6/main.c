//
//  main.c
//  Ex2.6
//
//  Created by Andrew Sheppard on 8/1/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

unsigned setbits(unsigned x, int p, int n, unsigned y);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i=0;
    unsigned x = 8;
    unsigned y = 1;
    int p = 2;
    int n = 1;
    unsigned result;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    result = setbits(x, p, n, y);
    
    printf("setbits(%d,%d,%d,%d) = %d\n", x, p, n, y, result);
    
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned nbits = ~0; /* bit pattern for lower n bits */
    unsigned pbits = ~0; /* bit pattern for n bits at position p */
    
    /* make lower n bits one */
    nbits = nbits << n;
    nbits = ~nbits;
    
    /* make n bits zero at position p */
    pbits = pbits << n;
    pbits = ~pbits;
    pbits = pbits << p;
    pbits = ~pbits;
    
    /* isolate lower n bits of y */
    y = y & nbits;
    
    /* move lower n bits of y to position p */
    y = y << p;
    
    /* zero out n bits at position p for x */
    x = x & pbits;
    
    /* copy n lower bits of y to x at position p */
    return x | y;
}