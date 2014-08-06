//
//  main.c
//  Ex2.9
//
//  Created by Andrew Sheppard on 8/6/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

int bitcount(unsigned char x);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i=0;
    unsigned char x = 7;
    int result;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    result = bitcount(x);
    
    printf("bitcount(%ud) = %d\n", x, result);
    
    return 0;
}

int bitcount(unsigned char x)
{
    unsigned int c; // c accumulates the total bits set in x
    
    for (c = 0; x; c++)
    {
        x &= x - 1; // clear the least significant bit set
    }
    
    return c;
}