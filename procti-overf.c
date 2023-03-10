/**
 * @author Timo Grautstueck
 * Overflow calculation in days, for 100 ticks per sec.
*/

#include <stdio.h>
#include <stdlib.h>

double sec_to_days(long int sec);

int
main(void)
{
    printf("Overflow after %15.1f days for 32-bit int\n",
            sec_to_days(__INT32_MAX__ / 100));
    printf("Overflow after %.1f days for 64-bit int\n",
            sec_to_days(__INT64_MAX__ / 100));

    return EXIT_SUCCESS;
}

double 
sec_to_days(long int sec)
{
    return (sec/60/60/24);
}