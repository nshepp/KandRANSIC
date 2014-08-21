//
//  main.c
//  Ex3.5
//
//  Created by Andrew Sheppard on 8/19/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <string.h>

#define MAXLEN 1023
#define BIN 2   // binary
#define OCT 8   // octal
#define DEC 10  // decimal
#define HEX 16  // hexadecimal

void reverse(char s[]);
void itob(int n, char s[], int b);
char nextdigit(const char c);
void addone(char s[], int b);

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z'};

int main(int argc, const char * argv[])
{
    char c;
    char s[MAXLEN];
    int i, b = 10;
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);
    
    //    pause();
    
    printf("INT_MAX = %d, INT_MIN = %d\n", INT_MAX, INT_MIN);
    
    // Test 1: INT_MAX
    itob(INT_MAX, s, 2);
    assert(strcmp(s, "1111111111111111111111111111111") == 0);
    printf("INT_MAX = %s\n", s);

    
    // Test 2: INT_MAX
    itob(INT_MAX, s, 8);
    assert(strcmp(s, "17777777777") == 0);
    printf("INT_MAX = %s\n", s);
    

    // Test 3: INT_MAX
    itob(INT_MAX, s, 10);
    assert(strcmp(s, "2147483647") == 0);
    printf("INT_MAX = %s\n", s);
    
    // Test 4: INT_MAX
    itob(INT_MAX, s, 16);
    assert(strcmp(s, "7FFFFFFF") == 0);
    printf("INT_MAX = %s\n", s);

    // Test 5: INT_MIN
    itob(INT_MIN, s, 2);
    assert(strcmp(s, "-10000000000000000000000000000000") == 0);
    printf("INT_MAX = %s\n", s);


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

void itob(int n, char s[], int b) {
    
    int i, sign, minval = 0;
    
    if (n == INT_MIN) {
        minval = 1;
        n = INT_MAX;
    }
    
    if ((sign = n) < 0) /* record sign */
        n = -n;
    i = 0;
    do {  /* generate digits in reverse order */
        s[i++] = digits[n % b]; /* get next digit */
    }
    while ((n /= b) > 0);
    if (sign < 0 || minval)
        s[i++] = '-';
    s[i] = '\0';
    
    
    // correct for last digit
    if (minval) {
        addone(s, b);
    }
    
    reverse(s);
}

void addone(char s[], int b)
{
    int i;
    char c;
    int carry = 0;
    
    switch (b)
    {
        case BIN:
            i = 0;
            while ((c=s[i])!='\0' && c!='-')
            {
                if (c==digits[b-1])
                {
                    s[i] = '0';
                    carry = 1;
                }
                else
                {
                    s[i] = nextdigit(c); // increment to next digit
                    carry = 0;
                    break;
                }
                
                i++;
            }
            // TODO: minus sign?
            if (carry)
            {
                s[i]   = '1';
                s[i+1] = '-';
                s[i+2] = '\0';
            }
            break;
        case OCT:
            break;
        default:
            exit(1);
    }
}

char nextdigit(const char c)
{
    switch (c) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8':
            return c+1;
            
        case '9':
            return 'A'; // hex
            
        case 'A': case 'B': case 'C': case 'D': case 'E':
        case 'F': case 'G': case 'H': case 'I': case 'J':
        case 'K': case 'L': case 'O': case 'M': case 'N':
        case 'P': case 'Q': case 'R': case 'S': case 'T':
        case 'U': case 'V': case 'W': case 'X': case 'Y':
            return c+1;
  }
    
    return 0; /* null char */
}





