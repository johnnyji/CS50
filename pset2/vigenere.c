#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants

#define FALSE 0
#define TRUE 1
#define ASCII_ALPHABET_UPPER_START 65
#define ASCII_ALPHABET_LOWER_START 97
#define NUM_OF_ALPHABETS 26

// Prototype

char Encrypt(int key_ascii, int char_ascii);

// Implementation

int main(int argc, string argv[])
{
    // Makes sure the user inputs correctly
    if (argc != 2)
    {
        printf("Please provide one keyword\n");
        return 1;
    }

    string keyword = argv[1];
    int keyword_length = strlen(keyword);
    int isAlphabet = TRUE;

    // Make sure the word is alphabetical
    for (int i = 0; i < keyword_length; i++)
        if (isalpha(keyword[i]) == FALSE)
        {
            isAlphabet = FALSE;
            break;
        }

    if (isAlphabet == false)
    {
        printf("The keyword can only contain alphabetic letters.");
        return 1;
    }

    // Prompt the user for the text to encrypt
    printf("What would you like to encrypt?\n");
    string text = GetString();

    int text_length = strlen(text);
    int keycount = 0;
    char encrypted[text_length];

    // Loop through every character and encrypt
    for (int i = 0; i < text_length; i++)
    {
        char current_char = text[i];

        // Encrypts the current character and sets it on the encrypted string
        if (isalpha(text[i]))
            encrypted[i] = Encrypt(keyword[keycount], current_char); 
        else
            encrypted[i] = current_char;
    
        // If there are no more keys left in our keyword, we reset back to
        // the first letter of the keyword to use
        if ((keycount + 1) >= keyword_length)
            keycount = 0;
        else
            keycount++;
    }

    printf("Encrypted: %s\n", encrypted);

    return 0;
}

/**
 * Encrypts an ASCII char into a new char using the given
 * encryption key
 */
char Encrypt(int key_ascii, int char_ascii)
{
    // Gets the ASCII number offsets
    int key_ascii_offset = isupper(key_ascii) ? ASCII_ALPHABET_UPPER_START : ASCII_ALPHABET_LOWER_START;
    int char_ascii_offset = isupper(char_ascii) ? ASCII_ALPHABET_UPPER_START : ASCII_ALPHABET_LOWER_START;

    // Gets the alphabet index of the `encryption key` and the `char to encrypt`
    int key_num = key_ascii - key_ascii_offset;
    int char_num = char_ascii - char_ascii_offset;

    int encrypted_char_num = (char_num + key_num) % NUM_OF_ALPHABETS;

    // Adds the ASCII offset back to the char after its been encrypted so we can have the proper
    // ASCII indexed character
    return (char) (char_ascii_offset + encrypted_char_num);
}
