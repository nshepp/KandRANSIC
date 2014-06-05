#include <stdio.h>

/* print Celsius-Fahrenheit table for celsius = -20, 0, ..., 200 */

int main()
{
    printf("Cels  Fahr\n");
    
    float fahr, celsius;
	int lower, upper, step;

	lower = -20;   	/* Lower limit of temperature table */
	upper = 200;    /* Upper limit */
	step = 20; 	/* Step size */

	celsius = lower;
	while (celsius <= upper)
	{
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
