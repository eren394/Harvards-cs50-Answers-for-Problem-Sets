#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_key(string s);

int main(int argc, string argv[])
{
    // 1. Validate that there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 2. Validate that the argument consists only of digits
    if (!is_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // 3. Convert the key string to an integer
    int k = atoi(argv[1]);

    // 4. Prompt the user for plaintext
    string p = get_string("plaintext:  ");

    // 5. Output the ciphertext
    printf("ciphertext: ");

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isupper(p[i]))
        {
            // (Letter index + key) % 26, then convert back to ASCII
            printf("%c", (p[i] - 'A' + k) % 26 + 'A');
        }
        else if (islower(p[i]))
        {
            // (Letter index + key) % 26, then convert back to ASCII
            printf("%c", (p[i] - 'a' + k) % 26 + 'a');
        }
        else
        {
            // Non-alphabetical characters remain unchanged
            printf("%c", p[i]);
        }
    }

    // Print a newline and exit
    printf("\n");
    return 0;
}

// Function to check if a string contains only decimal digits
bool is_valid_key(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
