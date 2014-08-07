//
//  main.c
//  Ex3.1
//
//  Created by Andrew Sheppard on 8/7/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//

int binsearch(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n = 5, x = 5, result;
    int v[] = {1, 3, 5, 7, 9};
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    result = binsearch(x, v, n);
    
    printf("Valued returned: %d\n", result);
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}


int binsearch1(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x == v[mid]) /* found match */
            return mid;
    }
    
    return -1; /* no match */
}
