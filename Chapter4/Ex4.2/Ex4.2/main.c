//
//  main.c
//  Ex4.2
//
//  Created by Andrew Sheppard on 8/27/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

double myatof(char s[]);

int main(int argc, const char * argv[])
{
    char s[] = "-01.2";
    double result;
    
    result = myatof(s);
    
    printf("The result is %f\n", result);
}

double myatof(char s[])
{
    double val, power;
    int i, sign;
    
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}