#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
  int loop_count = 0;
  float change_owed;
  
  do
  {
    change_owed = GetFloat();
  } while (change_owed <= 0);
  
  // Rounds the float to integer conversion to avoid floating point imprecision
  int cents_owed = round(change_owed * 100);
  
  int coin_types[] = {25, 10, 5, 1};
  
  // loops through every type of coin we have
  for (int i = 0; i < sizeof(coin_types) / sizeof(coin_types[0]); i++)
  {
    
    loop_count = i;
    
    int coin_type = coin_types[i];
    
    // if theres at least one quantity of the current coin type we can give back, figure out
    // how many of that coin we can give back
    if (cents_owed >= coin_type)
    {
      int remaining_cents_owed = cents_owed % coin_type;
      int coins_given_of_type = (cents_owed - remaining_cents_owed) / coin_type;
      printf("%i cents: %i\n", coin_type, coins_given_of_type);
      cents_owed = remaining_cents_owed;
    }
    else
    {
      printf("%i cents: 0\n", coin_type);   
    }
  }
  
  printf("Times looped: %i\n", loop_count);
  loop_count = 0;
}