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

char EncryptLowerCase(int key, int char_code);
char EncryptUpperCase(int key, int char_code);
int IsCapAlphabet(int char_code);
int IsLowerCaseAlphabet(int char_code);


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
        int char_code = (int) text[i];

        if (IsCapAlphabet(char_code))
            encrypted_text[i] = EncryptUpperCase(key, char_code);
        else if (IsLowerCaseAlphabet(char_code))
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
    int char_num = char_code - ASCII_ALPHABET_REG_MIN;
    int encrypted_char_num = (char_num + key) % NUM_OF_ALPHABETS;
    int encrypted_ascii_code = ASCII_ALPHABET_REG_MIN + encrypted_char_num;
    
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
    int char_num = char_code - ASCII_ALPHABET_CAP_MIN;
    int encrypted_char_num = (char_num + key) % NUM_OF_ALPHABETS;
    int encrypted_ascii_code = ASCII_ALPHABET_CAP_MIN + encrypted_char_num;
    
    return (char) encrypted_ascii_code;
}

/**
 * Checks if a given ascii code is a A-Z
 */
int IsCapAlphabet(int char_code)
{
    // if the character is a capitalized alphabet
    if (char_code >= ASCII_ALPHABET_CAP_MIN && char_code <= ASCII_ALPHABET_CAP_MAX)
        return TRUE;

    return FALSE;
}


/**
 * Checks if a given ascii code is a a-z
 */
int IsLowerCaseAlphabet(int char_code)
{
    // if the character is a lower cased alphabet
    if (char_code >= ASCII_ALPHABET_REG_MIN && char_code <= ASCII_ALPHABET_REG_MAX)
       return TRUE;
    
    return FALSE;
}
