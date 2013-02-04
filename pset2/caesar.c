#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int var, k, i, n; 
    
    // return an error if user inputs more than one argument
    if (argc != 2)
    {
        printf("An error has occurred. Please try again.");
        return 1;
    }
    // convert user's command-line argument from a string to an integer
    k = atoi(argv[1]);

    // return an error if user inputs a negative integer
    while (k < 0)
    {
        printf("Enter a non-negative integer.");
        return 1;
    }
    // prompt user for plaintext string
    string p = GetString();
    
    // iterate over each character in the string
    for (i = 0, n = strlen(p); i < n; i++)
    {
        // store ASCII value of each char in an array
        int ascii[n]; 
        ascii[i] = (int) p[i];
        
        // test for capital letters
        if (isupper(ascii[i]) != 0)
            var = (ascii[i] - 65 + k) % 26 + 65;

        // test for lowercase letters
        else if (islower(ascii[i]) != 0)
            var = (ascii[i] - 97 + k) % 26 + 97;
        
        // return non-alphabet characters unchanged
        else
            var = ascii[i];

        // print the encrypted string
        printf("%c", (char) var);
    }
    printf("\n");
    return 0;
}
