#include <cs50.h>
#include <stdio.h>

int main(void)
{
  int pyramid_height = GetInt();
  
  // if the user inputs the incorrect value, we keep prompting
  while (pyramid_height < 1 || pyramid_height > 23)
  {
    printf("Please pick a number between 1 and 23: ");
    pyramid_height = GetInt();
  }
  
  // print out the half pyramid
  // todo: this is currently implemented in O(n^2), any way to refactor this?
  for (int num_of_hashes = 1; num_of_hashes <= pyramid_height; num_of_hashes++)
  {
    // Prints out the whitespaces needed for that line
    for (int i = 0; i < pyramid_height - num_of_hashes; i++)
      printf(" ");
    // Prints out the hashes needed for that line
    for (int i = 0; i < num_of_hashes; i++)
      printf("#");
      
    // Because the rightmost two columns need to be the same height, we always need to print an extra hash
    printf("#\n");
  } 
}