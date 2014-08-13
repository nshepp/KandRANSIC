//
//  main.c
//  Ex3.2
//
//  Created by Andrew Sheppard on 8/13/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#define MAXLEN 1023

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main(int argc, const char * argv[])
{
    char c;
    char t[MAXLEN], s[MAXLEN];
    int i;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    pause();
    
    i = 0;
    while ((c = getchar()) != EOF)
    {
        t[i++] = c;
    }
    
    t[i] ='\0';

    escape(s, t);
    
    printf("input string = t[%s], output string = s[%s]\n", t, s);
    
    unescape(t, s);
    
    printf("input string = s[%s], output string = t[%s]\n", s, t);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    char c;
    
    i = j = 0;
    while ((c =t[i]) != '\0')
    {
        switch (c) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        i++;
    }
}

void unescape(char s[], char t[])
{
    int i, j;
    char c;
    
    i = j = 0;
    while ((c =t[i]) != '\0')
    {
        switch (c) {
            case '\\':
                if (t[i+1] == 't') {
                    s[j++] = '\t'; i++;
                } else if (t[i+1] == 'n') {
                    s[j++] = '\n'; i++;
                } else
                    s[j++] = '\\';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        
        i++;
    }
}
