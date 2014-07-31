//
//  main.c
//  Ex2.5
//
//  Created by Andrew Sheppard on 7/31/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//
//

#include <stdio.h>

int any(char s1[], char s2[]);

int main(int argc, const char * argv[])
{
    char s1[] = "Bloater is bad";
    char s2[] = "";
    
    /*    char s[] = "Bloater likes chocolate"; */
    int i=0, c=c;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    printf("String 2: %s\n", s2);
    
    printf("String 1: %s\n", s1);
    
    printf("Location of match (if no matches -1 is displayed): %d\n", any(s1, s2));
    
    return 0;
}

/* any: returns first location of similar character found in s1 that occurs in s2 */
int any(char s1[], char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)
        for (j = 0; s2[j] != '\0'; j++)
            if (s2[j] == s1[i])
                return i;

    return -1;
}