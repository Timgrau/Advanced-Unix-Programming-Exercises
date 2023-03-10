/**
 * @author Timo Grautstueck
 * 
 * This program returns the past seconds since 1970 and calculates
 * the maximum years to reach for a 4 and 8 byte int
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#define UNIX_REF_TIME 1970

float sec_to_years(long sec);

int 
main(void)
{   
    time_t *curr_time;
    float max32_year, max64_year;

    if(time(curr_time) < 0) {
        perror("Could not set time to pointer!");

        return EXIT_FAILURE;
    }

    printf("%ld sec passed since %d\n", *curr_time, UNIX_REF_TIME);

    max32_year = UNIX_REF_TIME + sec_to_years(__INT32_MAX__);
    max64_year = UNIX_REF_TIME + sec_to_years(__INT64_MAX__);

    printf("Approximately to year %14.1f with a 4 Byte integer\n", max32_year);
    printf("Approximately to year %.1f with a 8 Byte integer\n", max64_year);

    return EXIT_SUCCESS;
}

float
sec_to_years(long sec)
{
    return (sec/60/60/24/365);
}