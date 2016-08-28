/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false. Uses binary search
 */
bool search(int value, int values[], int n)
{

    bool found = false;

    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
        {
            found = true;
            break;
        }
    }

    return found;
    // // If n isn't positive, there is no array to traverse
    // if (n <= 0)
    //     return false;

    // int start = 0; // Start index of values
    // int end = n - 1; // End index of values
    // int middle = (start + end) / 2; // Middle index, setting this as int will floor any floats
    // bool found = false;

    // // While we have no yet traversed the whole array, keep searching
    // while (start <= end)
    // {
    //     printf("Start: %d\nEnd: %d\n\n", start, end);
    //     int curr_val = values[middle];

    //     if (curr_val < value) // Value is in the right half
    //     {
    //         start = middle + 1; // Discard the left half
    //     }
    //     else if (curr_val == value)
    //     {
    //         found = true; // We've found it! Break early out of loop
    //         break;
    //     }
    //     else // Value is in left half
    //     {
    //         end = middle - 1; // Discard the right half
    //     }

    //     // Update the middle
    //     middle = (start + end) / 2;
    // }

    // return found;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    bool sorted = false;

    while (sorted == false)
    {
        // We assume the array is sorted
        sorted = true;

        for (int i = 0; i < n; i++)
        {
            // Swap items if out of order
            if (values[n] > values[n + 1])
            {
                // The moment we make a single swap, that assumption of sorted is broken
                values[n] = values[n + 1];
                values[n + 1] = values[n];
                sorted = false;
            }
        }
    }
    return;
}
