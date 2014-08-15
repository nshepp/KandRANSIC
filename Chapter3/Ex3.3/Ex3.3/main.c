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
char nextASCII(const char c);
int isASCII(const char c);

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
    char c, k;
    
    while ((c=s1[i]) != '\0')
    {
        if (isASCII(c)) {
            if (s1[i+1] == '-') {
                /* is next char a A-Za-z0-9 ? */
                if (isASCII(s1[i+2])) {
                    /* expand */
                    if (s1[i]<s1[i+2]) {
                        for (k=s1[i]; k<s1[i+2]; k=nextASCII(k)) {
                            s2[j++] = k;
                        }
                        
                        i += 2;
                    }
                } else if (s1[i+2] == '\0') { /* end of string reached */

                    s2[j++] = s1[i+1]; /* copy '-' */

                    s2[j++] = '\0';
                    
                    break;
                }
            } else if (s1[i+1] == '\0') { /* end of string reached */
                
                s2[j++] = '\0';
                
                break;
            }
        }
        
        s2[j++] = s1[i];
        
        i++;
    }
    
    s2[j] = '\0';
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


/* is char c A-Za-z0-9 ? */
int isASCII(const char c)
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
            return 1;
    }
    
    return 0;
}
