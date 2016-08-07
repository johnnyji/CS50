#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants

#define FALSE 0
#define TRUE 1
#define NUM_OF_ALPHABETS 26
#define ASCII_ALPHABET_CAP_MIN 65
#define ASCII_ALPHABET_CAP_MAX 90
#define ASCII_ALPHABET_REG_MIN 97
#define ASCII_ALPHABET_REG_MAX 122

// Prototype

int IsAsciiAlphabet(int char_code);


// Implementation

int main(int argc, char* argv[])
{

    // If the user didn't provide a key option, we terminate the program
    if (argc != 2)
    {
        printf("Please enter a position number key as the only argument!\n");
        return 1;
    }

    // Convert the user's key into an integer and
    // make sure that it is always less than 26, if not, we'll wrap it around to be, ie:
    // 26 -> 0
    // 28 -> 2
    // 13 -> 13
    int key = atoi(argv[1]) % NUM_OF_ALPHABETS;

    // Declare the text and the encrypted text variables
    printf("Enter some text to encrypt: ");
    string text = GetString(); 
    int text_length = strlen(text);
    char encrypted_text[text_length];
    
    for (int i = 0; i < text_length; i++)
    {
        // For every alphabet in the user's input text, change the char to ASCII
        // and add the relevant number of numbers (key) to change the character,
        // and add the newly "encrypted" character to the `encrypted_text` string
        if (IsAsciiAlphabet(text[i]))
        {
            int ascii_char_code = (int) text[i];
            encrypted_text[i] = (char) (ascii_char_code + key);
        }
        else
        {
            encrypted_text[i] = text[i];
        }
    }

    printf("Encrypted: %s\n", encrypted_text);
    return 0;
}

/**
 * Checks if a given ascii code is an alphabet character between a-z or A-Z
 */
int IsAsciiAlphabet(int char_code)
{
    // if the character is a capitalized alphabet
    if (char_code >= ASCII_ALPHABET_CAP_MIN && char_code <= ASCII_ALPHABET_CAP_MAX)
        return TRUE;
    // if the character is a lower cased alphabet
    if (char_code >= ASCII_ALPHABET_REG_MIN && char_code <= ASCII_ALPHABET_REG_MAX)
       return TRUE;

    return FALSE;
}
