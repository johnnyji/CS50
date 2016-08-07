#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void) {
    string name = GetString();

    for (int i = 0, l = strlen(name); i < l; i++)
    {
        if (i == 0)
        {
            printf("%c", name[i]);
        }
        else if (name[i - 1] == ' ')
        {
            printf("%c", name[i]);
        }
            
    }
    printf("\n");
}
