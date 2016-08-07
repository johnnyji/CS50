#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants

#define NUM_OF_ALPHABETS 26
#define ASCII_ALPHABET_UPPER_MIN 65
#define ASCII_ALPHABET_LOWER_MIN 97

// Prototype

char EncryptLowerCase(int key, int char_code);
char EncryptUpperCase(int key, int char_code);

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
        char character = text[i];
        int char_code = (int) character;

        if (isupper(char_code))
            encrypted_text[i] = EncryptUpperCase(key, char_code);
        else if (islower(char_code))
            encrypted_text[i] = EncryptLowerCase(key, char_code);
        else
            encrypted_text[i] = text[i];
    }

    printf("Encrypt: %s\n", encrypted_text);
    return 0;
}

/**
 * Encrypts a lower case alphabet ASCII code using the Caesar Cipher encryption key
 */
char EncryptLowerCase(int key, int char_code)
{
    // Gets the regular char num (0-26) from its ASCII code,
    // then uses that number to encrypt the new char num, and
    // finally converts the newly converted char num back into ASCII
    int char_num = char_code - ASCII_ALPHABET_LOWER_MIN;
    int encrypted_char_num = (char_num + key) % NUM_OF_ALPHABETS;
    int encrypted_ascii_code = ASCII_ALPHABET_LOWER_MIN + encrypted_char_num;
    
    return (char) encrypted_ascii_code;
}

/**
 * Encrypts a upper case alphabet ASCII code using the Caesar Cipher encryption key
 */
char EncryptUpperCase(int key, int char_code)
{
    // Gets the regular char num (0-26) from its ASCII code,
    // then uses that number to encrypt the new char num, and
    // finally converts the newly converted char num back into ASCII
    int char_num = char_code - ASCII_ALPHABET_UPPER_MIN;
    int encrypted_char_num = (char_num + key) % NUM_OF_ALPHABETS;
    int encrypted_ascii_code = ASCII_ALPHABET_UPPER_MIN + encrypted_char_num;
    
    return (char) encrypted_ascii_code;
}
