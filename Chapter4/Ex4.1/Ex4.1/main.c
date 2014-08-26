//
//  main.c
//  Ex4.1
//
//  Created by Andrew Sheppard on 8/26/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strindex2(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern for search for */

/* find all lines matching pattern */
int main(int argc, const char * argv[])
{
    char line[MAXLINE];
    int found = 0, i = 0, position = 0;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    pause();

    
    while (mygetline(line, MAXLINE) > 0)
        if ((position=strindex2(line, pattern)) >= 0) {
            printf("%s", line);
            found++;
            printf("Match found at %d\n", position);
        }
    return found;
}

/* getline: get line into s, return length */
int mygetline(char s[], int lim)
{
    int c, i;
    
    i = 0;
    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;
    
    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}

/* strindex2: return index of t in s, -1 if none */
int strindex2(char s[], char t[])
{
    int i, lens = 0, lent = 0;
    
    lens = (int)strlen(s);
    lent = (int)strlen(t);
    
    for (i=lens-lent; i>=0 ; i--)
        if (strncmp(&s[i], t, lent)==0)
            return i;
    
    return -1;
}