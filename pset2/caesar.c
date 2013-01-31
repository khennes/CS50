#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // return an error if user inputs more than one argument
    if (argc != 2)
    {
        printf("An error has occurred. Please try again.");
        return 1;
    }
    // convert user's command-line argument from a string to an integer
    int k = atoi(argv[1]);
    while (k < 0)
    {
        printf("Enter a non-negative integer.");
        return 1;
    }
    // prompt user for plaintext string
    string p = GetString();
    
    // iterate over each character in the string
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // store ASCII value of each char in an array
        int ascii[strlen(p)]; 
        ascii[i] = (int) p[i];
        int var = ascii[i] + (k % 26);
        
        // test for capital letters
        if (isupper(ascii[i]) != 0)
        {
            if (var > 90)
                printf("%c", (char) var - 26);
            else
                printf("%c", (char) var);
        }
        // test for lowercase letters
        else if (islower(ascii[i]) != 0)
        {
            if (var > 122)
                printf("%c", (char) var - 26);
            else
                printf("%c", (char) var);
        } 
        // print all non-alphabet characters normally
        else
            printf("%c", (char) ascii[i]);
    }
    printf("\n");
    return 0;
}
