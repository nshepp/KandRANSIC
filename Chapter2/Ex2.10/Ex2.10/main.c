//
//  main.c
//  Ex2.10
//
//  Created by Andrew Sheppard on 8/7/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

void lower(char s[]);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i=0;
    char s[] = "ABCabc123!@#AZaz";
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    printf("s[] = %s\n", s);
    
    lower(s);
    
    printf("lower(s[]) = %s\n", s);
    
    return 0;
}

void lower(char s[])
{
    char c;
    int i = 0;
    
    while ((c=s[i]) != '\0')
    {
        (c>='A' && c<='Z') ? (s[i] = (c+=32)) : 0 ;
        
        i++;
    }
}