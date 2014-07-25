//
//  main.c
//  Ex2.3
//
//  Created by Andrew Sheppard on 7/25/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int htoi(char s[]);
int hexchar(const char c);

#define HEX "0x000*"

int main(int argc, const char * argv[])
{
    int i=0;
    char s[] = HEX;
    
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    printf("%s = %d\n", s, htoi(s));
    
    return 0;
}

int htoi(char s[])
{
    int i, len, val, mult;
    int length; /* effective length of string - minus "0x" */
    
    /* length of string */
    len = 0;
    while (s[len]!='\0')
    {
        len++;
    }
        
    /* leading 0x prefix? */
    if (len>2 && s[0]=='0' && (s[1]=='X' || s[1]=='x'))
    {
        length = len - 2;
    }
    else
        length = len;
    
    val = 0; mult = 1;
    for (i=len-1; i>=len-length; i--)
    {
        val += (hexchar(s[i])) * mult;
        
        mult *= 16;
    }
    
    return val;
}

int hexchar(const char c)
{
    switch(c)
    {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A':
        case 'a': return 10;
        case 'B':
        case 'b': return 11;
        case 'C':
        case 'c': return 12;
        case 'D':
        case 'd': return 13;
        case 'E':
        case 'e': return 14;
        case 'F':
        case 'f': return 15;
        default: printf("Invalid Hex Character.\n"); exit(0);
    }
}
