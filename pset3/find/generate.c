/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checks to make sure that we have either 1 or 2 arugments,
    // the first being the required amount of pseudorandom numbers we want,
    // and the second (which is optional) being the seed value for those pseudorandom numbers
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Converts count of numbers to be generated from string (terminal input) to integer
    int n = atoi(argv[1]);

    // In order to generate a pseudorandom number with `drand48`, we first need to generate a seed,
    // either by using the provided seed number or the current time
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // For the amount of numbers we want, we generate a pseudorandom number for each,
    // seed was already previoulsy generated about with `srand48`
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
