#include <cs50.h>
#include <stdio.h>


// Declarations

int GetPositiveInt (void);


// Implementation

int main (void)
{
  // Default values
  int ounces_per_gallon = 128;
  int ounces_per_bottle = 16;
  float gallons_used_per_min = 1.5;
  int length_of_shower = GetPositiveInt();
  
  // Calculate how much water was used 
  int total_gallons_used = length_of_shower * gallons_used_per_min;
  int bottles_used = (total_gallons_used * ounces_per_gallon) / ounces_per_bottle;
  
  printf("minutes: %i\n", length_of_shower); 
  printf("bottles: %i\n", bottles_used); 
}

// Gets a positive integer from the user
int GetPositiveInt (void)
{
  int x = 0;
  
  do {
    x = GetInt(); 
  } while (x < 1);
  
  return x;
}