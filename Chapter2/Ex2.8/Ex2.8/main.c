//
//  main.c
//  Ex2.8
//
//  Created by Andrew Sheppard on 8/5/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

unsigned rightrot(unsigned char x, int n);

#include <stdio.h>
#include <limits.h>

int main(int argc, const char * argv[])
{
    int i=0;
    unsigned char x = 1;
    int n = 1;
    unsigned char result;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    result = rightrot(x, n);
    
    printf("sifeof(unsigned) = %lu\n", sizeof(unsigned char));
    
    printf("rightrot(%d,%d) = %u\n", x, n, result);
    
    return 0;
}

unsigned rightrot(unsigned char x, int n)
{
    int i;
    int word_width = sizeof(unsigned char) * CHAR_BIT;
    unsigned char y = ~0;
    
    for (i=0; i<n; i++) {
        
        /* isolate the LSB */
        y = x << (word_width-1);
        
        /* shift x 1 bit to the right, MSB padded with 0 */
        x = x >> 1;
        
        /* rotate bits by copying y to x */
        x = x + y;
    }
    
    return x;
}