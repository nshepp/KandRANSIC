//
//  main.c
//  Ex3.1
//
//  Created by Andrew Sheppard on 8/7/14.
//  Copyright (c) 2014 Andrew Sheppard. All rights reserved.
//
#include <assert.h>

int binsearch(int x, int v[], int n);
int binsearch1(int x, int v[], int n);

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int i, n = 5, result;
    int v[] = {2, 3, 5, 7, 9};
    
    for (i=0; i<argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    // Test < lower bound.
    result = binsearch1(1, v, n);
    assert(result==-1);
    printf("Valued returned: %d\n", result);
    
    // Test > high bound.
    result = binsearch1(10, v, n);
    assert(result==-1);
    printf("Valued returned: %d\n", result);
    
    // Test equal v[0] bound.
    result = binsearch1(2, v, n);
    assert(result==0);
    printf("Valued returned: %d\n", result);

    // Test equal v[hi] bound.
    result = binsearch1(9, v, n);
    assert(result==4);
    printf("Valued returned: %d\n", result);

    // Test != any v[].
    result = binsearch1(4, v, n);
    assert(result==-1);
    printf("Valued returned: %d\n", result);

    // Test == any of the middle v[] values.
    result = binsearch1(5, v, n);
    assert(result==2);
    printf("Valued returned: %d\n", result);

    return 0;
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
    while (low<=high && v[(mid = low + (high-low) / 2)] != x)
    {
        if (v[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return  (v[mid] == x) ? mid : -1;
}
