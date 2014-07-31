//
//  main.c
//  Ex2.4
//
//  Created by Andrew Sheppard on 7/31/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(int argc, const char * argv[])
{
    char s1[] = "Bloater is bad";
    char s2[] = "Bloater is bad";
    
/*    char s[] = "Bloater likes chocolate"; */
    int i=0, c=c;

    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    printf("String 2: %s\n", s2);
    
    printf("String 1 before squeeze: %s\n", s1);
    
    squeeze(s1, s2);
    
    printf("String 1 after squeeze: %s\n", s1);
    
    return 0;
}

/* squeeze: delete all common letters from s1 found in s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k, found;
    for (i = k = 0; s1[i] != '\0'; i++) {
        
        found = 0;
        
        for (j = 0; s2[j] != '\0'; j++)
            if (s2[j] == s1[i]) {
                found = 1;
                break;
            }
        
        if (!found) s1[k++] = s1[i];
    }
    
    s1[k] = '\0';
}