#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_numeric(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    if (!is_numeric(argv[1]))
    {
        printf("The argument must be a positive integer\n");
        return 1;
    }
    int k = atoi(argv[1]);

    string plaintext = get_string("plaintext:  ");
    char ciphertext[strlen(plaintext) + 1];

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = 'A' + ((plaintext[i] - 'A' + k) % 26);
        }
        else if (islower(plaintext[i]))
        {
            ciphertext[i] = 'a' + ((plaintext[i] - 'a' + k) % 26);
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool is_numeric(string s)
{
    // Check if the string contains only digits
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false; // Return false if any character is not a digit
        }
    }
    return true; // All characters are digits, so it's a valid integer
}