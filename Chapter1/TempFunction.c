#include <stdio.h>

int fahrcels(int m);


/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */

int main()
{
	int fahr;
	int lower, upper, step;

	lower = 0;   	/* Lower limit of temperature table */
	upper = 300;    /* Upper limit */
	step = 20; 	/* Step size */

	fahr = lower;
	while (fahr <= upper)
	{
		printf("%d\t%d\n", fahr, fahrcels(fahr));
		fahr = fahr + step;
	}
  
  return 0;
  
}

int fahrcels(int fahr)
{
    return (5 * (fahr-32) / 9); 
} 