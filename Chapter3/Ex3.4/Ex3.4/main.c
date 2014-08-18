//
//  main.c
//  Ex3.4
//
//  Created by Andrew Sheppard on 8/18/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#define MAXLEN 1023

void reverse(char s[]);
void itoa(int n, char s[]);

int main(int argc, const char * argv[])
{
    char c;
    char s[MAXLEN];
    int i;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
//    pause();
    
    printf("INT_MAX = %d, INT_MIN = %d\n", INT_MAX, INT_MIN);
    
    itoa(INT_MAX, s);
    
    printf("INT_MAX = %s\n", s);
    
    itoa(INT_MIN, s);
    
    printf("INT_MIN = %s\n", s);
    
    return 0;
}

void reverse(char s[]) {
    int c, i, j;
    
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        
    }
}
        
        


void itoa(int n, char s[]) {
    
    int i, sign, minval = 0;
    
    if (n == INT_MIN) {
        minval = 1;
        n = INT_MAX;
    }
    
    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do {  /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    }
    while ((n /= 10) > 0);
    if (sign < 0 || minval)
        s[i++] = '-';
    s[i] = '\0';
    
    if (minval) {
        if (s[0] < '9') s[0]++;
    }
    
    reverse(s);
}