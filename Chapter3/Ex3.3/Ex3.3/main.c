//
//  main.c
//  Ex3.3
//  Created by Andrew Sheppard on 8/14/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#define MAXLEN 1023

void expand(char s1[], char s2[]);

int main(int argc, const char * argv[])
{
    char c;
    char s1[MAXLEN], s2[MAXLEN];
    int i;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    pause();
    
    i = 0;
    while ((c = getchar()) != EOF)
    {
        s1[i++] = c;
    }
    
    s1[i] ='\0';
    
    expand(s1, s2);
    
    printf("input string = s1[%s], output string = s2[%s]\n", s1, s2);
    
    return 0;
}

void expand(char s1[], char s2[])
{
    int i=0, j=0;
    char c;
    
    while ((c=s1[i]) != '\0')
    {
        switch (c) {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                
            case 'A': case 'B': case 'C': case 'D': case 'E':
            case 'F': case 'G': case 'H': case 'I': case 'J':
            case 'K': case 'L': case 'O': case 'M': case 'N':
            case 'P': case 'Q': case 'R': case 'S': case 'T':
            case 'U': case 'V': case 'W': case 'X': case 'Y':
            case 'Z':
                
            case 'a': case 'b': case 'c': case 'd': case 'e':
            case 'f': case 'g': case 'h': case 'i': case 'j':
            case 'k': case 'l': case 'o': case 'm': case 'n':
            case 'p': case 'q': case 'r': case 's': case 't':
            case 'u': case 'v': case 'w': case 'x': case 'y':
            case 'z':
                /* is next char "-" ? */
                /* if the char following A-Za-z0-9 ? */
                /* if yes to both questions, then possibly an expansion,
                   but ONLY if for x-y the condition x<y holds true
                   for x, y in the char range A-Za-z0-9 */
                /* s[i+1] != '\0' ? ((s[i+1] == '-') ? : b;) : break; */
                /* step forward again */;
                
                
                
     
                 
            default:
                s2[j++] = s1[i];
                break;
        }
        
        i++;

    }
    
    
}

char nextASCII(const char c)
{
    switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': /* case '9': */
            return c+1;
        
        case 'A': case 'B': case 'C': case 'D': case 'E':
        case 'F': case 'G': case 'H': case 'I': case 'J':
        case 'K': case 'L': case 'O': case 'M': case 'N':
        case 'P': case 'Q': case 'R': case 'S': case 'T':
        case 'U': case 'V': case 'W': case 'X': case 'Y':
            return c+1;
        
        /* skip [ ... ' */
        case 'Z':
            return 'a';
        
        case 'a': case 'b': case 'c': case 'd': case 'e':
        case 'f': case 'g': case 'h': case 'i': case 'j':
        case 'k': case 'l': case 'o': case 'm': case 'n':
        case 'p': case 'q': case 'r': case 's': case 't':
        case 'u': case 'v': case 'w': case 'x': case 'y':
        /* case 'z': */
            return c+1;
    }
    
    return 0; /* null char */
}
